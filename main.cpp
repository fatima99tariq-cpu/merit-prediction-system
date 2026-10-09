#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

// This class predicts merit on the basis of the list of previous merits of a department
class Merit_prediction {
private:
    float previous_merits[10];
    int size;
public:
    Merit_prediction(float merits[], int length) {
        size = length;
        for (int i = 0; i < size; ++i) {
            previous_merits[i] = merits[i];
        }
    }

    float calculate_AGR() {
        float first = previous_merits[0];
        float last = previous_merits[size - 1];
        float years = size - 1;
        if (first <= 0 || years <= 0)
        {
            return last;
        }
        float c_agr = pow((last / first), (1 / years)) - 1;
        return last * (1 + c_agr);
    }

    float predict_next_merit() {
        return calculate_AGR();
    }
};

class Department {
private:
    const char* name;
    float merits[10];
public:
    Department(const char* deptName, float data[]) {
        name = deptName;
        for (int i = 0; i < 10; i++) {
            merits[i] = data[i];
        }
    }

    const char* getName() const {
        return name;
    }

    float* getMerits() {
        return merits;
    }
};

void MeritPredictToFile(const string& department, float predictionMerit) {
    ofstream outFile("predicted_merit.txt", ios::app);
    outFile << fixed << setprecision(2);
    outFile << "Predicted Closing Merit for LCWU " << department << " (2025): " << predictionMerit << "%\n";
    outFile.close();
}

int main() {
    float csData[10] = {75.0, 76.3, 77.5, 78.6, 79.8, 80.9, 81.7, 82.4, 83.0, 83.55};
    float seData[10] = {83.0, 84.2, 85.3, 86.1, 87.0, 88.1, 89.3, 90.5, 91.7, 93.0};

    Department* departments[2];
    departments[0] = new Department("Computer Science", csData);
    departments[1] = new Department("Software Engineering", seData);

    char again;
    do {
        int choice;
        cout << "Enter department number (1-CS,2-SE):" << endl;
        cin >> choice;
        if (choice >= 1 && choice <= 2) {
            Department* selectedDept = departments[choice - 1];
            float* merits = selectedDept->getMerits();
            Merit_prediction predictor(merits, 10);
            float predicted = predictor.predict_next_merit();
            cout << fixed << setprecision(2);
            cout << "Predicted Closing Merit for LCWU " << selectedDept->getName()
                 << " (2025): " << predicted << "%\n";
            MeritPredictToFile(selectedDept->getName(), predicted);
        }
        else {
            cout << "Department Not Found." << endl;
        }
        cout << "Do you want to predict again? (y/n):\n";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    for (int i = 0; i < 2; ++i)
        delete departments[i];

    cout << "\nThank you for using the Merit Predictor!\n";
    return 0;
}

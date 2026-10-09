# Merit Prediction System Using CAGR in C++

A console-based C++ program that predicts the **next year's closing merit** for university departments (LCWU) using the last 10 years of merit data and the **Compound Annual Growth Rate (CAGR)** formula.

> Course project for **Object-Oriented Programming (CS-302)**, BS Computer Science, 2nd Semester (Session 2024-2028).

## Why this project?

Merit lists usually go up slightly every year, and many students are unsure whether they will qualify for a department. This tool looks at the past trend and gives a data-based estimate of the coming year's closing merit, so students can plan their admissions better. It can also help teachers, counselors and universities track merit growth.

## Features

- Department-wise prediction (Computer Science and Software Engineering)
- Uses 10 years of historical merit data
- CAGR-based forecasting
- Simple menu-driven console interface with "predict again" option
- Saves every prediction to `predicted_merit.txt`
- Clean OOP design (encapsulation, modularity, class-based design)

## How it works

CAGR measures the average yearly growth between the first and the last value:

```
CAGR = (last_merit / first_merit) ^ (1 / (years - 1)) - 1
Predicted merit = last_merit * (1 + CAGR)
```

Example for Computer Science: merit grew from 75.0% to 83.55% over 9 intervals, so the predicted merit for 2025 is **84.56%**.

## Project structure

```
merit-prediction-system/
├── src/
│   └── main.cpp              # Source code
├── docs/
│   ├── Project_Report.docx   # Full project report
│   └── Presentation.pptx     # Project presentation
├── sample_output/
│   └── predicted_merit.txt   # Example of the file the program creates
├── Makefile
├── .gitignore
└── README.md
```

## Class overview

| Class / Function | Purpose |
|---|---|
| `Department` | Stores the department name and its 10-year merit list (`getName()`, `getMerits()`) |
| `Merit_prediction` | Applies the CAGR formula and returns the predicted merit (`calculate_AGR()`, `predict_next_merit()`) |
| `MeritPredictToFile()` | Appends the predicted merit to `predicted_merit.txt` |

## Requirements

- A C++ compiler (GCC / g++ recommended), or an IDE such as Code::Blocks / Dev-C++

## Build and run

**Using g++ directly:**

```bash
g++ -o merit src/main.cpp
./merit            # on Windows: merit.exe
```

**Using make:**

```bash
make run
```

**Using Code::Blocks / Dev-C++:** open `src/main.cpp`, then Build and Run.

## Sample run

```
Enter department number (1-CS,2-SE):
1
Predicted Closing Merit for LCWU Computer Science (2025): 84.56%
Do you want to predict again? (y/n):
y
Enter department number (1-CS,2-SE):
2
Predicted Closing Merit for LCWU Software Engineering (2025): 94.18%
Do you want to predict again? (y/n):
n

Thank you for using the Merit Predictor!
```

## Future enhancements

- Graphical user interface
- Graphs/tables of merit trends
- Other prediction methods (moving average, linear regression)
- Database storage for department data
- Let users add or update department data without changing code
- Add more departments (e.g. Information Technology)

## Team (Group 8)

- Fatima Tariq
- Aliza Amir
- Umaima Bibi
- Dua Fatima

**Instructor:** Mariam Nosheen

## References

- LCWU sample merit data
- https://www.programiz.com/cpp-programming

CXX = g++
CXXFLAGS = -Wall -std=c++11

merit: src/main.cpp
	$(CXX) $(CXXFLAGS) -o merit src/main.cpp

run: merit
	./merit

clean:
	rm -f merit predicted_merit.txt

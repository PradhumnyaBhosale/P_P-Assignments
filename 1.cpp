#include <iostream>
#include <stdexcept>
using namespace std;
// Base class with virtual function for calculating average
class CalculateAverage {
protected:
    int numbers[5];

public:
    virtual void inputNumbers() {
        cout << "Enter 5 numbers: ";
        for (int i = 0; i < 5; ++i) {
            cin >> numbers[i];
        }
    }

    virtual double calculate() {
        double sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += numbers[i];
        }
        return sum / 5.0;
    }

    virtual ~CalculateAverage() {}
};

class CalculateAverageWithExceptionHandling : public CalculateAverage {
    friend void checkNumbers(const CalculateAverageWithExceptionHandling &obj);

public:
    void inputNumbers() override {
        cout << "Enter 5 numbers (within the range of -100 to 100): ";
        for (int i = 0; i < 5; ++i) {
            cin >> numbers[i];
        }
    }
};

// Friend function to check if the numbers are within a specified range
void checkNumbers(const CalculateAverageWithExceptionHandling &obj) {
    for (int i = 0; i < 5; ++i) {
        if (obj.numbers[i] < -100 || obj.numbers[i] > 100) {
            throw out_of_range("Number out of range! Please enter numbers between -100 and 100.");
        }
    }
}

int main() {
    try {
        CalculateAverageWithExceptionHandling obj;
        obj.inputNumbers();

        checkNumbers(obj);

        double average = obj.calculate();
        cout << "Average of the 5 numbers is: " << average << endl;
    }
    catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

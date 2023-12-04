#include <iostream>
#include <stdexcept>
using  namespace std;
// Base class with virtual functions for exam result analysis
class ExamResultAnalyzer {
protected:
    int passedCount;
    int failedCount;

public:
    ExamResultAnalyzer() : passedCount(0), failedCount(0) {}

    virtual void inputResults() {
        for (int i = 0; i < 10; ++i) {
            int result;
            cout << "Enter result for student " << (i + 1) << " (1 for pass, 2 for fail): ";
            cin >> result;

            if (result == 1)
                passedCount++;
            else if (result == 2)
                failedCount++;
            else
                throw invalid_argument("Invalid input! Enter 1 for pass or 2 for fail.");
        }
    }

    virtual void displaySummary() {
        cout << "Number of students who passed: " << passedCount << endl;
        cout << "Number of students who failed: " << failedCount << endl;

        if (passedCount > 8)
            cout << "Raise tuition." << endl;
    }

    virtual ~ExamResultAnalyzer() {}
};

int main() {
    try {
        ExamResultAnalyzer obj;
        obj.inputResults();
        obj.displaySummary();
    }
    catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

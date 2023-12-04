#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
// User-defined exception for age validation
class AgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Age should be between 18 and 55.";
    }
};

// User-defined exception for income validation
class IncomeException : public exception {
public:
    const char* what() const noexcept override {
        return "Income should be between Rs. 50,000 and Rs. 1,00,000 per month.";
    }
};

// User-defined exception for city validation
class CityException : public exception {
public:
    const char* what() const noexcept override {
        return "User should stay in Pune, Mumbai, Bangalore, or Chennai.";
    }
};

// User-defined exception for vehicle validation
class VehicleException : public exception {
public:
    const char* what() const noexcept override {
        return "User should have a 4-wheeler vehicle.";
    }
};

// Class to handle user information and perform validation
class UserInformation {
private:
    int age;
    double income;
    string city;
    bool hasFourWheeler;

public:
    void inputDetails() {
        cout << "Enter age: ";
        cin >> age;

        cout << "Enter income: ";
        cin >> income;

        cout << "Enter city: ";
        cin >> city;

        cout << "Does the user have a 4-wheeler (1 for Yes, 0 for No): ";
        cin >> hasFourWheeler;
    }

    void validate() {
        if (age < 18 || age > 55) {
            throw AgeException();
        }

        if (income < 50000 || income > 100000) {
            throw IncomeException();
        }

        if (city != "Pune" && city != "Mumbai" && city != "Bangalore" && city != "Chennai") {
            throw CityException();
        }

        if (!hasFourWheeler) {
            throw VehicleException();
        }
    }
};

int main() {
    try {
        UserInformation user;
        user.inputDetails();
        user.validate();

        cout << "User information validated successfully." << endl;
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

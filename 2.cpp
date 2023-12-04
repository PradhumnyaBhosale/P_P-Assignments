#include <iostream>
#include <cmath>
#include <stdexcept>

// Base class with virtual function for power calculation
class PowerCalculator {
public:
    virtual double power(double n, int p = 2) {
        return std::pow(n, p);
    }

    virtual ~PowerCalculator() {}
};

// Derived class with friend function for exception handling
class PowerCalculatorWithExceptionHandling : public PowerCalculator {
    friend void checkExponent(int exp);

public:
    double power(double n, int p = 2) override {
        if (p < 0) {
            throw std::invalid_argument("Exponent must be a non-negative integer!");
        }
        return std::pow(n, p);
    }
};

// Friend function to check if the exponent is a non-negative integer
void checkExponent(int exp) {
    if (exp < 0) {
        throw std::invalid_argument("Exponent must be a non-negative integer!");
    }
}

int main() {
    try {
        PowerCalculatorWithExceptionHandling obj;
        double base;
        int exponent;

        std::cout << "Enter the base number: ";
        std::cin >> base;

        std::cout << "Enter the exponent (default is 2 if omitted): ";
        std::cin >> exponent;

        checkExponent(exponent);

        double result = obj.power(base, exponent);

        std::cout << base << " raised to the power " << exponent << " is: " << result << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

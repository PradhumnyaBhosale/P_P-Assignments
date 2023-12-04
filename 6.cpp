#include <iostream>
#include <stdexcept>
using namespace std;
class ClassB; // Forward declaration of ClassB

// Base class with virtual function for swapping data
class SwapData {
public:
    virtual void swapPrivateData(ClassB &objB) = 0; // Virtual function for swapping data
    virtual ~SwapData() {}
};

// ClassA with private data member 'dataA'
class ClassA : public SwapData {
private:
    int dataA;

public:
    ClassA(int val) : dataA(val) {}

    friend void swapPrivateData(ClassA &objA, ClassB &objB); // Friend function declaration

    void display() {
        cout << "ClassA: DataA = " << dataA << endl;
    }

    void swapPrivateData(ClassB &objB) override; // Override virtual function
};

// ClassB with private data member 'dataB'
class ClassB : public SwapData {
private:
    int dataB;

public:
    ClassB(int val) : dataB(val) {}

    friend void swapPrivateData(ClassA &objA, ClassB &objB); // Friend function declaration

    void display() {
        cout << "ClassB: DataB = " << dataB << endl;
    }

    void swapPrivateData(ClassA &objA) override; // Override virtual function
};

// Friend function definition for swapping data of ClassA and ClassB
void swapPrivateData(ClassA &objA, ClassB &objB) {
    int temp = objA.dataA;
    objA.dataA = objB.dataB;
    objB.dataB = temp;
}

// Implementation of swapPrivateData function in ClassA
void ClassA::swapPrivateData(ClassB &objB) {
    swapPrivateData(*this, objB); // Invoking friend function for swapping
}

// Implementation of swapPrivateData function in ClassB
void ClassB::swapPrivateData(ClassA &objA) {
    swapPrivateData(objA, *this); // Invoking friend function for swapping
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    cout << "Before swapping:" << endl;
    objA.display();
    objB.display();

    objA.swapPrivateData(objB); // Swapping data

    cout << "\nAfter swapping:" << endl;
    objA.display();
    objB.display();

    return 0;
}

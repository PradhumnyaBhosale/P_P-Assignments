#include <iostream>
#include <stdexcept>
using namespace std;
// Base class with virtual function for volume calculation
class VolumeCalculator {
public:
    virtual double calculateVolume() const {
        return 0.0;
    }

    virtual ~VolumeCalculator() {}
};

// Derived class for calculating volume of a cylinder
class Cylinder : public VolumeCalculator {
private:
    double radius;
    double height;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double calculateVolume() const override {
        return 3.14159 * radius * radius * height;
    }
};

// Derived class for calculating volume of a cube
class Cube : public VolumeCalculator {
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double calculateVolume() const override {
        return side * side * side;
    }
};

// Derived class for calculating volume of a cuboid
class Cuboid : public VolumeCalculator {
private:
    double length;
    double width;
    double height;

public:
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

    double calculateVolume() const override {
        return length * width * height;
    }
};

int main() {
    try {
        Cylinder cylinder(3.0, 4.0);
        Cube cube(5.0);
        Cuboid cuboid(2.0, 3.0, 4.0);

        cout << "Volume of Cylinder: " << cylinder.calculateVolume() << endl;
        cout << "Volume of Cube: " << cube.calculateVolume() << endl;
        cout << "Volume of Cuboid: " << cuboid.calculateVolume() << endl;
    }
    catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include <cmath>

const double PI = 3.14159265358979323846;

class RightTriangle {
private:
    double side;
    double angle;

public:
    RightTriangle();
    RightTriangle(double side, double angle);

    bool setProperties(double side, double angle);
    bool isValid() const;
    static bool isValid(double side, double angle);

    bool resizeSide(double percentage);
    double calculateInradius() const;
    double calculateDistanceCenters() const;
    double calculateSquareRootOfArea() const;
    void getSides(double& a, double& b) const;

    void printInfo() const;
};

#endif
#include "RightTriangle.h"
#include <iostream>
#include <limits>

using namespace std;

// ����������� �� ���������
RightTriangle::RightTriangle() : side(0), angle(0) {}

// ����������� � �����������
RightTriangle::RightTriangle(double side, double angle) : side(side), angle(angle) {
    if (!isValid()) {
        cout << "������: ������������ �������� ��� �������������� ������������." << endl;
    }
}

// ����� ��������� �������
bool RightTriangle::setProperties(double side, double angle) {
    if (!isValid(side, angle)) {
        cout << "������: ������������ �������� ��� �������������� ������������." << endl;
        return false;
    }
    this->side = side;
    this->angle = angle;
    return true;
}

// ����� �������� ������������ �������
bool RightTriangle::isValid() const {
    return isValid(side, angle);
}

// ����� �������� ������������ ������� (�����������)
bool RightTriangle::isValid(double side, double angle) {
    if (side <= 0 || angle <= 0 || angle >= 90) {
        return false;
    }
    return true;
}

// ����� ��������� ������� �������
bool RightTriangle::resizeSide(double percentage) {
    if (percentage < 0) {
        cout << "������: ������������ ������� ��������� �������." << endl;
        return false;
    }
    side *= (1 + percentage / 100);
    return true;
}

// ����� ���������� ������� ��������� ����������
double RightTriangle::calculateInradius() const {
    return side * sin(angle * PI / 180) / 2;
}

// ����� ����������� ���������� ����� �������� ��������� � ��������� �����������
double RightTriangle::calculateDistanceCenters() const {
    double hypotenuse = side / sin(angle * PI / 180);
    return hypotenuse / 2 - calculateInradius();
}

// ����� ���������� ����������� ����� �� �������
double RightTriangle::calculateSquareRootOfArea() const {
    double area = side * side * sin(angle * PI / 180) / 2;
    return sqrt(area);
}

// ����� ����������� �������� ������
void RightTriangle::getSides(double& a, double& b) const {
    a = side * sin(angle * PI / 180);
    b = side * cos(angle * PI / 180);
}

// ����� ������ ���������� � ������������
void RightTriangle::printInfo() const {
    cout << "�������: " << side << endl;
    cout << "����: " << angle << endl;
    cout << "������ ��������� ����������: " << calculateInradius() << endl;
    cout << "���������� ����� �������� ��������� � ��������� �����������: "
        << calculateDistanceCenters() << endl;
    cout << "���������� ������ �� �������: " << calculateSquareRootOfArea() << endl;
    double a, b;
    getSides(a, b);
    cout << "�������: " << a << ", " << b << endl;
    cout << endl;
}
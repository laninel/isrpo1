#include "RightTriangle.h"
#include <iostream>
#include <limits>

using namespace std;

// Конструктор по умолчанию
RightTriangle::RightTriangle() : side(0), angle(0) {}

// Конструктор с параметрами
RightTriangle::RightTriangle(double side, double angle) : side(side), angle(angle) {
    if (!isValid()) {
        cout << "Ошибка: Недопустимые значения для прямоугольного треугольника." << endl;
    }
}

// Метод установки свойств
bool RightTriangle::setProperties(double side, double angle) {
    if (!isValid(side, angle)) {
        cout << "Ошибка: Недопустимые значения для прямоугольного треугольника." << endl;
        return false;
    }
    this->side = side;
    this->angle = angle;
    return true;
}

// Метод проверки допустимости свойств
bool RightTriangle::isValid() const {
    return isValid(side, angle);
}

// Метод проверки допустимости свойств (статический)
bool RightTriangle::isValid(double side, double angle) {
    if (side <= 0 || angle <= 0 || angle >= 90) {
        return false;
    }
    return true;
}

// Метод изменения размера стороны
bool RightTriangle::resizeSide(double percentage) {
    if (percentage < 0) {
        cout << "Ошибка: Недопустимый процент изменения размера." << endl;
        return false;
    }
    side *= (1 + percentage / 100);
    return true;
}

// Метод вычисления радиуса вписанной окружности
double RightTriangle::calculateInradius() const {
    return side * sin(angle * PI / 180) / 2;
}

// Метод определения расстояния между центрами вписанной и описанной окружностей
double RightTriangle::calculateDistanceCenters() const {
    double hypotenuse = side / sin(angle * PI / 180);
    return hypotenuse / 2 - calculateInradius();
}

// Метод вычисления квадратного корня из площади
double RightTriangle::calculateSquareRootOfArea() const {
    double area = side * side * sin(angle * PI / 180) / 2;
    return sqrt(area);
}

// Метод определения значений сторон
void RightTriangle::getSides(double& a, double& b) const {
    a = side * sin(angle * PI / 180);
    b = side * cos(angle * PI / 180);
}

// Метод вывода информации о треугольнике
void RightTriangle::printInfo() const {
    cout << "Сторона: " << side << endl;
    cout << "Угол: " << angle << endl;
    cout << "Радиус вписанной окружности: " << calculateInradius() << endl;
    cout << "Расстояние между центрами вписанной и описанной окружностей: "
        << calculateDistanceCenters() << endl;
    cout << "Квадратный корень из площади: " << calculateSquareRootOfArea() << endl;
    double a, b;
    getSides(a, b);
    cout << "Стороны: " << a << ", " << b << endl;
    cout << endl;
}
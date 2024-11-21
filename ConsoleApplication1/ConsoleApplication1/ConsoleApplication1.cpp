#include <iostream>
#include <limits>
#include "RightTriangle.h" // Включите заголовочный файл

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество прямоугольных треугольников: ";
    cin >> n;

    // Проверка корректности ввода
    if (n <= 0) {
        cout << "Ошибка: Количество треугольников должно быть положительным." << endl;
        return 1;
    }

    // Создание массива треугольников
    RightTriangle* triangles = new RightTriangle[n];

    // Ввод данных о треугольниках
    for (int i = 0; i < n; i++) {
        double side, angle;
        cout << "Введите сторону и угол " << i + 1 << "-го треугольника: ";
        cin >> side >> angle;
        triangles[i].setProperties(side, angle);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
    }

    // Основной цикл
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Изменить размер стороны треугольника" << endl;
        cout << "2. Вычислить радиус вписанной окружности" << endl;
        cout << "3. Определить расстояние между центрами вписанной и описанной окружностей" << endl;
        cout << "4. Вычислить квадратный корень из площади" << endl;
        cout << "5. Определить значения сторон" << endl;
        cout << "6. Вывести информацию о треугольнике" << endl;
        cout << "7. Выход" << endl;
        cout << "Введите номер действия: ";

        int choice;
        cin >> choice;

        // Проверка корректности ввода
        if (choice < 1 || choice > 7) {
            cout << "Ошибка: Неверный номер действия." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            continue;
        }

        if (choice == 7) {
            break;
        }

        // Выбор действия
        cout << "Выберите номер треугольника (от 1 до " << n << "): ";
        int triangleIndex;
        cin >> triangleIndex;

        // Проверка корректности ввода
        if (triangleIndex < 1 || triangleIndex > n) {
            cout << "Ошибка: Неверный номер треугольника." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            continue;
        }

        triangleIndex--;

        switch (choice) {
        case 1: {
            double percentage;
            cout << "Введите процент изменения размера стороны: ";
            cin >> percentage;
            if (!triangles[triangleIndex].resizeSide(percentage)) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
                break;
            }
            cout << "Размер стороны успешно изменен." << endl;
            break;
        }
        case 2:
            cout << "Радиус вписанной окружности: " << triangles[triangleIndex].calculateInradius() << endl;
            break;
        case 3:
            cout << "Расстояние между центрами вписанной и описанной окружностей: "
                << triangles[triangleIndex].calculateDistanceCenters() << endl;
            break;
        case 4:
            cout << "Квадратный корень из площади: " << triangles[triangleIndex].calculateSquareRootOfArea() << endl;
            break;
        case 5: {
            double a, b;
            triangles[triangleIndex].getSides(a, b);
            cout << "Стороны: " << a << ", " << b << endl;
            break;
        }
        case 6:
            triangles[triangleIndex].printInfo();
            break;
        }
    }

    // Удаление динамического массива
    delete[] triangles;

    return 0;
}
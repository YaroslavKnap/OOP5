#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

// Абстрактний клас геометричне тіло
class GeometricShape {
public:
    // Віртуальний метод для обчислення площі поверхні
    virtual double calculateSurfaceArea() const = 0;

    // Віртуальний метод для обчислення об'єму
    virtual double calculateVolume() const = 0;
};

// Похідний клас Піраміда
class Pyramid : public GeometricShape {
private:
    double baseArea; // Площа основи піраміди
    double height;   // Висота піраміди

public:
    // Конструктор
    Pyramid(double baseArea, double height) : baseArea(baseArea), height(height) {}

    // Реалізація віртуального методу для обчислення площі поверхні піраміди
    double calculateSurfaceArea() const override {
        // Формула для обчислення площі поверхні піраміди
        return baseArea + 0.5 * baseArea * sqrt(4 * pow(height, 2) + pow(baseArea, 2));
    }

    // Реалізація віртуального методу для обчислення об'єму піраміди
    double calculateVolume() const override {
        // Формула для обчислення об'єму піраміди
        return (1.0 / 3.0) * baseArea * height;
    }
};

// Похідний клас Куля
class Sphere : public GeometricShape {
private:
    double radius; // Радіус кулі

public:
    // Конструктор
    Sphere(double radius) : radius(radius) {}

    // Реалізація віртуального методу для обчислення площі поверхні кулі
    double calculateSurfaceArea() const override {
        // Формула для обчислення площі поверхні кулі
        return 4.0 * PI * pow(radius, 2);
    }

    // Реалізація віртуального методу для обчислення об'єму кулі
    double calculateVolume() const override {
        // Формула для обчислення об'єму кулі
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");
    // Приклад використання класів
    Pyramid pyramid(10.0, 5.0);
    Sphere sphere(7.0);

    std::cout << "Площа поверхнi пірамiди: " << pyramid.calculateSurfaceArea() << std::endl;
    std::cout << "Обсяг пiрамiди: " << pyramid.calculateVolume() << std::endl;

    std::cout << "Площа поверхнi сфери: " << sphere.calculateSurfaceArea() << std::endl;
    std::cout << "Обсяг кулi: " << sphere.calculateVolume() << std::endl;

    return 0;
}

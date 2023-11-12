#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

// ����������� ���� ����������� ���
class GeometricShape {
public:
    // ³��������� ����� ��� ���������� ����� �������
    virtual double calculateSurfaceArea() const = 0;

    // ³��������� ����� ��� ���������� ��'���
    virtual double calculateVolume() const = 0;
};

// �������� ���� ϳ�����
class Pyramid : public GeometricShape {
private:
    double baseArea; // ����� ������ ������
    double height;   // ������ ������

public:
    // �����������
    Pyramid(double baseArea, double height) : baseArea(baseArea), height(height) {}

    // ��������� ����������� ������ ��� ���������� ����� ������� ������
    double calculateSurfaceArea() const override {
        // ������� ��� ���������� ����� ������� ������
        return baseArea + 0.5 * baseArea * sqrt(4 * pow(height, 2) + pow(baseArea, 2));
    }

    // ��������� ����������� ������ ��� ���������� ��'��� ������
    double calculateVolume() const override {
        // ������� ��� ���������� ��'��� ������
        return (1.0 / 3.0) * baseArea * height;
    }
};

// �������� ���� ����
class Sphere : public GeometricShape {
private:
    double radius; // ����� ���

public:
    // �����������
    Sphere(double radius) : radius(radius) {}

    // ��������� ����������� ������ ��� ���������� ����� ������� ���
    double calculateSurfaceArea() const override {
        // ������� ��� ���������� ����� ������� ���
        return 4.0 * PI * pow(radius, 2);
    }

    // ��������� ����������� ������ ��� ���������� ��'��� ���
    double calculateVolume() const override {
        // ������� ��� ���������� ��'��� ���
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");
    // ������� ������������ �����
    Pyramid pyramid(10.0, 5.0);
    Sphere sphere(7.0);

    std::cout << "����� �������i ����i��: " << pyramid.calculateSurfaceArea() << std::endl;
    std::cout << "����� �i���i��: " << pyramid.calculateVolume() << std::endl;

    std::cout << "����� �������i �����: " << sphere.calculateSurfaceArea() << std::endl;
    std::cout << "����� ���i: " << sphere.calculateVolume() << std::endl;

    return 0;
}

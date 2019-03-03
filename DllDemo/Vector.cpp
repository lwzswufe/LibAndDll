#include "stdafx.h"
#include "Vector.h"

Vector::~Vector()
{
}

Vector::Vector(double v1, double v2)
{   
    this->x = v1;
    this->y = v2;
}

string Vector::get_string()
{
    string str;
    double len = this->get_len();
    char char_arr[256];
    sprintf_s(char_arr, "x: %.4lf \ty: %.4lf \t len: %.4lf", x, y, len);
    str = char_arr;
    return str;
}

double Vector::get_x()
{
    return this->x;
}

double Vector::get_y()
{
    return this->y;
}

void Vector::show()                      // 使用内联函数定义类方法
{
    cout << this->get_string() << endl;
}

double Vector::get_len()
{
    return sqrt(x * x + y * y);
}

Vector operator+(Vector& lhs, Vector& rhs)
{
    return Vector(lhs.get_x() + rhs.get_x(), lhs.get_y() + rhs.get_y());
}

double operator*(Vector& lhs, Vector& rhs)
{
    return (lhs.get_x() * rhs.get_x() + lhs.get_y() * rhs.get_y());
}

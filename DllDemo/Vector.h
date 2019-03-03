#pragma once
class DEMO_API Vector
{
public:
    Vector() :Vector(0, 0) {};
    ~Vector();
    Vector(double v1, double v2);
    Vector(double v1) :Vector(v1, v1) {};
    double get_x();
    double get_y();
    double get_len();
    void show();
    string get_string();

private:
    double x;
    double y;
    double len;
    const int dim{ 2 };
};

Vector DEMO_API operator+(Vector& lhs, Vector& rhs);

double DEMO_API operator*(Vector& lhs, Vector& rhs);

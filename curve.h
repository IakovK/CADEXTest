#pragma once

struct point3D
{
    double x;
    double y;
    double z;
};

struct vector3D
{
    double x;
    double y;
    double z;
};

class curve
{
public:
    virtual point3D Point(double t) = 0;
    virtual vector3D Derivative(double t) = 0;
    virtual double Radius() = 0;
};

class circle : public curve
{
    double radius;
public:
    circle(double r);
    virtual double Radius();
    virtual point3D Point(double t);
    virtual vector3D Derivative(double t);
};

class ellipse : public curve
{
    double radiusX, radiusY;
public:
    ellipse(double a, double b);
    virtual double Radius();
    virtual point3D Point(double t);
    virtual vector3D Derivative(double t);
};

class helix : public curve
{
    double radius, step;
public:
    helix(double r, double s);
    virtual double Radius();
    virtual point3D Point(double t);
    virtual vector3D Derivative(double t);
};

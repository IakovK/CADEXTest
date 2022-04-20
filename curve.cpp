#include "curve.h"
#include <cmath>
#include <stdexcept>

circle::circle(double r)
    : radius(r)
{
    if (r <= 0)
        throw std::invalid_argument("radius must be positive");
}

double circle::Radius()
{
    return radius;
}

point3D circle::Point(double t)
{
    return { radius * std::cos(t), radius * std::sin(t), 0.0 };
}

vector3D circle::Derivative(double t)
{
    return { -radius * std::sin(t), radius * std::cos(t), 0.0 };
}

ellipse::ellipse(double a, double b)
    : radiusX(a)
    , radiusY(b)
{
    if (a <= 0 || b <= 0)
        throw std::invalid_argument("axes must be positive");
}

double ellipse::Radius()
{
    return radiusX;
}

point3D ellipse::Point(double t)
{
    return { radiusX * std::cos(t), radiusY * std::sin(t), 0.0 };
}

vector3D ellipse::Derivative(double t)
{
    return { -radiusX * std::sin(t), radiusY * std::cos(t), 0.0 };
}

helix::helix(double r, double s)
    : radius(r)
    , step(s)
{
    if (r <= 0)
        throw std::invalid_argument("radius must be positive");
}

double helix::Radius()
{
    return radius;
}

double PI2 = std::asin(1.) * 4.;    // 2 * PI
point3D helix::Point(double t)
{
    return { radius * std::cos(t), radius * std::sin(t), step * t / PI2 };
}

vector3D helix::Derivative(double t)
{
    return { -radius * std::sin(t), radius * std::cos(t), step / PI2 };
}

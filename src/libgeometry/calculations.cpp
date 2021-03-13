#include <cmath>
#include <libgeometry/calculations.h>
const double PI = 3.14159;
float CirclePerimeter(float radius)
{
    float per = 2 * PI * radius;
    return per;
}
float CircleArea(float radius)
{
    float area = PI * radius * radius;
    return area;
}
float TrianglePerimeter(float a, float b, float c)
{
    float res = a + b + c;
    return res;
}
float TriangleArea(float a, float b, float c)
{
    float halfper = TrianglePerimeter(a, b, c) / 2;
    float res
            = sqrt(halfper * (halfper - a) * (halfper - b)
                   * (halfper - c)); // Geron formula
    return res;
}

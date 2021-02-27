#include "functions.h"
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

#include <iostream>
#include <libgeometry/calculations.h>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
void Circle(char* input, float& perimeter, float& area)
{
    int left_par, right_par, comma;
    Search(input, left_par, right_par, comma);
    char data[80];
    char rad[10];
    int j = 0;
    for (int i = left_par + 1; i < right_par; i++) {
        data[j] = input[i];
        j++;
    }
    j = 0;
    for (int i = comma + 1; i < right_par; i++) {
        rad[j] = input[i];
        j++;
    }
    int x, y;
    float radius;
    sscanf(data, " %d %d", &x, &y);
    radius = atof(rad);
    perimeter = CirclePerimeter(radius);
    area = CircleArea(radius);
}

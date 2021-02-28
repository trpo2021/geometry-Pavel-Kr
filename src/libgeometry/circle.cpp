#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
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
void Circle(char* input)
{
    string inp;
    inp.assign(input);
    int left_par = inp.find('(');
    int right_par = inp.find(')', left_par);
    int comma = inp.find(',', left_par);
    char data[80];
    char rad[10];
    int j = 0;
    for (int i = left_par + 1; i < right_par; i++) {
        data[j] = inp[i];
        j++;
    }
    j = 0;
    for (int i = comma + 1; i < right_par; i++) {
        rad[j] = inp[i];
        j++;
    }
    int x, y;
    float radius;
    sscanf(data, " %d %d", &x, &y);
    radius = atof(rad);
    printf("x= %d\ny= %d\nradius= %f", x, y, radius);
    float perimeter = CirclePerimeter(radius);
    float area = CircleArea(radius);
    cout << endl << "Perimeter= " << perimeter << endl << "Area= " << area;
}

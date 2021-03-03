#include <cmath>
#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
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
void Triangle(char* input)
{
    string inp;
    inp.assign(input);
    int left_par = inp.find('(');
    int right_par = inp.find(')', left_par);
    char data[4][10];
    int comma[3];
    comma[0] = inp.find(',');
    for (int i = 1; i < 3; i++) {
        comma[i] = inp.find(',', comma[i - 1] + 1);
    }
    int x[4] = {0, 0, 0, 0};
    int y[4] = {0, 0, 0, 0};
    int j, k = 0;
    for (j = left_par + 1; j < comma[0]; j++) {
        data[0][k] = inp[j];
        k++;
    }
    for (int i = 0; i < 2; i++) {
        k = 0;
        for (j = comma[i] + 1; j < comma[i + 1]; j++) {
            data[i + 1][k] = inp[j];
            k++;
        }
    }
    k = 0;
    for (j = comma[2] + 1; j < right_par; j++) {
        data[3][k] = inp[j];
        k++;
    }
    for (int i = 0; i < 4; i++) {
        sscanf(data[i], "%d %d", &x[i], &y[i]);
    }
    if (x[0] != x[3] || y[0] != y[3]) {
        cout << "Error: not a triangle" << endl;
        return;
    }
    float a = sqrt(
            (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
    float b = sqrt(
            (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));
    float c = sqrt(
            (x[3] - x[2]) * (x[3] - x[2]) + (y[3] - y[2]) * (y[3] - y[2]));
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Error: not a triangle" << endl;
        return;
    }
    float per = TrianglePerimeter(a, b, c);
    float area = TriangleArea(a, b, c);
    cout << "Perimeter: " << per << endl << "Area: " << area << endl;
}

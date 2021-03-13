#include <iostream>
#include <libgeometry/calculations.h>
#include <libgeometry/functions.h>
#include <string>
#include <cmath>
using namespace std;
int Triangle(char* input,float &per, float &area)
{
    int left_par, right_par;
    int comma[3];
    Search(input, left_par, right_par, comma);
    char data[4][10];
    int x[4];
    int y[4];
    int j, k = 0;
    for (j = left_par + 1; j < comma[0]; j++) {
        data[0][k] = input[j];
        k++;
    }
    for (int i = 0; i < 2; i++) {
        k = 0;
        for (j = comma[i] + 1; j < comma[i + 1]; j++) {
            data[i + 1][k] = input[j];
            k++;
        }
    }
    k = 0;
    for (j = comma[2] + 1; j < right_par; j++) {
        data[3][k] = input[j];
        k++;
    }
    for (int i = 0; i < 4; i++) {
        sscanf(data[i], "%d %d", &x[i], &y[i]);
    }
    if (x[0] != x[3] || y[0] != y[3]) {
        cout << "Error: not a triangle" << endl;
        return -1;
    }
    float a = sqrt(
            (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]));
    float b = sqrt(
            (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]));
    float c = sqrt(
            (x[3] - x[2]) * (x[3] - x[2]) + (y[3] - y[2]) * (y[3] - y[2]));
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Error: not a triangle" << endl;
        return -1;
    }
    per = TrianglePerimeter(a, b, c);
    area = TriangleArea(a, b, c);
    return 0;
}

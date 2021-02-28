#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
int main()
{
    char input[80];
    for (int i = 0; i < 80; i++) {
        input[i] = ' ';
    }
    cin.getline(input, 80);
    int CorT = CircleOrTriangle(input); // 0 for circle,1 for triangle, -1 error
    bool is_circle = false;
    bool is_triangle = false;
    if (CorT == 0) {
        is_circle = CircleCheck(input);
    }
    if (CorT == 1) {
        is_triangle = TriangleCheck(input);
    }
    if (is_circle) {
        Circle(input);
    } else if (is_triangle) {
        Triangle(input);
    }
    return 0;
}

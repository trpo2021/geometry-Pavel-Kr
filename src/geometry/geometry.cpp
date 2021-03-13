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
    int is_circle;
    int is_triangle;
    if (CorT == 0) {
        is_circle = CircleCheck(input);
        if (is_circle != 0)
            PrintError(is_circle);
    } else if (CorT == 1) {
        is_triangle = TriangleCheck(input);
        if (is_triangle != 0)
            PrintError(is_triangle);
    } else {
        cout << "Error:expected circle or triangle" << endl;
    }
    if (is_circle == 0) {
        float perimeter, area;
        Circle(input, perimeter, area);
        cout << endl << "Perimeter= " << perimeter << endl << "Area= " << area;
    } else if (is_triangle == 0) {
        float perimeter, area;
        int err;
        err = Triangle(input, perimeter, area);
        if (err == 1)
            cout << "Error: not a triangle" << endl;
        else {
            cout << endl
                 << "Perimeter= " << perimeter << endl
                 << "Area= " << area;
        }
    }
    return 0;
}

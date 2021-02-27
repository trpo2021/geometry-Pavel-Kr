#include "functions.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char input[80];
    for (int i = 0; i < 80; i++) {
        input[i] = ' ';
    }
    cin.getline(input, 80);
    string inp;
    inp.assign(input);
    int left_par = inp.find('(');
    int right_par = inp.find(')', left_par);
    int comma = inp.find(',', left_par);
    bool IsDataTrue = CircleCheck(input);
    if (IsDataTrue) {
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
    return 0;
}

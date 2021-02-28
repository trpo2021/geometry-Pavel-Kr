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
    string inp;
    inp.assign(input);
    int CoT = CircleOrTriangle(
            input); // 0 for circle,1 for triangle, -1 error
    bool is_circle = false;
    bool is_triangle = false;
    if (CoT == 0) {
        is_circle = CircleCheck(input);
    }
    if (CoT == 1) {
        is_triangle = TriangleCheck(input);
    }
    if (is_circle) {
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
    else if(is_triangle){
    	cout<<"triangle";
    }
    return 0;
}

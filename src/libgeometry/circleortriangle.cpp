#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
int CircleOrTriangle(char* input)
{
    string inp;
    inp.assign(input);
    int left_par = inp.find('(');
    int first_space = inp.find(' ');
    int circle_true = inp.compare(0, first_space, "circle")
            * inp.compare(0, left_par, "circle")
            * inp.compare(0, first_space, "CIRCLE")
            * inp.compare(0, left_par, "CIRCLE");
    int triangle_true = inp.compare(0, first_space, "triangle")
            * inp.compare(0, left_par, "triangle")
            * inp.compare(0, first_space, "TRIANGLE")
            * inp.compare(0, left_par, "TRIANGLE");
    if (circle_true == 0)
        return 0;
    if (triangle_true == 0)
        return 1;
    else
        return -1;
}

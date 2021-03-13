#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
int CircleCheck(char* input)
{
    int left_par, right_par, comma;
    Search(input, left_par, right_par, comma);
    if (left_par == -1 || right_par == -1)
        return 1;
    if (comma == -1)
        return 2;
    bool IsNumber = false;
    int lcount = 0; // must be 2
    int rcount = 0; // must be 1
    for (int i = left_par + 1; i <= comma; i++) {
        if ((input[i] == ' ' || input[i] == ',') && IsNumber) {
            lcount++;
            IsNumber = false;
        }
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == ',') {
            IsNumber = true;
        } else if (input[i] == ' ')
            continue;
        else
            return 3;
    }
    IsNumber = false;
    bool IsFloat = false;
    for (int i = comma + 1; i <= right_par; i++) {
        if ((input[i] == ' ' || input[i] == ')') && IsNumber) {
            rcount++;
            IsNumber = false;
        }
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == ')')
            IsNumber = true;
        else if (input[i] == '.' && IsNumber && IsFloat)
            return 4;
        else if (input[i] == '.' && IsNumber && IsFloat == false) {
            IsFloat = true;
        } else if (input[i] == ' ')
            continue;
        else
            return 3;
    }
    if (lcount != 2 || rcount != 1)
        return 5;
    for (int i = right_par + 2; i < 80; i++) {
        if (input[i] != ' ')
            return 6;
    }
    return 0;
}

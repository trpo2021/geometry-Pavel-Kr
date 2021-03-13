#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
int CircleCheck(char* input)
{
    int left_par, right_par, comma;
    Search(input, left_par, right_par, comma);
    bool IsDataTrue = true;
    if (left_par == -1 || right_par == -1) {
        cout << "Error: parenthesis expected" << endl;
        IsDataTrue = false;
    }
    if (comma == -1) {
        cout << "Error: wrong data" << endl;
        IsDataTrue = false;
    }
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
        else {
            cout << "Error: wrong symbols" << endl;
            IsDataTrue = false;
            break;
        }
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
        else if (input[i] == '.' && IsNumber && IsFloat) {
            cout << "Error:radius must be float";
            IsDataTrue = false;
            break;
        } else if (input[i] == '.' && IsNumber && IsFloat == false) {
            IsFloat = true;
        } else if (input[i] == ' ')
            continue;
        else {
            cout << "Error: wrong symbols" << endl;
            IsDataTrue = false;
            break;
        }
    }
    if (lcount != 2 || rcount != 1) {
        cout << "Error: wrong amount of data" << endl;
        IsDataTrue = false;
    }
    for (int i = right_par + 2; i < 80; i++) {
        if (input[i] != ' ') {
            cout << "Error: unexpected token" << endl;
            IsDataTrue = false;
            break;
        }
    }
    return IsDataTrue;
}

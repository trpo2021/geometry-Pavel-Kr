#include <libgeometry/functions.h>
#include <iostream>
#include <string>
using namespace std;
int CircleCheck(char *input)
{
    string inp;
    inp.assign(input);
    int left_par = inp.find('(');
    int right_par = inp.find(')', left_par);
    bool IsDataTrue = true;
    if (left_par == -1 || right_par == -1) {
        cout << "Error: parenthesis expected" << endl;
        IsDataTrue = false;
    }
    int comma = inp.find(',', left_par);
    if (comma == -1) {
        cout << "Error: wrong data" << endl;
        IsDataTrue = false;
    }
    bool IsNumber = false;
    int lcount = 0; // must be 2
    int rcount = 0; // must be 1
    for (int i = left_par + 1; i <= comma; i++) {
        if ((inp[i] == ' ' || inp[i] == ',') && IsNumber) {
            lcount++;
            IsNumber = false;
        }
        if ((inp[i] >= '0' && inp[i] <= '9') || inp[i] == ',') {
            IsNumber = true;
        } else if (inp[i] == ' ')
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
        if ((inp[i] == ' ' || inp[i] == ')') && IsNumber) {
            rcount++;
            IsNumber = false;
        }
        if ((inp[i] >= '0' && inp[i] <= '9') || inp[i] == ')')
            IsNumber = true;
        else if (inp[i] == '.' && IsNumber && IsFloat) {
            cout << "Error:radius must be float";
            IsDataTrue = false;
            break;
        } else if (inp[i] == '.' && IsNumber && IsFloat == false) {
            IsFloat = true;
        } else if (inp[i] == ' ')
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
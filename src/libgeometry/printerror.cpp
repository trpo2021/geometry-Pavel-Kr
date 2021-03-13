#include <iostream>
#include <libgeometry/functions.h>
using namespace std;
void PrintError(int x)
{
    switch (x) {
    case 1:
        cout << "Error: Parentheses expected" << endl;
        break;
    case 2:
        cout << "Error: wrong data" << endl;
        break;
    case 3:
        cout << "Error: wrong symbols" << endl;
        break;
    case 4:
        cout << "Error:radius must be float";
        break;
    case 5:
        cout << "Error: wrong amount of data" << endl;
        break;
    case 6:
        cout << "Error: unexpected token" << endl;
        break;
    }
}

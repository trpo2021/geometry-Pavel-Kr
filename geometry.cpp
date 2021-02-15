#include <iostream>
#include <string>
using namespace std;
int main()
{
    char input[80];
    string inp;
    cin.getline(input, 80);
    inp.assign(input);
    string circle = "circle";
    int lp = inp.find('(');
    int rp = inp.find(')');
    int space = inp.find(' ');
    if (lp == -1) {
        cout << "Error: parenthesis expected" << endl;
    }
    int CTrue = inp.compare(0, space, circle) * inp.compare(0, lp, circle);
    if (CTrue == 0)
        cout << "circle" << endl;
    else
        cout << "Error: circle expected" << endl;
    int zap = inp.find(',', lp);
    if (zap == -1) {
        cout << "Error: wrong data" << endl;
    }
    bool NTrue = true;
    bool IsNumber = false;
    int lcount = 0; // must be 2
    int rcount = 0; // must be 1
    for (int i = lp + 1; i <= zap; i++) {
        if ((inp[i] == ' ' || inp[i] == ',') && IsNumber) {
            lcount++;
            IsNumber = false;
        }
        if ((inp[i] >= '0' && inp[i] <= '9') || inp[i] == ',') {
            IsNumber = true;
        } else if (inp[i] == ' ')
            continue;
        else {
            NTrue = false;
            break;
        }
    }
    IsNumber = false;
    for (int i = zap + 1; i <= rp; i++) {
        if ((inp[i] == ' ' || inp[i] == ')') && IsNumber) {
            rcount++;
            IsNumber = false;
        }
        if ((inp[i] >= '0' && inp[i] <= '9') || inp[i] == ')')
            IsNumber = true;
        else if (inp[i] == ' ')
            continue;
        else {
            NTrue = false;
            break;
        }
    }
    if (!NTrue)
        cout << "Error: wrong symbols" << endl;
    if (lcount != 2 || rcount != 1)
        cout << "Error: wrong amount of data" << endl;
    return 0;
}

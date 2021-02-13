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
    if (lp == -1 || rp == -1) {
        cout << "Error: parenthesis expected" << endl;
    }
    int CTrue = inp.compare(0, space, circle);
    if (CTrue == 0)
        cout << "circle";
    else
        cout << "Error: circle expected";
    return 0;
}

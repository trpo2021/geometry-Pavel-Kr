#include <iostream>
#include <string>
using namespace std;
int main()
{
    string inp;
    cin >> inp;
    string circle = "circle";
    int lp = inp.find('(');
    int rp = inp.find(')');
    if (lp == -1 || rp == -1) {
        cout << "Error: parenthesis expected" << endl;
    }
    int CTrue = inp.compare(0, lp, circle);
    if (CTrue == 0)
        cout << "circle";
    else
        cout << "Error: circle expected";
    return 0;
}

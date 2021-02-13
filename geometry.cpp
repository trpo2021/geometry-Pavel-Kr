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
    if(lp==-1||rp==-1){
    	cout<<"Error: expected parenthesis";
    }
    int CTrue = inp.compare(0, lp, circle);
    
    return 0;
}

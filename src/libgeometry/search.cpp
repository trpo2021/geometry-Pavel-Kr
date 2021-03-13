#include <libgeometry/functions.h>
#include <string>
using namespace std;
void Search(char* input, int& left_par, int& right_par, int& comma)
{
    string inp;
    inp.assign(input);
    left_par = inp.find('(');
    right_par = inp.find(')', left_par);
    comma = inp.find(',', left_par);
}
void Search(char* input, int& left_par, int& right_par, int comma[])
{
    string inp;
    inp.assign(input);
    left_par = inp.find('(');
    right_par = inp.find(')', left_par);
    comma[0] = inp.find(',');
    for (int i = 1; i < 3; i++) {
        comma[i] = inp.find(',', comma[i - 1] + 1);
    }
}

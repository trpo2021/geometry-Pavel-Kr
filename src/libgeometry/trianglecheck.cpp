#include <iostream>
#include <libgeometry/functions.h>
#include <string>
using namespace std;
int TriangleCheck(char* input)
{
    int i;
    int left_par, right_par;
    int comma[3];
    Search(input, left_par, right_par, comma);
    if (left_par == -1 || right_par == -1)
        return 1;
    int comma_count = 1;
    for (i = 1; i < 3; i++) {
        if (comma[i] != -1)
            comma_count++;
    }
    if (comma_count != 3)
        return 2;
    bool is_number = false;
    int num_count[4] = {0, 0, 0, 0};
    for (int j = left_par + 1; j <= comma[0]; j++) {
        if ((input[j] == ' ' || input[j] == ',') && is_number) {
            num_count[0]++;
            is_number = false;
        }
        if ((input[j] >= '0' && input[j] <= '9') || input[j] == ',') {
            is_number = true;
        } else if (input[j] == ' ')
            continue;
        else
            return 3;
    }
    for (i = 0; i < 2; i++) {
        is_number = false;
        for (int j = comma[i] + 1; j <= comma[i + 1]; j++) {
            if ((input[j] == ' ' || input[j] == ',') && is_number) {
                num_count[i + 1]++;
                is_number = false;
            }
            if ((input[j] >= '0' && input[j] <= '9') || input[j] == ',') {
                is_number = true;
            } else if (input[j] == ' ')
                continue;
            else
                return 3;
        }
    }
    is_number = false;
    for (int j = comma[2] + 1; j <= right_par; j++) {
        if ((input[j] == ' ' || input[j] == ')') && is_number) {
            num_count[3]++;
            is_number = false;
        }
        if ((input[j] >= '0' && input[j] <= '9') || input[j] == ')') {
            is_number = true;
        } else if (input[j] == ' ')
            continue;
        else
            return 3;
    }
    for (i = 0; i < 4; i++) {
        if (num_count[i] != 2)
            return 5;
    }
    for (int i = right_par + 2; i < 80; i++) {
        if (input[i] != ' ')
            return 6;
    }
    return 0;
}

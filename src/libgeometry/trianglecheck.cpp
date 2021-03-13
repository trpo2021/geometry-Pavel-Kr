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
    bool is_data_true = true;
    if (left_par == -1 || right_par == -1) {
        cout << "Error: parenthesis expected" << endl;
        is_data_true = false;
    }
    int comma_count = 1;
    for (i = 1; i < 3; i++) {
        if (comma[i] != -1)
            comma_count++;
    }
    if (comma_count != 3) {
        cout << "Error: wrong data" << endl;
        is_data_true = false;
    }
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
        else {
            cout << "Error: wrong symbols" << endl;
            is_data_true = false;
            break;
        }
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
            else {
                cout << "Error: wrong symbols" << endl;
                is_data_true = false;
                break;
            }
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
        else {
            cout << "Error: wrong symbols" << endl;
            is_data_true = false;
            break;
        }
    }
    for (i = 0; i < 4; i++) {
        if (num_count[i] != 2) {
            cout << "Error: wrong amount of data" << endl;
            is_data_true = false;
            break;
        }
    }
    for (int i = right_par + 2; i < 80; i++) {
        if (input[i] != ' ') {
            cout << "Error: unexpected token" << endl;
            is_data_true = false;
            break;
        }
    }
    return is_data_true;
}

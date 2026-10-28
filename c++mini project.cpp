#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    char names[5][20];
    int marks[5][3];

    cout << "Enter 5 students' names:" << endl;

    for (int i = 0; i < 5; i++) {
        cin.getline(names[i], 20);
    }

    cout << "Enter 15 numbers :" << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> marks[i][j];
        }
        cin.ignore(1000, '\n');
    }

    cout << setw(20) << "Name"
         << setw(8) << "M1"
         << setw(8) << "M2"
         << setw(8) << "M3"
         << setw(10) << "Total"
         << setw(10) << "Avg" << endl;

    int sum[5] = {0};
    double average[5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i] += marks[i][j];
        }

        average[i] = (double)sum[i] / 3;

        cout << setw(20) << names[i];

        for (int j = 0; j < 3; j++) {
            cout << setw(8) << marks[i][j];
        }

        cout << setw(10) << sum[i]
             << setw(10) << fixed << setprecision(1)
             << average[i] << endl;
    }

    int big = 0;

    for (int i = 1; i < 5; i++) {
        if (sum[i] > sum[big]) {
            big = i;
        }
    }

    cout << "Top student: " << names[big] << endl;

    return 0;
}
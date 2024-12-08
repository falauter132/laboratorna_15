#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    const int n = 10;
    int A[n];
    int c = 0;

    cout << "Введіть елементи масиву:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            c++;
        }
    }

    cout << endl << "C = " << c;
}

//22//////////////////////////////////////////////////

int main() {
    int T;
    const int n = 10, m = 10;

    cin >> T;

    int A[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int last = -1, maxVal = 0;
    bool found = false;

    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (A[i][j] == T) {
                found = true;
                for (int k = j + 1; k < m; k++) {
                    if (A[i][k] < 0 && (last == -1 || A[i][k] > maxVal)) {
                        maxVal = A[i][k];
                        last = k;
                    }
                }
            }
        }
    }

    if (last != -1) {
        cout << last << endl;
    }
    else {
        cout << "Не знайдено" << endl;
    }

    return 0;
}

//3///////////////////////////////////////////////

int main() {
    const int n = 10;

    int A[n][n], B[n][n], result[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j] - B[i][k] * A[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//4///////////////////////////////////////////////////////////////

int main() {
    const int n = 10;
   

    int A[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    int rowIndex = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] < 0) {
                rowIndex = i;
                for (int k = 0; k < n; k++) {
                    A[k][j] /= 2;
                }
                break;
            }
        }
        if (rowIndex != -1) break;
    }

    if (rowIndex != -1) {
        cout << "Рядок з негативним елементом: " << rowIndex + 1 << endl;
    }
    else {
        cout << "Немає рядка з негативними елементами" << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
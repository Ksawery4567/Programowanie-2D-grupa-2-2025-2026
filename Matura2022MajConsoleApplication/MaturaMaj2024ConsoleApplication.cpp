#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int MAX = 100;

int A[MAX][MAX];
bool P[MAX][MAX];

int main() {
    int n, m;
    cout << "Podaj liczbe wierszy n i kolumn m:\n";
    cin >> n >> m;

    cout << "Wprowadz plansze\n" << n << m << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> A[i][j];
        }
    }


    P[1][1] = true;


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i][j] == 0) {
                P[i][j] = false;
            }
            else {
                if (i == 1 && j != 1)
                    P[i][j] = P[i][j - 1];
                else if (i != 1 && j == 1)
                    P[i][j] = P[i - 1][j];
                else if (i != 1 && j != 1)
                    P[i][j] = P[i][j - 1] || P[i - 1][j];
            }
        }
    }

    cout << "Tablica Pola:" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }


    cout << "Wynik:";
    if (P[n][m])
        cout << "PRAWDA" << endl;
    else
        cout << "FALSZ" << endl;

    return 0;
}


bool checkA(bool board[5][5]) {
    int blackCount = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j]) blackCount++;
        }
    }
    return blackCount <= 2;
}

bool checkB(bool board[4][4]) {
    int blackCount = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j]) blackCount++;
        }
    }
    return blackCount >= 9;
}

int main() {
    bool boardA[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    bool boardB[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };

    cout << "Wynik dla planszy a): " << (checkA(boardA) ? "FA£SZ" : "PRAWDA") << endl;
    cout << "Wynik dla planszy b): " << (checkB(boardB) ? "PRAWDA" : "FA£SZ") << endl;

    return 0;
}

int main() {
    int n;
    cout << "Podaj rozmiar planszy n x n: ";
    cin >> n;

    int maxCzarne = n * n;
    cout << "Najwiêksza mo¿liwa liczba czarnych pól: " << maxCzarne << endl;

    return 0;
}

int main() {
    long long n;
    cout << "Podaj nieujemn¹ liczbê ca³kowit¹ n: ";
    cin >> n;

    long long b = 1, c = 0;
    int instructionCount = 0;

    while (n > 0) {
        int a = n % 10;
        n /= 10;

        if (a % 2 == 0) {
            c = c + b * (a / 2);
        }
        else {
            c = c + b;
            instructionCount++;
        }

        b *= 10;
    }

    cout << "Wartoœæ dla c: " << c << endl;
    cout << "Liczba wykonanych instrukcji c <- c + b: " << instructionCount << endl;

    return 0;
}

int main() {
    int c = 6 * 3 + 6 * 6 + 6 * 9;
    std::cout << "c = " << c << std::endl;
    return 0;
}
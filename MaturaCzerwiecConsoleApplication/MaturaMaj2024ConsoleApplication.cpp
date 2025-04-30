#include <iostream>
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

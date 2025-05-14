#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//  ZAD 2 
int oddShortcut(long long n) {
    int b = 1, c = 0;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        if (digit % 2 == 0) c += b * (digit / 2);
        else c += b;
        b *= 10;
    }
    return c;
}

//  ZAD 3 
bool hasOnlyEvenDigits(int n) {
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) return false;
        n /= 10;
    }
    return true;
}

int shortcutOddDigits(int n) {
    int result = 0, multiplier = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) {
            result += digit * multiplier;
            multiplier *= 10;
        }
        n /= 10;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

//    ZAD 4 
bool canBeBuiltFrom(int number, const int firstRow[], int size) {
    int available[3000];
    for (int i = 0; i < size; i++) {
        available[i] = 1;
    }

    for (int i = 0; i < size; i++) {
        while (number % firstRow[i] == 0) {
            number /= firstRow[i];
            available[i]--;
            if (available[i] < 0) return false;
        }
    }
    return number == 1;
}
int main() {
    cout << "Zad 3.1";
    int number;
    cout << "Podaj liczbe: ";
    cin >> number;
    cout << "Skrocone nieparzyste cyfry: " << shortcutOddDigits(number) << endl;

    ifstream file1("skrot.txt");
    if (!file1.is_open()) {
        cout << "B³¹d otwarcia pliku skrot.txt" << endl;
        return 1;
    }
    int count = 0, maxEven = 0, value;
    while (file1 >> value) {
        if (hasOnlyEvenDigits(value)) {
            count++;
            if (value > maxEven) maxEven = value;
        }
    }
    file1.close();
    cout << "Zad 3.2";
    cout << "Liczba liczb zlozonych wylacznie z parzystych cyfr: " << count << endl;
    cout << "Najwieksza liczba z samych parzystych cyfr: " << maxEven << endl;

    ifstream file2("skrot2.txt");
    if (!file2.is_open()) {
        cout << "Blad otwarcia pliku skrot2.txt" << endl;
        return 1;
    }
    cout << "Zad 3.3";
    cout << "Liczby, dla których NWD:" << endl;
    int number2;
    while (file2 >> number2) {
        int shortNum = shortcutOddDigits(number2);
        if (gcd(number2, shortNum) == 7) {
            cout << number2 << endl;
        }
    }
    file2.close();

    ifstream file3("liczby.txt");
    if (!file3.is_open()) {
        cout << "B³¹d otwarcia pliku liczby.txt" << endl;
        return 1;
    }

    int row1[3000], row2[20];
    for (int i = 0; i < 3000; i++) file3 >> row1[i];
    for (int i = 0; i < 20; i++) file3 >> row2[i];
    file3.close();

    int divisibleCount = 0;
    for (int i = 0; i < 3000; i++) {
        for (int j = 0; j < 20; j++) {
            if (row2[j] % row1[i] == 0) {
                divisibleCount++;
                break;
            }
        }
    }
    cout << "Zad 4.1 " << endl;
    cout << "Liczba liczb dzielacych sie na co najmniej jedna z 20: " << divisibleCount << endl;

    int copy[3000];
    for (int i = 0; i < 3000; i++) copy[i] = row1[i];
    sortDescending(copy, 3000);
    cout << "Zad 4.2 " << endl;
    cout << "101. najwieksza liczba: " << copy[100] << endl;

    cout << "Zad 4.3 " << endl;
    cout << "Liczby, ktore mozna zbudowac z liczb pierwszego wiersza:" << endl;
    for (int i = 0; i < 20; i++) {
        if (canBeBuiltFrom(row2[i], row1, 3000)) {
            cout << row2[i] << " ";
        }
    }
    cout << endl;

    double bestAvg = 0.0;
    int bestLen = 0, firstElem = 0;
    for (int i = 0; i < 3000; i++) {
        int sum = 0;
        for (int j = i; j < 3000; j++) {
            sum += row1[j];
            int len = j - i + 1;
            if (len >= 50) {
                double avg = (double)sum / len;
                if (avg > bestAvg) {
                    bestAvg = avg;
                    bestLen = len;
                    firstElem = row1[i];
                }
            }
        }
    }
    cout << "Zad 4.4 " << endl;
    cout << "Najlepsza srednia: " << bestAvg << endl;
    cout << "Dlugosc ci¹gu: " << bestLen << endl;
    cout << "Pierwszy element ciagu: " << firstElem << endl;

    zadanie7();

    return 0;
}
    

    


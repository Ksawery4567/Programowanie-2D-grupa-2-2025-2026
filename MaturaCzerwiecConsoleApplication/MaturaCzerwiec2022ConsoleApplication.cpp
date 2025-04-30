#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool First(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    ifstream file("liczby.txt");
    int numbers[100];
    int count = 0;

    while (file >> numbers[count]) {
        count++;
    }

    cout << "Odwrócone liczby podzielne przez 17:";
    for (int i = 0; i < count; i++) {
        int reversed = reverseNumber(numbers[i]);
        if (reversed % 17 == 0) {
            cout << reversed << endl;
        }
    }

    cout << "Liczba ró¿ni¹ca siê najbardziej od swojej odwrotnoœci:";
    int maxDiff = 0;
    int original = 0, reversed = 0;
    for (int i = 0; i < count; i++) {
        int r = reverseNumber(numbers[i]);
        int diff = abs(numbers[i] - r);
        if (diff > maxDiff) {
            maxDiff = diff;
            original = numbers[i];
            reversed = r;
        }
    }
    cout << original << " " << reversed << endl;

    cout << "Liczby pierwsze, których odwrotnoœæ jest równie¿ liczb¹ pierwsz¹: ";
    for (int i = 0; i < count; i++) {
        int r = reverseNumber(numbers[i]);
        if (First(numbers[i]) && First(r)) {
            cout << numbers[i] << endl;
        }
    }

    return 0;
}

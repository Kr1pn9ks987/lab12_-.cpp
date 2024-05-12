// lab12_Габестро.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

// Функція для знаходження мінімального елемента в масиві
int findMin(int arr[], int size) {
   
    int minElement = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return minElement;
}

// Функція для перевірки, чи є число простим
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int N;
    cout << "Введіть число N: ";
    cin >> N;

    // Розрахунок кількості цифр у числі N
    int temp = N, digitCount = 0;
    while (temp != 0) {
        temp /= 10;
        ++digitCount;
    }

    // Створення масиву для зберігання цифр числа N
    int* digits = new int[digitCount];

    // Заповнення масиву цифрами числа N
    temp = N;
    for (int i = digitCount - 1; i >= 0; --i) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    // Знаходження мінімального елемента в масиві
    int minElement = findMin(digits, digitCount);

    cout << "Мінімальний елемент у масиві цифр: " << minElement << endl;

    // Перевірка, чи є число простим
    if (isPrime(minElement)) {
        cout << "Мінімальний елемент є простим числом" << endl;
    }
    else {
        cout << "Мінімальний елемент не є простим числом" << endl;
    }

    // Звільнення пам'яті, виділеної для масиву
    delete[] digits;

    return 0;
}
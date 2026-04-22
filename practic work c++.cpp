#include <iostream>
#include <string>
#include <iomanip>

void array_int(int* arr, int size) {
    if (size <= 0) return;

    int sumEven = 0, countEven = 0;
    int sumOdd = 0, countOdd = 0;

    for (int* ptr = arr; ptr < arr + size; ++ptr) {
        if (*ptr % 2 == 0) {
            sumEven += *ptr;
            countEven++;
        } else {
            sumOdd += *ptr;
            countOdd++;
        }
    }

    if (countEven > 0) {
        std::cout << "Середнє парних: " << static_cast<double>(sumEven) / countEven << std::endl;
    } else {
        std::cout << "Парні числа відсутні." << std::endl;
    }

    if (countOdd > 0) {
        std::cout << "Середнє непарних: " << static_cast<double>(sumOdd) / countOdd << std::endl;
    } else {
        std::cout << "Непарні числа відсутні." << std::endl;
    }
}

void min_max_str(std::string* arr, int size) {
    if (size <= 0) return;

    std::string* maxStr = arr;
    std::string* minStr = arr;

    for (std::string* ptr = arr; ptr < arr + size; ++ptr) {
        if (ptr->length() > maxStr->length()) {
            maxStr = ptr;
        }
        if (ptr->length() < minStr->length()) {
            minStr = ptr;
        }
    }

    std::cout << "Найдовший: \"" << *maxStr << "\" (Розмір: " << maxStr->length() << ")" << std::endl;
    std::cout << "Найкоротший: \"" << *minStr << "\" (Розмір: " << minStr->length() << ")" << std::endl;
}

void sum_reverse(double* arr, int size) {
    if (size <= 0) return;

    double totalSum = 0;
    std::cout << "Елементи у зворотному порядку: ";

    for (double* ptr = arr + size - 1; ptr >= arr; --ptr) {
        std::cout << *ptr << " ";
        totalSum += *ptr;
    }

    std::cout << "\nЗагальна сума: " << totalSum << std::endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(2);

    int n1;
    std::cout << "Введіть кількість цілих чисел: ";
    if (!(std::cin >> n1)) return 1;

    int* intArr = new int[n1];
    for (int i = 0; i < n1; ++i) {
        std::cout << "Число [" << i << "]: ";
        std::cin >> *(intArr + i);
    }
    
    array_int(intArr, n1);

    std::string words[] = {"Apple", "Banana", "Kiwi", "Strawberry", "Go"};
    int n2 = sizeof(words) / sizeof(words[0]);
    min_max_str(words, n2);

    double prices[] = {12.50, 45.99, 105.00, 7.25};
    int n3 = sizeof(prices) / sizeof(prices[0]);
    sum_reverse(prices, n3);

    delete[] intArr;
    return 0;
}
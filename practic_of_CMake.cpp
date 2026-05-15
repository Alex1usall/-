#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

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
        cout << "Середнє парних: "
             << static_cast<double>(sumEven) / countEven << endl;
    } else {
        cout << "Парні числа відсутні." << endl;
    }

    if (countOdd > 0) {
        cout << "Середнє непарних: "
             << static_cast<double>(sumOdd) / countOdd << endl;
    } else {
        cout << "Непарні числа відсутні." << endl;
    }
}

void min_max_str(string* arr, int size) {
    if (size <= 0) return;

    string* maxStr = arr;
    string* minStr = arr;

    for (string* ptr = arr; ptr < arr + size; ++ptr) {
        if (ptr->length() > maxStr->length()) {
            maxStr = ptr;
        }

        if (ptr->length() < minStr->length()) {
            minStr = ptr;
        }
    }

    cout << "Найдовший: \"" << *maxStr
         << "\" (Розмір: " << maxStr->length() << ")" << endl;

    cout << "Найкоротший: \"" << *minStr
         << "\" (Розмір: " << minStr->length() << ")" << endl;
}

void sum_reverse(double* arr, int size) {
    if (size <= 0) return;

    double totalSum = 0;

    cout << "Елементи у зворотному порядку: ";

    for (double* ptr = arr + size - 1; ptr >= arr; --ptr) {
        cout << *ptr << " ";
        totalSum += *ptr;
    }

    cout << "\nЗагальна сума: " << totalSum << endl;
}

void menu() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1 - Extion 1\n";
        cout << "2 - Extion 2\n";
        cout << "3 - Extion 3\n";

        cin >> choice;

        switch (choice) {

            case 1: {
                int n1;

                cout << "Введіть кількість цілих чисел: ";
                cin >> n1;

                int* intArr = new int[n1];

                for (int i = 0; i < n1; ++i) {
                    cout << "Число [" << i << "]: ";
                    cin >> intArr[i];
                }

                array_int(intArr, n1);

                delete[] intArr;
                break;
            }

            case 2: {
                string words[] = {
                    "Apple",
                    "Banana",
                    "Kiwi",
                    "Strawberry",
                    "Go"
                };

                int n2 = sizeof(words) / sizeof(words[0]);

                min_max_str(words, n2);

                break;
            }

            case 3: {
                double prices[] = {
                    12.50,
                    45.99,
                    105.00,
                    7.25
                };

                int n3 = sizeof(prices) / sizeof(prices[0]);

                sum_reverse(prices, n3);

                break;
            }

            case 0:
                cout << "Exit\n";
                break;

            default:
                cout << "Wrong choice\n";
        }

    } while (choice != 0);
}

int main() {

    cout << fixed << setprecision(2);

    menu();

    return 0;
}
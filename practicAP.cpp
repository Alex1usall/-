#include <iostream>
#include <ctime>

using namespace std;

void filling_an_array(float*** array, int size) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            for (int z = 0; z < size; z++) {

                cout << array[i][j][z] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }
}

int main() {

    cout << "Завдання 1" << endl;

    cout << "Enter char: " << endl;
    char* a = new char;
    cin >> *a;
    cout << "Char: " << *a << endl;
    delete a;

    cout << "Enter short: " << endl;
    short* b = new short;
    cin >> *b;
    cout << "Short: " << *b << endl;
    delete b;

    cout << "Enter int: " << endl;
    int* c = new int;
    cin >> *c;
    cout << "Int: " << *c << endl;
    delete c;

    cout << "Enter long: " << endl;
    long* d = new long;
    cin >> *d;
    cout << "Long: " << *d << endl;
    delete d;

    cout << "Enter float: " << endl;
    float* e = new float;
    cin >> *e;
    cout << "Float: " << *e << endl;
    delete e;

    cout << "Enter double: " << endl;
    double* f = new double;
    cin >> *f;
    cout << "Double: " << *f << endl;
    delete f;

    cout << endl;

    cout << "Завдання 2" << endl;

    double* Int = new double;

    cin >> *Int;

    double& doub = *Int;

    cout << doub << endl;

    delete Int;

    cout << endl;

    cout << "Завдання 3" << endl;

    int num;

    cin >> num;

    int* array = new int[num];

    for (int i = 0; i < num; i++) {
        array[i] = num - 1 - i;
    }

    cout << "Array: " << endl;

    for (int i = num-1; i >= 0; i--) {
        cout << array[i] << " ";
    }

    delete[] array;

    cout << endl << endl;

    cout << "Завдання 4" << endl;

    srand(time(0));

    int num1;

    cout << "Enter random number 1: " << endl;
    cin >> num1;

    float*** third_line = new float**[num1];

    for (int i = 0; i < num1; i++) {

        third_line[i] = new float*[num1];

        for (int j = 0; j < num1; j++) {

            third_line[i][j] = new float[num1];
        }
    }

    for (int i = 0; i < num1; i++) {

        for (int j = 0; j < num1; j++) {

            for (int z = 0; z < num1; z++) {

                third_line[i][j][z] = rand() % 100;
            }
        }
    }

    filling_an_array(third_line, num1);

    for (int i = 0; i < num1; i++) {

        for (int j = 0; j < num1; j++) {

            delete[] third_line[i][j];
        }

        delete[] third_line[i];
    }

    delete[] third_line;

    return 0;
}

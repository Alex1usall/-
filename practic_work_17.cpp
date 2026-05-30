#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

struct Vertex {
    float pos[2];
};

float findSquare(Vertex* figure, int count) {

    if (count != 4) {
        return 0;
    }

    float lengthA = sqrt(
        pow(figure[1].pos[0] - figure[0].pos[0], 2) +
        pow(figure[1].pos[1] - figure[0].pos[1], 2)
    );

    float lengthB = sqrt(
        pow(figure[2].pos[0] - figure[1].pos[0], 2) +
        pow(figure[2].pos[1] - figure[1].pos[1], 2)
    );

    return lengthA * lengthB;
}

void showData(Vertex* figure, int count) {

    cout << "\nКоординати вершин:\n";

    for (int i = 0; i < count; i++) {
        cout << "Вершина " << i + 1
             << " -> X: " << figure[i].pos[0]
             << " Y: " << figure[i].pos[1]
             << endl;
    }
}

void autoFill(Vertex* figure, int count) {

    for (int i = 0; i < count; i++) {
        figure[i].pos[0] = rand() % 100;
        figure[i].pos[1] = rand() % 100;
    }

    showData(figure, count);

    cout << "\nПлоща прямокутника: "
         << findSquare(figure, count)
         << endl;
}

void manualFill(Vertex* figure, int count) {

    for (int i = 0; i < count; i++) {

        cout << "\nВведення вершини " << i + 1 << endl;

        while (true) {

            string value;

            cout << "X = ";
            cin >> value;

            try {

                size_t pos;
                figure[i].pos[0] = stof(value, &pos);

                if (pos != value.length()) {
                    throw invalid_argument("");
                }

                break;
            }
            catch (...) {
                cout << "Помилка введення. Спробуйте ще раз.\n";
            }
        }

        while (true) {

            string value;

            cout << "Y = ";
            cin >> value;

            try {

                size_t pos;
                figure[i].pos[1] = stof(value, &pos);

                if (pos != value.length()) {
                    throw invalid_argument("");
                }

                break;
            }
            catch (...) {
                cout << "Помилка введення. Спробуйте ще раз.\n";
            }
        }
    }

    showData(figure, count);

    cout << "\nПлоща прямокутника: "
         << findSquare(figure, count)
         << endl;
}

void startProgram() {

    Vertex* figure = new Vertex[4];

    int option;

    cout << "============================\n";
    cout << "   РОЗРАХУНОК ПЛОЩІ\n";
    cout << "============================\n";
    cout << "1 - Згенерувати координати\n";
    cout << "2 - Ввести координати вручну\n";
    cout << "Оберіть пункт: ";

    cin >> option;

    switch (option) {

        case 1:
            autoFill(figure, 4);
            break;

        case 2:
            manualFill(figure, 4);
            break;

        default:
            cout << "Невірний вибір." << endl;
    }

    delete[] figure;
}

int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    startProgram();

    return 0;
}
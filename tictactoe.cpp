#include <iostream>
#include <vector>

using namespace std;

// Funkcja do wyświetlania planszy
void wyswietlPlansze(const vector<char>& plansza) {
    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0)
            cout << endl;
        cout << plansza[i] << " ";
    }
    cout << endl;
}

// Funkcja do sprawdzania, czy jest zwycięzca
bool sprawdzZwyciezce(const vector<char>& plansza, char gracz) {
    for (int i = 0; i < 9; i += 3)
        if (plansza[i] == gracz && plansza[i + 1] == gracz && plansza[i + 2] == gracz)
            return true;

    for (int i = 0; i < 3; ++i)
        if (plansza[i] == gracz && plansza[i + 3] == gracz && plansza[i + 6] == gracz)
            return true;

    if (plansza[0] == gracz && plansza[4] == gracz && plansza[8] == gracz)
        return true;

    if (plansza[2] == gracz && plansza[4] == gracz && plansza[6] == gracz)
        return true;

    return false;
}

int main() {
    vector<char> plansza(9, ' ');
    char obecnyGracz = 'X';
    int ruch;
    
    while (true) {
        wyswietlPlansze(plansza);
        cout << "Gracz " << obecnyGracz << ", podaj numer pola: " << endl;
        cout << "" << endl;
        cout << "---------" << endl;
        cout << "1 | 2 | 3" << endl;
        cout << "---------" << endl;
        cout << "4 | 5 | 6" << endl;
        cout << "---------" << endl;
        cout << "7 | 8 | 9" << endl;
        cout << "---------" << endl;
        cin >> ruch;

        if (ruch < 1 || ruch > 9 || plansza[ruch - 1] != ' ') {
            cout << "Nieprawidłowy ruch, spróbuj jeszcze raz." << endl;
            continue;
        }

        plansza[ruch - 1] = obecnyGracz;

        if (sprawdzZwyciezce(plansza, obecnyGracz)) {
            wyswietlPlansze(plansza);
            cout << "Gracz " << obecnyGracz << " wygrał!" << endl;
            break;
        }

        obecnyGracz = (obecnyGracz == 'X') ? 'O' : 'X';
    }

    return 0;
}

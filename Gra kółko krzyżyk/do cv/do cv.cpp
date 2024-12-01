#include <iostream>
using namespace std;


void wyswietlPlansze(char plansza[3][3]) {
    cout << "Aktualna plansza:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << plansza[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---\n";
    }
}


char sprawdzZwyciezce(char plansza[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (plansza[i][0] == plansza[i][1] && plansza[i][1] == plansza[i][2]) return plansza[i][0];
        if (plansza[0][i] == plansza[1][i] && plansza[1][i] == plansza[2][i]) return plansza[0][i];
    }
    
    if (plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2]) return plansza[0][0];
    if (plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0]) return plansza[0][2];
    
    return ' ';
}


int main() {
    char plansza[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char obecnyGracz = 'X';
    int ruch;
    int liczbaRuchow = 0;
    char zwyciezca = ' ';

    cout << "Witamy w grze Kolko i Krzyzyk!\n";
    wyswietlPlansze(plansza);

    while (liczbaRuchow < 9 && zwyciezca == ' ') {
        cout << "Gracz " << obecnyGracz << ", wybierz pole (1-9): ";
        cin >> ruch;

        if (ruch < 1 || ruch > 9) {
            cout << "Nieprawidlowy ruch. Sprobuj ponownie.\n";
            continue;
        }
        int wiersz = (ruch - 1) / 3;
        int kolumna = (ruch - 1) % 3;

        
        if (plansza[wiersz][kolumna] == 'X' || plansza[wiersz][kolumna] == 'O') {
            cout << "Pole jest juz zajete. Wybierz inne.\n";
            continue;
        }

        
        plansza[wiersz][kolumna] = obecnyGracz;
        liczbaRuchow++;
        wyswietlPlansze(plansza);
        zwyciezca = sprawdzZwyciezce(plansza);
        if (zwyciezca != ' ') break;

        
        obecnyGracz = (obecnyGracz == 'X') ? 'O' : 'X';
    }

    if (zwyciezca != ' ') {
        cout << "Gratulacje! Gracz " << zwyciezca << " wygrywa!\n";
    }
    else {
        cout << "Remis! Nikt nie wygrywa.\n";
    }

    return 0;
}

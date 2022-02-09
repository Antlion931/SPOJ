#include <iostream>

using namespace std;

int punkty(string sekwencja)
{
    int wynik = 0;
    for(int i = 0; i < sekwencja.length(); i++)
    {
        switch(sekwencja[i])
        {
        case 'T':
            wynik += 10;
        break;

        case 'J':
            wynik += 11;
        break;

        case 'Q':
            wynik += 12;
        break;

        case 'K':
            wynik += 13;
        break;

        case 'A':
            wynik += 14;
        break;
        
        default:
            wynik += sekwencja[i] - '0';
        break;
        }
    }
    return wynik;
}

int main()
{
    string sekwencjaJasia, sekwencjaStasia;
    cin >> sekwencjaJasia >> sekwencjaStasia;
    int punktyJasia = punkty(sekwencjaJasia), punktyStasia = punkty(sekwencjaStasia);

    if(punktyJasia > punktyStasia) cout << "JASIO" << endl;
    else if(punktyJasia < punktyStasia) cout << "STASIO" << endl;
    else cout << "REMIS" << endl;
}
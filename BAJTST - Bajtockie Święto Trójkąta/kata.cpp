#include <iostream>

using namespace std;

void quickSort(int tab[], const int lewyKraniec, const int prawyKraniec)
{
    int pivot = tab[(lewyKraniec + prawyKraniec) / 2];
    int lewyAktualny = lewyKraniec;
    int prawyAktualny = prawyKraniec;

    do
    {
        while(tab[lewyAktualny] < pivot) lewyAktualny++;
        while(tab[prawyAktualny] > pivot) prawyAktualny--;

        if(lewyAktualny <= prawyAktualny)
        {
            int bufor = tab[lewyAktualny];
            tab[lewyAktualny] = tab[prawyAktualny];
            tab[prawyAktualny] = bufor;

            lewyAktualny++;
            prawyAktualny--;
        }
    } while (lewyAktualny <= prawyAktualny);

    if(lewyAktualny < prawyKraniec) quickSort(tab, lewyAktualny, prawyKraniec);
    if(lewyKraniec < prawyAktualny) quickSort(tab, lewyKraniec, prawyAktualny);
}

string tabToString(int tab[], int amount)
{
    string wynik;
    for(int i = 0; i < amount; i++)
    {
        wynik += " " + to_string(tab[i]);
    }
    return wynik;
}

int main()
{
    int tab[10] = {3, 4, 5, 1, 2, 0, 6, 7, 8, 9};

    cout << "tab przed quickSort: " << tabToString(tab, 10) << endl;
    quickSort(tab, 0, 9);
    cout << "tab po quickSort: " << tabToString(tab, 10) << endl;
}
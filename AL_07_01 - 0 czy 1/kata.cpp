#include <iostream>

using namespace std;

void quickSort(int tab[], int lewyKoniec, int prawyKoniec)
{
    int lewyIndex = lewyKoniec; 
    int prawyIndex = prawyKoniec;
    int pivot = tab[ (lewyKoniec+prawyKoniec) / 2];

    do
    {
        while(tab[lewyIndex] < pivot) lewyIndex++;
        while(tab[prawyIndex] > pivot) prawyIndex--;

        if(lewyIndex <= prawyIndex)
        {
            int bufor = tab[lewyIndex];
            tab[lewyIndex] = tab[prawyIndex];
            tab[prawyIndex] = bufor;

            lewyIndex++;
            prawyIndex--;        
        }
    } while(lewyIndex <= prawyIndex);
    
    if(lewyIndex < prawyKoniec) quickSort(tab, lewyIndex, prawyKoniec);
    if(prawyIndex > lewyKoniec) quickSort(tab, lewyKoniec, prawyIndex);
}

string tabToString(int tab[], int n)
{
    string wynik;

    for(int i = 0; i < n; i++)
    {
        if( i!= 0) wynik += " ";
        wynik += to_string(tab[i]);
    }

    return wynik;
}

int main()
{
    int tab[10] = {9, 8, 7, 6, 5, 1, 2, 3, 4, 0};
    cout << "tab przed quick sort: " << tabToString(tab, 10) << endl;
    quickSort(tab, 0, 9);
    cout << "tab po quick sort: " << tabToString(tab, 10) << endl;
}
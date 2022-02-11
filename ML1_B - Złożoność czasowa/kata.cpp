#include <iostream>

using namespace std;

void quicksort(int tab[], int lewy, int prawy)
{
    int l = lewy, p = prawy, pivot = tab[(prawy + lewy) / 2];

    do
    {
        while(tab[l] < pivot) l++;
        while(tab[p] > pivot) p--;

        if(l <= p)
        {
            int bufor = tab[l];
            tab[l] = tab[p];
            tab[p] = bufor;
            l++;
            p--;
        }
    }while( l <= p);

    if(p > lewy) quicksort(tab, lewy, p);
    if(l < prawy) quicksort(tab, l, prawy);
}

int main()
{
    int tab[7] = {6, 7, 19, 3, 5, -7, 0};
    cout << "tab przed quicksort: " << flush;
    for(int i = 0; i < 7; i++)
    {
        cout << tab[i] << " ";
    }
    quicksort(tab, 0, 6);
    cout << "\ntab po quicksort: " << flush;
    for(int i = 0; i < 7; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}
#include <iostream>

using namespace std;

void quicksort(int tab[], int lewy, int prawy)
{
    int pivot = tab[(lewy + prawy) / 2];
    int l, p;
    l = lewy;
    p = prawy;
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
    } while (l <= p);

    if(p > lewy) quicksort(tab, lewy, p);
    if(l < prawy) quicksort(tab, l, prawy);
}

int main()
{
    int tab[6] = {4, 6, 2, 5, 1, 2};
    cout << "tab przed quick sort: ";
    for(int i = 0; i < 6; i++)
    {
        cout << tab[i] << " " << flush;
    }
    quicksort(tab, 0, 5);
    cout << "\ntab po quick sort: ";
    for(int i = 0; i < 6; i++)
    {
        cout << tab[i] << " " << flush;
    }
    cout << endl;
}
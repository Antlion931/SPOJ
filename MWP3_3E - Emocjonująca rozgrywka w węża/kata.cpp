#include <iostream>

using namespace std;

void quickSort(int tab[], int lewy, int prawy)
{
    int l = lewy;
    int p = prawy;
    int pivot = tab[(lewy+prawy) / 2];

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
    }while(l <= p);

    if(p > lewy) quickSort(tab, lewy, p);
    if(l < prawy) quickSort(tab, l, prawy);
}

void wypiszTab(int tab[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

int main()
{
    int tab[6] = {5, 4, 3, 6, 1, 2};
    cout << "przed quick sortem:" << endl;
    wypiszTab(tab, 6);
    
    quickSort(tab, 0, 5);

    cout << "po quick sorcie:" << endl;
    wypiszTab(tab, 6);
}
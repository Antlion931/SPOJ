#include <iostream>

using namespace std;

int main()
{
    int iloscLiczb;
    cin >> iloscLiczb;

    int *liczby = new int[iloscLiczb], wynik = 0;

    for(int i = 0; i < iloscLiczb; i++)
    {
        cin >> liczby[i];
    }

    for(int i = 2; i < iloscLiczb; i++)
    {
        if(liczby[i - 2] + liczby[i - 1] == liczby[i])
        {
            ++wynik;
        }
    }

    cout << wynik << endl;
}
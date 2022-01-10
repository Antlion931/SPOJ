#include <iostream>

using namespace std;

int main()
{
    int tab[257] = {}, t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        tab[x]++;
    }

    int wynik = 0;
    for(int i = 0; i < 257; i++)
    {
        wynik += tab[i] / 3;
    }
    cout << wynik << endl;
}
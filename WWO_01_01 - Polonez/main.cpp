#include <iostream>

using namespace std;

int main()
{
    short int a, b, c;

    cin >> a >> b >> c;

    int liczbaDziewczyn = 0, liczbaChlopcow = 0;
    for(int i = 0; i < a + b +c; i++)
    {
        string imie;
        cin >> imie;
        
        if(imie[imie.length() - 1] == 'a')
        {
            ++liczbaDziewczyn;
        }
        else
        {
            ++liczbaChlopcow;
        }
    }

    cout << ( liczbaChlopcow > liczbaDziewczyn ? liczbaDziewczyn : liczbaChlopcow) << endl;
}
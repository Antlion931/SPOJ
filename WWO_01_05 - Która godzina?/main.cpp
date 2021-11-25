#include <iostream>
#include <sstream>

using namespace std;

int zwracamDecZBin(int b);

int main()
{
    stringstream godzina;

    for(int i = 0; i < 4; i++)
    {
        int bin;
        cin >> bin;
        godzina << zwracamDecZBin(bin);
        if(i == 1)
        {
            godzina << ":";
        }
    }

    cout << godzina.str() << endl;
}

int zwracamDecZBin(int b)
{
    int wynik = 0, potegaDwa = 1;
    while(b)
    {
        wynik += b % 10 * potegaDwa;
        potegaDwa *= 2;
        b /= 10; 
    }
    return wynik;
}
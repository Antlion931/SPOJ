#include <iostream>

using namespace std;

int main()
{
    string slowo;
    int dlugosc;
    cin >> dlugosc >> slowo;
    for(int i = 0; i <= dlugosc/2; i++)
    {
        for(int k = 0; k < dlugosc; k++)
        {
            if(abs(i - k) > dlugosc/2 || abs(dlugosc/2 - i) > k)
            {
                cout << ".";
            }
            else
            {
                cout << slowo[k];
            }
        }
        cout << endl;
    }
}
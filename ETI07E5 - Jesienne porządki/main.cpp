#include <iostream>

using namespace std;

class kopiec
{
public:
    int dlugosc_drogi(int kopiecX);
    void wczytaj();
    int x;
    int y;
};

int main()
{
    int n;
    cin >> n;

    kopiec *kopce = new kopiec[n];
    int minX = INT32_MAX, maxX = INT32_MIN;
    for(int i = 0; i < n; i++)
    {
        kopce[i].wczytaj();

        if(kopce[i].x < minX)
        {
            minX = kopce[i].x;
        }

        if(kopce[i].x > maxX)
        {
            maxX = kopce[i].x;
        }
    }

    long long int minOdleglosc = INT32_MAX;
    int minOdlegloscX;
    for(int i = minX; i <= maxX; i++)
    {
        long long int odleglosc = 0;
        for(int k = 0; k < n; k++)
        {
            odleglosc += kopce[k].dlugosc_drogi(i);
            if(odleglosc > minOdleglosc)
            {
                break;
            }
        }
        //cout << i << " " << odleglosc << endl;
        if(odleglosc < minOdleglosc)
        {
            minOdleglosc = odleglosc;
            minOdlegloscX = i;
        }
    }

    cout << minOdlegloscX << " " << minOdleglosc << endl;
    delete[] kopce;
}

int kopiec::dlugosc_drogi(int kopiecX)
{
    int wynik = abs(y);
    wynik += abs(kopiecX - x); 
    return wynik;
}

void kopiec::wczytaj()
{
    cin >> x >> y;
}

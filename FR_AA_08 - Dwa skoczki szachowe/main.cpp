#include <iostream>

using namespace std;

int main()
{
    string wspSkoczkaBialego, wspSkoczkaCzarnego;
    cin >> wspSkoczkaBialego >> wspSkoczkaCzarnego;

    int roznicaKolumn = abs(wspSkoczkaBialego[0] - wspSkoczkaCzarnego[0]),
        roznicaWierszy = abs(wspSkoczkaBialego[1] - wspSkoczkaCzarnego[1]);
        
    if((roznicaKolumn == 2 && roznicaWierszy == 1) || (roznicaKolumn == 1 && roznicaWierszy == 2))
    {
        cout << "TAK" << endl;
    }
    else
    {
        cout << "NIE" << endl;
    }
}
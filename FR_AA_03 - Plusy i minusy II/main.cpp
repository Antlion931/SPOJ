#include <iostream>

using namespace std;

int main()
{
    
    int stos = 0;
    bool czyOcenaWystawiona = false;
    string wej;
    cin >> wej;
    
    for(int i = 0; i < wej.length(); i++)
    {
        if(wej[i] == '+')
        {
            ++stos;
        }
        else if(wej[i] == '-')
        {
            --stos;
        }

        if(stos >= 3)
        {
            cout << 5 << " ";
            czyOcenaWystawiona = true;
            stos = 0;
        }
        else if (stos <= -3)
        {
            cout << 1 << " ";
            czyOcenaWystawiona = true;
            stos = 0;
        }
    }

    if(!czyOcenaWystawiona)
    {
        cout << "BRAK";
    }
    cout << endl;
}
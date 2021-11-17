#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int sumaWygranych = 0, sumaPrzegranych = 0, rundy;
        for(int k = 0; k < 3; k++)
        {
            int w,l;
            cin >> w >> l;
            sumaWygranych += w;
            sumaPrzegranych += l; 
            rundy = w + l;
        }

        cout << rundy * 2 - sumaWygranych << " " << rundy * 2 - sumaPrzegranych << endl;


    }


}
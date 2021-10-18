#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        long long int x;
        int p;
        cin >> x >> p;

        int liczbaCyfr = 1;
        while(x >= p)
        {
            x /= p;
            ++liczbaCyfr;
        }
        cout << liczbaCyfr << endl;
    }
}
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string szyfr;
        cin >> szyfr;
        for(int k = 0; k < szyfr.length(); k += 5)
        {
            int znak = 0;
            for(int z = 0; z < 5; z++)
            {
                znak <<= 1;
                if(szyfr[k + z] == '1')
                {
                    znak += 1;
                }
            }
            cout << char(znak + 'A');
        }
        cout << endl;
    }
}
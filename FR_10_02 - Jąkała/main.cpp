#include <iostream>

using namespace std;

int main()
{
    int liczbaLiter;
    cin >> liczbaLiter;
    bool LiteryJakane[26] = {};


    for(int i = 0; i < liczbaLiter; i++)
    {
        char c;
        cin >> c;
        LiteryJakane[c - 'a'] = true;
    }

    string slowo;
    cin >> slowo;
    for(int i = 0; i < slowo.length(); i++)
    {
        cout << slowo[i];
        if(LiteryJakane[slowo[i] - 'a'])
        {
            cout << slowo[i];
        }
    }
    cout << endl;
}
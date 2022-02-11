#include <iostream>

using namespace std;

int main()
{
    int linijki, maxS = 0, curS = 0;
    cin >> linijki;
    for(int i = 0; i < linijki; i++)
    {
        string linia;
        cin >> linia;
        if(linia == "for")
        {
            curS++;
            if(curS > maxS)
            {
                maxS = curS;
            }
        }
        else if(linia == "end")
        {
            curS--;
        }
    }

    switch(maxS)
    {
        case 0:
            cout << "O(1)" << endl;
        break;

        case 1:
            cout << "O(n)" << endl;
        break;

        default:
            cout << "O(n^" << maxS << ")" << endl;
        break;
    }
}
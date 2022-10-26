#include <iostream>
#include <math.h>

int main()
{
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++)
    {
        int a,b,c,d;

        std::cin >> a >> b >> c >> d;

        int max1 = std::max(a, b);
        int min1 = std::min(a, b);

        int max2 = std::max(c, d);
        int min2 = std::min(c, d);

        if(max2 < max1)
        {
            if(min2 < min1)
            {
                std::cout << "TAK\n";
            }
            else
            {
                std::cout << "NIE\n";
            }
            continue;
        }

        int przekatna = std::sqrt(pow(c, 2) + pow(d, 2));

        double arcX = acos( double(max2)/przekatna );
        double arcY = acos( double(min2)/przekatna );

        double newArcX = acos(double(max1)/przekatna );

        double newArcY = arcY - arcX - newArcX;

        if(newArcY >= 0 && cos(newArcY) * przekatna < min1)
        {
            std::cout << "TAK\n";
        }
        else
        {
            std::cout << "NIE\n";
        }
    }
}
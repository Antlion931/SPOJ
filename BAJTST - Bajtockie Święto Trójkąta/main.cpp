#include <iostream>
#include <math.h>

using namespace std;

bool CanTriangelBeMade(int a, int b, int c)
{
    if(a+b <= c || b+c <= a || a+c <= b)
    {
        return false;
    }
    return true;
}

double AreaOfTriangleFromSides(int a, int b, int c) // return 0 when it is not possible to make triangle
{
    if(!CanTriangelBeMade(a, b, c))
    {
        return 0;
    }

    double p = (a+b+c) / 2.0; //half perimeter of triangle
    double areaSqured =  p * (p-a) * (p-b) * (p-c);
    return sqrt(areaSqured);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int amountOfTests;
    cin >> amountOfTests;

    for(int t = 0; t < amountOfTests; t++)
    {
        int amountOfParticipants;
        double averageUseOfChalk_kg_m2;
        cin >> amountOfParticipants >> averageUseOfChalk_kg_m2;

        double chalkUsage_g = 0.0;
        double averageUseOfChalk_g_cm2 = averageUseOfChalk_kg_m2 / 10.0;

        for(int p = 0; p < amountOfParticipants; p++)
        {
            int a_cm, b_cm, c_cm; //sides of a triangle in centimeters
            cin >> a_cm >> b_cm >> c_cm;

            double area_cm2 = AreaOfTriangleFromSides(a_cm, b_cm, c_cm);
            chalkUsage_g += area_cm2 * averageUseOfChalk_g_cm2;
        }
        
        long int result = round(chalkUsage_g);
        cout << result << endl;
    }
}
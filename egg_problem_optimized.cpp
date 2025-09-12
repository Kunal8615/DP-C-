#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cstring>
using namespace std;

int t[1001][1001];

int egg_drop(int egg, int floor)
{

    if (t[egg][floor] != -1)
    {
        return t[egg][floor];
    }
    int low;
    int high;

    int mn = INT_MAX;

    if (floor == 0 || floor == 1)
    {
        return floor;
    }

    if (egg == 1)
    {
        return floor;
    }

    for (int k = 1; k <= floor; k++)
    {
        if (t[egg - 1][k - 1] != -1)
        {
             low = t[egg - 1][k - 1];
        }
        else
        {
            low = egg_drop(egg - 1, k - 1);
            t[egg - 1][k - 1] = low;
        }

        if (t[egg][floor - k] != -1)
        {
             high = t[egg][floor - k];
        }
        else
        {
            high = egg_drop(egg, floor - k);
            t[egg][floor - k]  = high;

        }

        int temp = 1 + max(low,high);
        mn = min(mn, temp);
        t[egg][floor] = mn;
    }
    return mn;
}

int main()
{
    int egg = 3;
    int floor = 5;
    memset(t, -1, sizeof(t));
    cout << egg_drop(egg, floor);
    return 0;
}
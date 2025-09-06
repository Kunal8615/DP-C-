#include <iostream>
#include <stdlib.h>
#include <climits>
#include <algorithm>
using namespace std;
int static t[1001][1001];

bool palaindrome(string str, int i, int j)
{

    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int solve(string str, int i, int j)
{
    int mn = INT_MAX;
    int left, right;
    if (i >= j || palaindrome(str, i, j))
    {
        return 0;
    }

    for (int k = i; k <= j - 1; k++)
    {

        if (t[i][k] != 0)
        {
            left = t[i][k];
        }
        else
        {
            left = solve(str, i, k);
        }

        if (t[k+1][j] != 0)
        {
            right = t[k + 1][j];
        }
        else
        {
            right = solve(str, k+1, j);
        }
        int temp = 1 + left + right;
        mn = min(temp, mn);
    }
    t[i][j] = mn;
    return t[i][j];
}

int main()
{
    string str = "atba";
    int str_size = str.size();
    int i = 0;
    int j = str_size - 1;
    cout << solve(str, i, j);
    return 0;
}
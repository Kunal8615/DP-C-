#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int t[100][100];

string print_lcs(char *a, char *b, int size_a, int size_b)
{
    string str = "";

    for (int i = 0; i <= size_a; i++)
    {
        for (int j = 0; j <= size_b; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0; // inslization
            else if (a[i - 1] == b[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    int i = size_a, j = size_b;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            str.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (t[i - 1][j] > t[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    //  cout<<str<<endl;
    reverse(str.begin(), str.end());
  //  cout<<str;
    return str;
}

int main()
{
    char a[] = "acee";
    int size_a = sizeof(a) / sizeof(a[0]) - 1;
    char b[] = "zabne";
    int size_b = sizeof(b) / sizeof(b[0]) - 1;
    cout << print_lcs(a, b, size_a, size_b);
    return 0;
   
}

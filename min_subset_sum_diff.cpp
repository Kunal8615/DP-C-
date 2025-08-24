#include <bits/stdc++.h>
using namespace std;

int t[100][100];

int min_sub_diff(int *arr, int arr_size, int arr_sum)
{
    // Initialize DP table
    for (int i = 0; i <= arr_size; i++) {
        for (int j = 0; j <= arr_sum; j++) {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    // Fill DP table
    for (int i = 1; i <= arr_size; i++) {
        for (int j = 1; j <= arr_sum; j++) {
            if (arr[i - 1] <= j) { // <-- fix here
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // Collect valid subset sums from last row
    vector<int> partial_arr;
    for (int i = 0; i <= arr_sum / 2; i++) {  
        if (t[arr_size][i] == 1) {
            partial_arr.push_back(i);
        }
    }

    // Print partial arr for debug
    cout << "Possible subset sums: ";
    for (int val : partial_arr) {
        cout << val << " ";
    }
    cout << endl;

    // Find minimum difference
    int mn = INT_MAX;
   for (int i = 0; i < partial_arr.size(); i++) {
    int s = partial_arr[i];
    int diff = arr_sum - 2 * s;
    if (diff < mn) {
        mn = diff;
    }
}
  return mn;
}

int main()
{
    int arr[3] = {1, 2, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr_sum = accumulate(arr, arr + arr_size, 0);  // STL shortcut

    cout << "Minimum Subset Sum Difference = "
         << min_sub_diff(arr, arr_size, arr_sum) << endl;

    return 0;
}

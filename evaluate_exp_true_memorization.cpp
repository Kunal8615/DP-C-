#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> t;

int solve(string str, int i, int j, bool istrue) {
    if (i > j) return 0;

    // if(t[i][j][istrue] != -1){
    //     return t[i][j][istrue];  
    // }
//key formation
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));

    //////////

    if(t.find(temp)!= t.end()){
        return t[temp];
    }
    if (i == j) {  
        if (istrue) return str[i] == 'T';
        else return str[i] == 'F';
    }

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        int LT = solve(str, i, k - 1, true);
        int LF = solve(str, i, k - 1, false);
        int RT = solve(str, k + 1, j, true);
        int RF = solve(str, k + 1, j, false);
 
        if (str[k] == '&') {
            if (istrue) ans += LT * RT;
            else ans += LT * RF + LF * RT + LF * RF;
        }
        else if (str[k] == '|') {
            if (istrue) ans += LT * RT + LT * RF + LF * RT;
            else ans += LF * RF;
        }
        else if (str[k] == '^') {
            if (istrue) ans += LT * RF + LF * RT;
            else ans += LT * RT + LF * RF;
        }
    }
    return t[temp] = ans;
}

int main() {
    string str = "T|F&T";
    t.clear(); //clear map
    int i = 0, j = str.size() - 1;
    cout << solve(str, i, j, true) << endl;
    return 0;
}
   
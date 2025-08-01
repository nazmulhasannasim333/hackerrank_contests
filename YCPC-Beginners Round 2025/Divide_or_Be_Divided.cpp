#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int digitx = s[x - 1] - '0';
    int digity = s[y - 1] - '0';

    if ((digitx != 0 && digity % digitx == 0) || (digity != 0 && digitx % digity == 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
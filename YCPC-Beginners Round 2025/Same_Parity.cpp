#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        int pos_odd = (n + 1) / 2;
        int pos_even = n / 2;

        if ((odd == pos_odd && even == pos_even) || (odd == pos_even && even == pos_odd))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
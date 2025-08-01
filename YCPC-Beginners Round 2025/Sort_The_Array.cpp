#include<bits/stdc++.h>
using namespace std;

int sortArray(const vector<int> &a)
{
    int count = 0;
    for (size_t i = 1; i < a.size(); ++i)
    {
        if (a[i - 1] == 1 && a[i] == 0)
            count++;
    }
    return count;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a)
        {
            cin >> x;
        }

        cout << sortArray(a) << endl;
    }

    return 0;
}

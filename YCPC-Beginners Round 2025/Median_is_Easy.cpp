#include <bits/stdc++.h>
using namespace std;

void median(int n, const vector<long long> &A)
{
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;

    for (int i = 0; i < n; ++i)
    {
        int modValue = A[i] % 10;

        if (low.empty() || modValue <= low.top())
        {
            low.push(modValue);
        }
        else
        {
            high.push(modValue);
        }

        if (low.size() > high.size() + 1)
        {
            high.push(low.top());
            low.pop();
        }
        else if (high.size() > low.size())
        {
            low.push(high.top());
            high.pop();
        }

        cout << low.top() << " ";
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> A(n);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        median(n, A);
    }
    return 0;
}

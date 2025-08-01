#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
    vector<int> bit;
    int n;

public:
    FenwickTree(int size)
    {
        n = size + 2;
        bit.assign(n, 0);
    }

    void update(int index, int delta)
    {
        for (; index < n; index += index & -index)
            bit[index] += delta;
    }

    int query(int index)
    {
        int result = 0;
        for (; index > 0; index -= index & -index)
            result += bit[index];
        return result;
    }

    void reset()
    {
        fill(bit.begin(), bit.end(), 0);
    }
};

void squid(const vector<long long> &a)
{
    int n = a.size();

    vector<long long> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    map<long long, int> compress;
    int id = 1;
    for (long long val : sorted_a)
    {
        if (!compress.count(val))
        {
            compress[val] = id++;
        }
    }

    vector<int> comp(n);
    for (int i = 0; i < n; ++i)
        comp[i] = compress[a[i]];

    FenwickTree leftBIT(id), rightBIT(id);
    vector<int> leftSmaller(n), rightGreater(n);

    for (int i = n - 1; i >= 0; --i)
    {
        rightGreater[i] = rightBIT.query(id - 1) - rightBIT.query(comp[i]);
        rightBIT.update(comp[i], 1);
    }

    long long result = 0;
    for (int i = 0; i < n; ++i)
    {
        leftSmaller[i] = leftBIT.query(comp[i] - 1);
        result += 1LL * leftSmaller[i] * rightGreater[i];
        leftBIT.update(comp[i], 1);
    }

    cout << result << endl;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        squid(a);
    }

    return 0;
}

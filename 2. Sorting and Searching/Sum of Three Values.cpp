#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), id(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](int i, int j)
         { return a[i - 1] < a[j - 1]; });
    sort(a.begin(), a.end());

    int i1 = -1, i2, i3;
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
        {
            int need = x - a[i] - a[j];
            auto it = lower_bound(a.begin() + i + 1, a.begin() + j, need);
            if (it != (a.begin() + j) and *it == need)
            {
                i1 = id[i], i2 = id[it - a.begin()], i3 = id[j];
                goto output;
            }
        }

    output:
    if (i1 == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << i1 << " " << i2 << " " << i3 << endl;
    return 0;
}
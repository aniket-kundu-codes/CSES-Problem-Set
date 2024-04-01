#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, h, t;
    cin >> n >> m;
    multiset<int> hn;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        hn.insert(h);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        auto it = hn.upper_bound(t);
        if (it != hn.begin())
        {
            it--;
            cout << *it << endl;
            hn.erase(it);
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
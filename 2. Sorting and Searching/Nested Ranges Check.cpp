#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n, a, b;
    cin >> n;
    set<array<int, 3>> points;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        points.insert({a, 1, i});
        points.insert({b, -a, i});
    }
    vector<bool> ans1(n, 0), ans2(n, 0);
    multiset<int> starts;
    int upto = -1;
    for (auto [x, y, id] : points)
    {
        if (y == 1)
            starts.insert(x);
        else
        {
            y = -y;
            ans1[id] = y <= upto;
            auto it = prev(starts.upper_bound(y));
            ans2[id] = it != starts.begin();
            upto = max(upto, y);
            starts.erase(it);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans1[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; i++)
        cout << ans2[i] << " \n"[i == n - 1];

    return 0;
}
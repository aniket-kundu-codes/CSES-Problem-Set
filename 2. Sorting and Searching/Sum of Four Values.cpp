#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            mp[a[i] + a[j]].push_back({i, j});

    auto collide = [&](pair<int, int> u, pair<int, int> v)
    {
        return u.first == v.first or u.first == v.second or u.second == v.first or u.second == v.second;
    };
    int i1 = -1, i2, i3, i4;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int need = x - (a[i] + a[j]);
            if (mp.find(need) != mp.end())
                for (auto &p : mp[need])
                    if (!collide({i, j}, p))
                    {
                        i1 = i, i2 = j, i3 = p.first, i4 = p.second;
                        goto output;
                    }
        }

    output:
    if (i1 == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << " " << i4 + 1 << endl;

    return 0;
}
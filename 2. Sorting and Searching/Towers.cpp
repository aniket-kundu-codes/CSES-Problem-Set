#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i].first, k[i].second = i;
    sort(k.begin(), k.end());
    set<int> s;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        auto it = s.lower_bound(k[i].second);
        if (it != s.begin())
        {
            it--;
            s.erase(it);
        }
        else
            ans++;
        s.insert(k[i].second);
    }
    cout << ans << endl;

    return 0;
}
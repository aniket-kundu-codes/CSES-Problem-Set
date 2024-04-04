#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++)
        cin >> movies[i].first >> movies[i].second;
    sort(movies.begin(), movies.end(), [&](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    multiset<int> timestamp;
    for (int i = 0; i < k; i++)
        timestamp.insert(0);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (movies[i].first >= *timestamp.begin())
            ans++, timestamp.erase(prev(timestamp.upper_bound(movies[i].first))), timestamp.insert(movies[i].second);

    cout << ans << endl;
    return 0;
}
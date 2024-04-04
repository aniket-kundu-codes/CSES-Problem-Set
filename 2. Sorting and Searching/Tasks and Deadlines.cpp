#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i].first >> s[i].second;
    sort(s.begin(), s.end());
    long long ans = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        ans += s[i].second - (time + s[i].first);
        time += s[i].first;
    }
    cout << ans << endl;
    return 0;
}
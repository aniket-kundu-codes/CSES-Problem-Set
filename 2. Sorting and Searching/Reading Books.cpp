#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());
    long long ans = accumulate(t.begin(), t.end(), 0ll);
    long long wait = t[n - 1] - (ans - t[n - 1]);
    ans += max(wait, 0ll);
    cout << ans << endl;
    return 0;
}
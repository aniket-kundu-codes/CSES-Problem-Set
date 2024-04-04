#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> psum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    long long ans = -1e9 * a;
    multiset<long long> dips;
    dips.insert(0);
    for (int i = a; i <= n; i++)
    {
        ans = max(ans, psum[i] - *dips.begin());
        if (i - b >= 0)
            dips.erase(dips.lower_bound(psum[i - b]));
        dips.insert(psum[i - a + 1]);
    }
    cout << ans << endl;
    return 0;
}
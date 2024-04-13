#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c.begin(), c.end());
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= x; j++)
            if (j - c[i] >= 0)
                dp[j] = (dp[j] + dp[j - c[i]]) % mod;
    cout << dp[x] << endl;

    return 0;
}
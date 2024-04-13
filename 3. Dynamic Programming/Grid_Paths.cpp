#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (s[n - 1][n - 1] != '*')
        dp[n - 1][n - 1] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (s[i][j] != '*')
            {
                if (i + 1 < n)
                    dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
                if (j + 1 < n)
                    dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
    cout << dp[0][0] << endl;

    return 0;
}
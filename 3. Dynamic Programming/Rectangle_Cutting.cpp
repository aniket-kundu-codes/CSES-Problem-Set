#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= max(n, m); i++)
        dp[i][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i != j)
            {
                dp[i][j] = n * m;
                for (int cut = 1; cut <= max(n, m) - 1; cut++)
                {
                    if (cut < i)
                        dp[i][j] = min(dp[i][j], 1 + dp[cut][j] + dp[i - cut][j]);
                    if (cut < j)
                        dp[i][j] = min(dp[i][j], 1 + dp[i][cut] + dp[i][j - cut]);
                }
            }
    cout << dp[n][m] << endl;
    return 0;
}
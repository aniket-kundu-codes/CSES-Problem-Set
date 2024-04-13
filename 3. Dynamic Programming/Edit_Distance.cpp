#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    // states I need : dp[i-1][j-1], dp[i-1][j], dp[i][j-1]
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = (s1[i] != s2[0]) + i;
        if (i > 0)
            dp[i][0] = min(dp[i][0], 1 + dp[i - 1][0]);
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = (s1[0] != s2[j]) + j;
        if (j > 0)
            dp[0][j] = min(dp[0][j], 1 + dp[0][j - 1]);
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = n + m;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i] != s2[j]));
            dp[i][j] = min({dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1});
        }
    cout << dp[n - 1][m - 1] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int dp[n + 1][6]; // OO OC CO CC CL OP
        for (int i = 0; i < 6; i++)
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = (0ll + dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4]) % mod;
            dp[i][1] = dp[i][0];
            dp[i][2] = dp[i][0];
            dp[i][3] = dp[i][0];
            dp[i][4] = (0ll + dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][5]) % mod;
            dp[i][5] = dp[i][4];
        }
        cout << (dp[n][3] + dp[n][4]) % mod << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    int cc = 0;
    int LIMIT = 1 << (n);
    vector<vector<int>> valid(LIMIT);
    for (int mask1 = 0; mask1 < LIMIT; mask1++)
        for (int mask2 = 0; mask2 < LIMIT; mask2++)
        {
            int consecutive = 0;
            bool can = true;
            for (int j = 0; j < n; j++)
            {
                bool has1 = mask1 & (1 << j);
                bool has2 = mask2 & (1 << j);
                if (has1 and has2)
                {
                    can = false;
                    break;
                }
                else if (has1 or has2)
                {
                    if (consecutive % 2 != 0)
                    {
                        can = false;
                        break;
                    }
                    consecutive = 0;
                }
                else
                    consecutive++;
            }
            can &= consecutive % 2 == 0;
            if (can)
                valid[mask1].push_back(mask2), cc++;
        }

    vector<vector<int>> dp(m + 1, vector<int>(LIMIT, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
        for (int mask1 = 0; mask1 < LIMIT; mask1++)
            for (auto &mask2 : valid[mask1])
                dp[i][mask1] = (dp[i][mask1] + dp[i - 1][mask2]) % mod;
    cout << dp[m][0] << endl;

    return 0;
}
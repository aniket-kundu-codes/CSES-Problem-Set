#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (num)
        {
            int digit = num % 10;
            if (digit != 0)
                dp[i] = min(dp[i], dp[i - digit]);
            num /= 10;
        }
        dp[i]++;
    }
    cout << dp[n] << endl;

    return 0;
}
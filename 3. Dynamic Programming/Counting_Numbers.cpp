#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    function<long long(long long)> solve = [&](long long x)
    {
        if (x <= 0)
            return 1 + x;
        string s = to_string(x);
        int n = s.size();
        long long dp[n][10][2][2] = {0}; // n digits, 10-digits want to put, [0-become free, 1-not free], [0-started, 1-not started]
        for (int digit = 1; digit < s[0] - '0'; digit++)
            dp[0][digit][0][0] = 1;
        dp[0][s[0] - '0'][1][0] = 1;
        dp[0][0][0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            int digit = s[i] - '0';
            for (int current_digit = 0; current_digit < 10; current_digit++)
                for (int last_digit = 0; last_digit < 10; last_digit++)
                    if (last_digit != current_digit)
                    {
                        if (current_digit < digit)
                        {
                            for (int j = 0; j < 2; j++)
                                for (int k = 0; k < 2; k++)
                                    dp[i][current_digit][0][0] += dp[i - 1][last_digit][j][k];
                        }
                        else if (current_digit == digit)
                        {
                            dp[i][current_digit][0][0] += dp[i - 1][last_digit][0][0] + dp[i - 1][last_digit][0][1];
                            dp[i][current_digit][1][0] += dp[i - 1][last_digit][1][0] + dp[i - 1][last_digit][1][1];
                        }
                        else
                            dp[i][current_digit][0][0] += dp[i - 1][last_digit][0][0] + dp[i - 1][last_digit][0][1];
                    }
                    else if (current_digit == 0)
                    {
                        dp[i][0][0][1] += dp[i - 1][0][0][1];
                    }
        }
        long long total = 0;
        for (int digit = 0; digit < 10; digit++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    total += dp[n - 1][digit][j][k];
        return total;
    };
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
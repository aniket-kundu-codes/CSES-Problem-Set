#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<bool> dp(n * 1000 + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = n * 1000; j >= x[i]; j--)
            if (dp[j - x[i]])
                dp[j] = true;
    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << endl;
    for (int i = 1; i <= n * 1000; i++)
        if (dp[i])
            cout << i << " ";
    return 0;
}
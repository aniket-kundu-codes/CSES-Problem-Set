#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n), id(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> p[i];
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j)
         { return b[i] < b[j]; });
    vector<long long> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            dp[i] = dp[i - 1];
        int low = 0, high = i - 1, mid, pt = -1;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (b[id[mid]] < a[id[i]])
                pt = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        dp[i] = max(dp[i], p[id[i]] + ((pt != -1) ? dp[pt] : 0));
    }
    cout << dp[n - 1] << endl;

    return 0;
}
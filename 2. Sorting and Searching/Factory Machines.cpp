#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    long long low = 1, high = 1e18, mid, ans, sum;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        sum = 0;
        for (int i = 0; i < n; i++)
            sum = min(0ll + t, sum + mid / k[i]);

        if (sum == t)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
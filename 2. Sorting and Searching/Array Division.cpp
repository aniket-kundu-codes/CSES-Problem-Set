#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int maxi = *max_element(x.begin(), x.end());
    long long low = maxi, high = 1ll * n * maxi, mid, ans, sum;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        int groups = 0;
        sum = 0;
        for (int i = 0; i < n; i++)
            if (sum + x[i] <= mid)
                sum += x[i];
            else
                groups++, sum = x[i];
        groups += sum > 0;

        if (groups <= k)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    cout << ans << endl;

    return 0;
}
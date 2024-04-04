#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<long long, int> cnt;
    cnt[0] = 1;
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        ans += cnt[sum - x];
        cnt[sum]++;
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (sum + a[i] % n + n) % n;
        cnt[sum]++;
    }
    long long ans = 0;
    for (auto &[ele, present] : cnt)
        ans += 1ll * present * (present - 1) / 2;
    cout << ans << endl;

    return 0;
}
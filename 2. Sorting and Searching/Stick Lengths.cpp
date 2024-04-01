#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < n / 2; i++)
        ans += a[n / 2] - a[i];
    for (int i = n / 2; i < n; i++)
        ans += a[i] - a[n / 2];
    cout << ans << endl;

    return 0;
}
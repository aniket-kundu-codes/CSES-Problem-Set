#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    long long ans = 0;
    map<int, int> cnt;
    for (int r = 0, l = 0; r < n; r++)
    {
        cnt[x[r]]++;
        while (cnt.size() > k)
        {
            cnt[x[l]]--;
            if (cnt[x[l]] == 0)
                cnt.erase(x[l]);
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;

    return 0;
}
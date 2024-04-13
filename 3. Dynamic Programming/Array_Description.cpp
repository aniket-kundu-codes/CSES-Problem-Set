#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> last(m + 2, 0);
    vector<int> curr(m + 2, 0);
    if (x[0] != 0)
        last[x[0]] = 1;
    else
        for (int i = 1; i <= m; i++)
            last[i] = 1;
    for (int i = 1; i < n; i++)
    {
        if (x[i] == 0)
        {
            for (int j = 1; j <= m; j++)
                for (int k = j - 1; k <= j + 1; k++)
                    curr[j] = (curr[j] + last[k]) % mod;
        }
        else
        {
            for (int j = x[i] - 1; j <= x[i] + 1; j++)
                curr[x[i]] = (curr[x[i]] + last[j]) % mod;
        }
        swap(last, curr);
        curr = vector<int>(m + 2, 0);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + last[i]) % mod;
    cout << ans << endl;
    return 0;
}
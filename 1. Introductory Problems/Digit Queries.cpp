#include <bits/stdc++.h>
using namespace std;
int main()
{

    int q;
    cin >> q;
    while (q--)
    {
        long long k, pos = 0, grp = 9, d = 1, n;
        cin >> k;
        while (pos + grp * d < k)
        {
            pos += grp * d;
            grp *= 10;
            d++;
        }
        k -= pos + 1;
        n = grp / 9 + k / d;
        string num = to_string(n);
        cout << num[k % d] << endl;
    }
    return 0;
}
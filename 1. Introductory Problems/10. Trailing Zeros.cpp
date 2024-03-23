#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p5 = 5;
    int ans = 0;
    while (p5 <= n)
    {
        ans += n / p5;
        p5 *= 5;
    }
    cout << ans << endl;
    return 0;
}
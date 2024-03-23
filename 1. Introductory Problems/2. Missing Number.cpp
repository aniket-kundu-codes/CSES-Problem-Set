#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        sum += x;
    }
    cout << (1ll * n * (n + 1) / 2 - sum) << endl;
    return 0;
}
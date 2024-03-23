#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int y, x;
        long long val, sign;
        cin >> y >> x;
        if (y > x)
        {
            if (y & 1)
                y--, sign = 1;
            else
                sign = -1, x--;
            val = 1ll * y * y;
            val += sign * x;
        }
        else
        {
            if (x % 2 == 0)
                x--, sign = 1;
            else
                sign = -1, y--;
            val = 1ll * x * x;
            val += sign * y;
        }
        cout << val << endl;
    }
    return 0;
}
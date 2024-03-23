#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        bool can = false;
        if ((a + b) % 3 == 0)
        {
            if (a > b)
                swap(a, b);
            if (b <= 2 * a)
                can = true;
        }
        cout<<(can?"YES":"NO")<<endl;
    }
    return 0;
}
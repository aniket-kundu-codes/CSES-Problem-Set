#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long sum = 1ll * n * (n + 1) / 2;
    if (sum & 1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        sum >>= 1;
        vector<int> s1, s2;
        for (int i = n; i >= 1; i--)
            if (sum <= i)
            {
                s1.push_back(sum);
                for (int j = 1; j <= i; j++)
                    if (j != sum)
                        s2.push_back(j);
                break;
            }
            else
                s1.push_back(i), sum -= i;
        cout << s1.size() << endl;
        for (auto &i : s1)
            cout << i << " ";
        cout << endl
             << s2.size() << endl;
        for (auto &i : s2)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
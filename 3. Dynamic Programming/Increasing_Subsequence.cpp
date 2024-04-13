#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<int> lis;
    for (auto &ele : x)
    {
        auto it = lower_bound(lis.begin(), lis.end(), ele);
        if (it == lis.end())
            lis.push_back(ele);
        else
            *it = ele;
    }
    cout << lis.size() << endl;

    return 0;
}
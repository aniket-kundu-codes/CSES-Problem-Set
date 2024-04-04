#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    long long sum1 = 0, sum2 = 0;
    multiset<int> s1, s2;
    for (int i = 0; i < k; i++)
        sum1 += x[i], s1.insert(x[i]);
    int median_size = (k + 1) / 2;
    while (s1.size() > median_size)
    {
        auto it = prev(s1.end());
        sum2 += *it;
        sum1 -= *it;
        s2.insert(*it);
        s1.erase(it);
    }

    auto calculate = [&]()
    {
        return 1ll * int(s1.size()) * (*prev(s1.end())) - sum1 + sum2 - 1ll * int(s2.size()) * (*prev(s1.end()));
    };
    auto remove = [&](int ele)
    {
        if (s1.find(ele) != s1.end())
            s1.erase(s1.lower_bound(ele)), sum1 -= ele;
        else
            s2.erase(s2.lower_bound(ele)), sum2 -= ele;
    };
    auto add = [&](int ele)
    {
        if (s1.size() == 0 or *prev(s1.end()) <= ele)
            s2.insert(ele), sum2 += ele;
        else
            s1.insert(ele), sum1 += ele;
    };
    auto adjust = [&]()
    {
        if (s1.size() < median_size)
        {
            auto it = s2.begin();
            s1.insert(*it);
            sum1 += *it;
            sum2 -= *it;
            s2.erase(it);
        }
        else if (s1.size() > median_size)
        {
            auto it = prev(s1.end());
            s2.insert(*it);
            sum2 += *it;
            sum1 -= *it;
            s1.erase(it);
        }
    };

    cout << calculate() << " ";
    for (int i = k; i < n; i++)
    {
        remove(x[i - k]);
        add(x[i]);
        adjust();
        cout << calculate() << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    int upto = 1 << n;
    vector<vector<int>> nums(n + 1);
    for (int mask = 0; mask < upto; mask++)
    {
        int bit_count = __builtin_popcount(mask);
        nums[bit_count].push_back(mask);
    }
    vector<pair<int, int>> ans(upto, {n, 0}); // {minimum_groups,minimum_occupied}
    ans[0] = {0, x};
    for (int no_of_people = 1; no_of_people <= n; no_of_people++)
        for (auto &mask : nums[no_of_people])
            for (int j = 0; j < n; j++)
                if (mask & (1 << j))
                {
                    // this person was added last
                    int weight = w[j];
                    int others = mask ^ (1 << j);
                    if (ans[others].second + weight <= x)
                        ans[mask] = min(ans[mask], {ans[others].first, ans[others].second + weight});
                    else
                        ans[mask] = min(ans[mask], {ans[others].first + 1, min(ans[others].second, weight)});
                }
    cout << ans[upto - 1].first << endl;

    return 0;
}
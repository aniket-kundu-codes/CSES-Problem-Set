#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ans;

    function<void(int, int, int, int)> transfer = [&](int initial, int target, int helper, int total_piles)
    {
        if (total_piles == 0)
            return;
        transfer(initial, helper, target, total_piles - 1);
        ans.push_back({initial, target});
        transfer(helper, target, initial, total_piles - 1);
    };
    transfer(1, 3, 2, n);
    cout << ans.size() << endl;
    for (auto &i : ans)
        cout << i.first << " " << i.second << endl;
    return 0;
}
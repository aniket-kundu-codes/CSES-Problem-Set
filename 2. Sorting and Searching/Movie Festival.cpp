#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    cin >> n;
    multiset<pair<int, int>> movies;
    multiset<int> ending;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        movies.insert({a, b});
        ending.insert({b});
    }
    int ans = 0;
    while (!movies.empty())
    {
        ans++;
        int choose = *ending.begin();
        while (movies.size() and movies.begin()->first < choose)
        {
            ending.erase(ending.find(movies.begin()->second));
            movies.erase(movies.begin());
        }
    }
    cout << ans << endl;
    return 0;
}
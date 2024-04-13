#include <bits/stdc++.h>
using namespace std;
long long minimize[5000][5000];
long long maximize[5000][5000];
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
        {
            maximize[i][j] = max(a[i] + minimize[i + 1][j], a[j] + minimize[i][j - 1]);
            minimize[i][j] = min(maximize[i + 1][j], maximize[i][j - 1]);
        }
    cout << maximize[0][n - 1] << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int lim = 1 << n;
    char graycode[lim][n];
    for (int i = 0; i < n; i++)
    {
        int grp = 1 << (i + 2);
        for (int j = 0; j < lim; j++)
        {
            int id = j % grp;
            if (id >= grp / 4 and id < grp / 4 * 3)
                graycode[j][i] = '1';
            else
                graycode[j][i] = '0';
        }
    }
    for (int i = 0; i < lim; i++)
    {
        for (int j = 0; j < n; j++)
            cout << graycode[i][j];
        cout << endl;
    }

    return 0;
}
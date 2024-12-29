
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, a;
        cin >> h >> a;

        int ans = 0;

        while (h > 0 && a > 0)
        {
            h += 3;
            a += 2;
            ans++;

            if (a <= 10)
            {
                h -= 20;
                a += 5;
            }
            else
            {
                h -= 5;
                a -= 10;
            }
            if (h > 0 && a > 0)
                ans++;
        }
        cout << ans << endl;
    }
}

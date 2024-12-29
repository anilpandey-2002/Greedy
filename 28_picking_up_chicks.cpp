
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    long long int t, j;
    cin >> t;
    for (j = 1; j <= t; ++j)
    {
        long long int n, k, b, time;
        cin >> n >> k >> b >> time;

        long long int x[n], v[n], i;
        for (i = 0; i < n; ++i)
            cin >> x[i];

        for (i = 0; i < n; ++i)
            cin >> v[i];

        int count = 0, swaps = 0, penalty = 0;
        for (i = n - 1; i >= 0; --i)
        {
            int distance_needed = b - x[i];
            int distance_possible = v[i] * time;

            if (distance_possible >= distance_needed)
            {
                count++;
                swaps += penalty;
            }
            else
                penalty++;

            if (count >= k)
                break;
        }

        if (count >= k)
            cout << "Case #" << j << ": " << swaps << endl;

        else
            cout << "Case #" << j << ": " << "IMPOSSIBLE" << endl;
    }
    return 0;
}

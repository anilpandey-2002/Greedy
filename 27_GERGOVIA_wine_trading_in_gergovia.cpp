
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;

        long long int a[n];
        for (long long int i = 0; i < n; i++)
            cin >> a[i];

        vector<pair<long long int, long long int>> sell, buy;

        for (long long int i = 0; i < n; i++)
        {
            if (a[i] > 0)
                buy.push_back({a[i], i});
            else
                sell.push_back({a[i], i});
        }

        long long int currBuyer = 0, currSeller = 0;
        long long int ans = 0;

        while (currBuyer < buy.size() && currSeller < sell.size())
        {
            long long int x = min(buy[currBuyer].first, -sell[currSeller].first);

            buy[currBuyer].first -= x;
            sell[currSeller].first += x;

            long long int times = abs(buy[currBuyer].second - sell[currSeller].second);

            ans += (times * x);

            if (buy[currBuyer].first == 0)
                currBuyer++;
            if (sell[currSeller].first == 0)
                currSeller++;
        }

        cout << ans << endl;
    }
    return 0;
}

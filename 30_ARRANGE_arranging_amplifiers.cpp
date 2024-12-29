
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int one = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
                one++;
            else
                v.push_back(x);
        }

        sort(v.begin(), v.end(), greater<>());

        for (int i = 0; i < one; i++)
            cout << 1 << " ";

        if (n - one == 2 && v[0] == 3 && v[1] == 2)
        {
            cout << "2 3" << endl;
        }
        else
        {
            for (auto i : v)
                cout << i << " ";
            cout << endl;
        }
    }
}
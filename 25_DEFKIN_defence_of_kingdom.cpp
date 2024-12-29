
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int width, height, points;
        cin >> width >> height >> points;
        vector<int> xCorr;
        vector<int> yCorr;

        xCorr.push_back(0);
        yCorr.push_back(0);

        for (int i = 0; i < points; i++)
        {
            int x, y;
            cin >> x >> y;
            xCorr.push_back(x);
            yCorr.push_back(y);
        }

        xCorr.push_back(width + 1);
        yCorr.push_back(height + 1);

        sort(xCorr.begin(), xCorr.end());
        sort(yCorr.begin(), yCorr.end());

        int mx = 0, my = 0;
        for (int i = 0; i < xCorr.size() - 1; i++)
        {

            mx = max(mx, xCorr[i + 1] - xCorr[i] - 1);

            my = max(my, yCorr[i + 1] - yCorr[i] - 1);
        }
        cout << mx * my << endl;
    }

    return 0;
}

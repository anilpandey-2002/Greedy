
bool static compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, compare);
        int a[n + 1];
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            for (int j = min(arr[i].dead, n); j > 0; j--)
            {
                if (a[j] == 0)
                {
                    a[j] = arr[i].profit;
                    break;
                }
            }
        }
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
            {
                cnt++;
                ans += a[i];
            }
        }
        return {cnt, ans};
    }
};

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
	if (a[1] == b[1])
	{
		if (a[2] == b[2])
		{
			return a[0] < b[0];
		}
		else
		{
			return a[2] < b[2];
		}
	}
	return a[1] < b[1];
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> v(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	vector<int> ans;

	sort(v.begin(), v.end(), comp);

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

	pq.push({v[0][2], v[0][1], v[0][0]});

	int i = 1, current_time = 0;

	while (!pq.empty())
	{
		int burst_time = pq.top()[0];
		int id = pq.top()[2];
		pq.pop();

		ans.push_back(id);
		current_time += burst_time;

		while (true)
		{
			if (i < n && v[i][1] <= current_time)
			{
				pq.push({v[i][2], v[i][1], v[i][0]});
				i++;
			}
			else
				break;
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}
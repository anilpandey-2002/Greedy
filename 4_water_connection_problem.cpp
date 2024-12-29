int n, p;
int rd[1100], wt[1100], cd[1100];
vector<vector<int>> ans;
int mn;

int dfs(int w)
{
	if (cd[w] == 0)
		return w;
	if (wt[w] < mn)
		mn = wt[w];
	return dfs(cd[w]);
}

vector<vector<int>> solve(int arr[][3])
{
	for (int i = 0; i < p; i++)
	{
		int q = arr[i][0], h = arr[i][1], t = arr[i][2];
		cd[q] = h, wt[q] = t, rd[h] = q;
	}
	ans.clear();
	for (int j = 1; j <= n; ++j)
	{
		if (rd[j] == 0 && cd[j])
		{
			mn = 1e9;
			int w = dfs(j);
			ans.push_back({j, w, mn});
		}
	}
	return ans;
}

vector<vector<int>> solve(int mainN, int mainP, vector<int> a, vector<int> b, vector<int> d)
{
	n = mainN, p = mainP;
	memset(rd, 0, sizeof(rd));
	memset(cd, 0, sizeof(cd));
	memset(wt, 0, sizeof(wt));
	int arr[p][3];
	for (int i = 0; i < p; i++)
		arr[i][0] = a[i], arr[i][1] = b[i], arr[i][2] = d[i];
	return solve(arr);
}

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
	vector<vector<int>> ans;
	map<int, pair<int, int>> m;
	for (int i = 0; i < p; i++)
		m[a[i]] = {b[i], d[i]};
	for (int i = 0; i < p; i++)
	{
		if (m.count(m[a[i]].first) <= 0)
			continue;
		int curr = m[a[i]].first;
		while (m.count(curr) > 0)
		{
			m[a[i]].first = m[curr].first;
			m[a[i]].second = min(m[a[i]].second, m[curr].second);
			m[curr].second = INT_MAX;
			curr = m[curr].first;
		}
	}
	for (auto i : m)
	{
		if (i.second.second != INT_MAX)
			ans.push_back({i.first, i.second.first, i.second.second});
	}
	return ans;
}


int minCost(int arr[], int n)
{

	priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);

	int res = 0;

	while (pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		res += first + second;
		pq.push(first + second);
	}

	return res;
}
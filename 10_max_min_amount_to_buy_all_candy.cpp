
vector<int> candyStore(int candies[], int N, int K)
{
	sort(candies, candies + N);

	// get index for
	int total_idx = N / (K + 1);
	if (N % (K + 1))
		total_idx++;

	total_idx = min(total_idx, N);

	int mn = 0, mx = 0;

	for (int i = 0; i < total_idx; i++)
	{
		mn += candies[i];
	}
	for (int i = N - 1; i >= N - total_idx; i--)
	{
		mx += candies[i];
	}

	return {mn, mx};
}
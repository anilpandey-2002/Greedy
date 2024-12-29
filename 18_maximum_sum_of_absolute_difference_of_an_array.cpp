
int MaxSumDifference(int a[], int n)
{
	sort(a, a + n);

	int ans = 0;

	for (int i = 0; i < n / 2; i++)
	{
		int diff = abs(a[i] - a[n - 1 - i]);

		ans += diff * 2;
	}
	return ans;
}

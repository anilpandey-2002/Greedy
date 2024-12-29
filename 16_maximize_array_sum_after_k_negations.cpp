
typedef long long int ll;
long long int maximizeSum(long long int a[], int n, int k)
{
	sort(a, a + n);
	ll sum = 0, i;
	for (i = 0; i < n; i++)
	{
		if (a[i] < 0 and k > 0)
		{
			a[i] *= -1;
			k--;
		}
	}

	sort(a, a + n);
	for (i = 0; i < n; i++)
		sum += a[i];

	if (k & 1)
		sum -= 2 * a[0];

	return sum;
}
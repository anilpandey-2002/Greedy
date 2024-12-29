
long long int maxSum(int arr[], int n)
{
	long long int sum = 0;
	sort(arr, arr + n);
	for (int i = 0; i < n / 2; i++)
	{
		sum -= (2 * arr[i]);
		sum += (2 * arr[n - i - 1]);
	}
	return sum;
}

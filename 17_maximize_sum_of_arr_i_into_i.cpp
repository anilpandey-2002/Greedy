
const long long int mod = (int)1e9 + 7;
int Maximize(int a[], int n)
{
	long long int pro = 0;
	sort(a, a + n);
	for (int i = 1; i < n; i++)
	{
		pro += (i * (a[i] % mod)) % mod;
		pro = pro % mod;
	}
	return pro;
}
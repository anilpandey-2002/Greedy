#include <algorithm>
#include <iostream>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
	sort(arr, arr + n);
	sort(dep, dep + n);
	int plat_needed = 1, result = 1, i = 1, j = 0;
	while (i < n && j < n)
	{
		if (arr[i] <= dep[j])
		{
			plat_needed++;
			i++;
		}
		else
		{
			plat_needed--;
			j++;
		}
		result = max(result, plat_needed);
	}
	return result;
}

int main()
{
	int arr[] = {900, 940, 950, 1100, 1500, 1800};
	int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = " << findPlatform(arr, dep, n);
	return 0;
}

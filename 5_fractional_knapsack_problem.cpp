#include <bits/stdc++.h>
using namespace std;

struct Item
{
	int value, weight;
	Item(int value, int weight) : value(value), weight(weight) {}
};

bool cmp(Item a, Item b)
{
	return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
	sort(arr, arr + n, cmp);
	int curWeight = 0;
	double finalvalue = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (curWeight + arr[i].weight <= W)
		{
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}
		else
		{
			finalvalue += arr[i].value * (double)(W - curWeight) / arr[i].weight;
			break;
		}
	}
	return finalvalue;
}

int main()
{
	int W = 50;
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
	return 0;
}

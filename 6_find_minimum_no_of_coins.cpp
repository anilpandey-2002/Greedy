#include <iostream>
using namespace std;

#define MAX 26

string smallestStr(string str, int n)
{
	int chk[MAX];
	fill(chk, chk + MAX, -1);

	for (int i = 0; i < n; i++)
		if (chk[str[i] - 'a'] == -1)
			chk[str[i] - 'a'] = i;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < str[i] - 'a'; j++)
		{
			if (chk[j] > chk[str[i] - 'a'])
			{
				char ch1 = str[i], ch2 = char(j + 'a');
				for (int k = 0; k < n; k++)
				{
					if (str[k] == ch1)
						str[k] = ch2;
					else if (str[k] == ch2)
						str[k] = ch1;
				}
				return str;
			}
		}
	}
	return str;
}

int main()
{
	string str = "ccad";
	cout << smallestStr(str, str.length());
	return 0;
}

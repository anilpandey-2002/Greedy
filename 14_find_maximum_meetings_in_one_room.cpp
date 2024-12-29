#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
	int start;
	int end;
	int pos;
};

bool comparator(Meeting m1, Meeting m2)
{
	return m1.end < m2.end;
}

void maxMeeting(int start[], int end[], int n)
{
	vector<Meeting> meetings(n);

	for (int i = 0; i < n; i++)
	{
		meetings[i] = {start[i], end[i], i + 1};
	}

	sort(meetings.begin(), meetings.end(), comparator);

	vector<int> selectedMeetings;

	selectedMeetings.push_back(meetings[0].pos);
	int lastEndTime = meetings[0].end;

	for (int i = 1; i < n; i++)
	{
		if (meetings[i].start >= lastEndTime)
		{
			selectedMeetings.push_back(meetings[i].pos);
			lastEndTime = meetings[i].end;
		}
	}

	for (int meeting : selectedMeetings)
	{
		cout << meeting << " ";
	}
}

int main()
{
	int start[] = {1, 3, 0, 5, 8, 5};
	int end[] = {2, 4, 6, 7, 9, 9};
	int n = sizeof(start) / sizeof(start[0]);

	maxMeeting(start, end, n);
	return 0;
}

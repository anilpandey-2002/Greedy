
bool static compare(pair<int, int> meeting1, pair<int, int> meeting2)
{
    if (meeting1.second == meeting2.second)
        return meeting1.first < meeting2.first;
    return meeting1.second < meeting2.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> timeTable(n);
    for (int i = 0; i < n; i++)
    {
        timeTable[i] = {start[i], end[i]};
    }

    sort(timeTable.begin(), timeTable.end(), compare);

    int temp = INT_MIN;
    int meetings = 0;
    for (pair<int, int> p : timeTable)
    {
        if (p.first > temp)
        {
            temp = p.second;
            meetings++;
        }
    }
    return meetings;
}

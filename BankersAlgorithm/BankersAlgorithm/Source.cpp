#include <iostream>
using namespace std;

bool isSafe(int p, bool arr[])
{
	for (int i = 0; i < p; i++)
		if (!arr[i])
			return false;
	return true;
}

int main()
{
	int num_r, num_p, p[100], total_r[100], av_r[100], current_allocation[100][100], max_request[100][100], remaining[100][100];
	bool done[100], enter = true;
	memset(done, false, sizeof(done));

	cout << "Number of resources: ";
	cin >> num_r;

	cout << "Number of processes: ";
	cin >> num_p;

	cout << "Enter Total resources (eg 1 2 3 4)\n";
	for (int i = 0; i < num_r; i++)
		cin >> total_r[i];

	cout << "Enter available resources (eg 1 2 3 4)\n";
	for (int i = 0; i < num_r; i++)
		cin >> av_r[i];

	cout << "Enter current allocation (eg P0: 1 2 3 4)\n";
	for (int i = 0; i < num_p; i++)
	{
		cout << "P" << i << ": ";
		for (int j = 0; j < num_r; j++)
			cin >> current_allocation[j][i];
	}

	cout << "Enter maximum request (eg P0: 1 2 3 4)\n";
	for (int i = 0; i < num_p; i++)
	{
		cout << "P" << i << ": ";
		for (int j = 0; j < num_r; j++)
			cin >> max_request[j][i];
	}

	for (int i = 0; i < num_p; i++)
		for (int j = 0; j < num_r; j++)
			remaining[j][i] = max_request[j][i] - current_allocation[j][i];
	
	cout << endl;
	while(enter)
	{
		enter = false;
		for (int i = num_p-1; i >=0; i--)
			if (!done[i])
			{
				bool flag = true;
				for (int j = 0; j < num_r; j++)
					if (remaining[j][i] > av_r[j])
					{
						flag = false;
						break;
					}
				if (flag)
				{
					for (int j = 0; j < num_r; j++)
						av_r[j] += current_allocation[j][i];
					done[i] = true;
					cout << "P" << i << " is done\n";
					enter = true;
				}
			}
	}
	cout << endl;
	if (isSafe(num_p, done))
		cout << "The program is safe\n";
	else
		cout << "The program is unsafe\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

bool comparator(vector<int> a, vector <int> b) {
	return a[5] < b[5];
}

bool comparator2(vector<int> a, vector <int> b) {
	return a[0] < b[0];
}

class Solution {
public:

	int n;
	float totalCt = 0;
	float totalWt = 0;
	float totalTat = 0;

	Solution(int n) {
		this->n = n;
	}

	void getData(vector<vector<int>> &v) {
		for (int i = 0; i < n; ++i)
		{

			int x;
			cout << "Enter AT of process " << i + 1 << " : ";
			cin >> x;
			v[i][0] = i;
			v[i][1] = x;
			cout << "Enter BT of process " << i + 1 << " : ";
			cin >> x;
			v[i][2] = x;
			v[i][4] = x;
			cout << "Enter Priority of process " << i + 1 << " : ";
			cin >> x;
			v[i][5] = x;
		}
	}

	void display(vector<vector<int>>v) {
		sort(v.begin(), v.end(), comparator2);

		cout << endl << endl;

		cout << "---------------------------------------------------------------------------------------------------------" << endl;
		cout << "|PID\t|" << "Arrival\t|" << "Burst\t\t|" << "Priority\t|" << "Completion\t|" << "TurnAround\t|" << "Waiting\t|" << endl;
		cout << "---------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < n; ++i)
		{
			int tat = (v[i][3] - v[i][1]);
			totalTat += tat;
			int wt = tat - v[i][2];
			totalWt += wt;
			cout << "|" << v[i][0] << "\t|" << v[i][1] << "\t\t|" << v[i][2] << "\t\t|" << v[i][5] << "\t\t|" << v[i][3] << "\t\t|" << tat << "\t\t|" << wt << "\t\t|" << endl;
		}

		cout << "---------------------------------------------------------------------------------------------------------" << endl;

		cout << "\n\nRESULT: " << endl << endl;
		cout << "The average Weighting Time is " << totalWt / n << " units" << endl << endl;
		cout << "The average Turn Around Time is " << totalTat / n << " units" << endl << endl;
		cout << "The average Completion Time is " << totalCt / n << " units" << endl << endl;
	}

	void Priority(vector<vector<int>> &v) {
		sort(v.begin(), v.end(), comparator);

		int t = 0;

		for (int i = 0; i < n; ++i)
		{
			int itr = -1;
			bool flag = true;
			int at = INT_MAX;
			for (int j = 0; j < n; ++j)
			{
				if (v[j][4] == 1) continue;

				if (v[j][1] < at) {
					at = v[j][1];
					itr = j;
				}

				if (v[j][1] <= t) {
					itr = j;
					flag = false;
					break;
				}
			}

			if (flag == true) {
				t += (at - t);
			}

			t += v[itr][2];
			v[itr][3] = t;
			v[itr][4] = 1;
		}

		totalCt = t;
	}

};

int main() {
	int n;
	cout << "Enter the number of processes: ";
	cin >> n;
	cout << endl;

	Solution f(n);

	vector<vector<int>> v(n, vector<int>(6, 0));

	f.getData(v);

	f.Priority(v);

	f.display(v);

	return 0;
}
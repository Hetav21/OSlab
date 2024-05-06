#include <bits/stdc++.h>
using namespace std;
bool comparator(vector<int> a, vector <int> b) {
	return a[0] < b[0];
}
class Solution {
public:
	int n = 0;
	Solution(int n) {
		this->n = n;
	}

	void getData(vector<vector<int>> &v) {
		for (int i = 0; i < n; ++i)
		{
			vector <int> temp;
			cout << "Enter Arrival Time of Process " << i + 1 << " : ";
			int x = 0;
			cin >> x;
			temp.push_back(x);
			cout << endl;
			cout << "Enter Burst Time of Process " << i + 1 << " : ";
			int y = 0;
			cin >> y;
			temp.push_back(y);
			cout << endl;
			v.push_back(temp);
		}
	}

	vector<int> findWt(vector<int> tat, float &t, vector<vector<int>> &v) {
		vector <int> ans(n, 0);
		for (int i = 0; i < n; ++i) {
			ans[i] = tat[i] - v[i][1];
			t += ans[i];
		}
		return ans;
	}

	vector<int> findTat(vector<int> ct, float &t, vector<vector<int>> &v) {
		vector <int> ans(n, 0);
		for (int i = 0; i < n; ++i) {
			ans[i] = ct[i] - v[i][0];
			t += ans[i];
		}
		return ans;
	}

	vector<int> findCt(float &t, vector<vector<int>> &v) {
		vector <int> ans(n, 0);
		ans[0] = v[0][0] + v[0][1];
		for (int i = 1; i < n; ++i)
		{
			ans[i] = ans[i - 1] + v[i][1];
			if (v[i][0] > ans[i - 1]) {
				ans[i] += (v[i][0] - ans[i - 1]);
			}
		}
		t = ans[n - 1];
		return ans;
	}

	void FCFS(vector < vector<int> > v) {
		sort(v.begin(), v.end(), comparator);

		float totalWt = 0;
		float totalTat = 0;
		float totalCt = 0;

		vector <int> ct = findCt(totalCt, v);
		vector <int> tat = findTat(ct, totalTat, v);
		vector <int> wt = findWt(tat, totalWt, v);

		cout << endl << endl;

		cout << "---------------------------------------------------------------------------------" << endl;
		cout << "|PID\t|" << "Arrival\t|" << "Burst\t|" << "Completion\t|" << "TurnAround\t|" << "Waiting\t|" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < n; ++i)
		{
			cout << "|" << i + 1 << "\t|" << v[i][0] << "\t\t|" << v[i][1] << "\t|" << ct[i] << "\t\t|" << tat[i] << "\t\t|" << wt[i] << "\t\t|" << endl;
		}

		cout << "---------------------------------------------------------------------------------" << endl;

		cout << "\n\nRESULT: " << endl << endl;
		cout << "The average Waiting Time is " << totalWt / n << " units" << endl << endl;
		cout << "The average Turn Around Time is " << totalTat / n << " units" << endl << endl;
		cout << "The average Completion Time is " << totalCt / n << " units" << endl << endl;
	}
};

int main() {
	int n;
	cout << "Enter the number of processes: ";
	cin >> n;
	cout << endl;
	vector <vector<int>> v;
	Solution f(n);
	f.getData(v);
	f.FCFS(v);
	return 0;
}
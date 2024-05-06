#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

bool comparator(vector<int> a, vector <int> b) {
	return a[1] < b[1];
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

		}
	}

	void RR(vector<vector<int>> &v) {
		int qt;
		cout << endl;
		cout << "Enter the quantum time: ";
		cin >> qt;
		cout << endl;

		int cs = 0;
		cout << "Enter the context switch: ";
		cin >> cs;
		cout << endl;

		sort(v.begin(), v.end(), comparator);

		int cnt = 0;
		queue <int> q;
		int i = 0;
		q.push(i);
		int t = v[i][1];

		while (q.size() > 0) {
			i = q.front();
			q.pop();
			bool flag = true;
			if (v[i][4] - qt > 0) {
				t += qt;
				v[i][4] -= qt;
			}
			else {
				t += v[i][4];
				v[i][3] = t;
				v[i][4] = 0;
				flag = false;
			}

			while (cnt + 1 < n && (v[cnt + 1][1] <= t)) {
				q.push(++cnt);
			}

			t += cs;

			if (flag == true) q.push(i);

			while (cnt + 1 < n && v[cnt + 1][1] <= t) {
				q.push(++cnt);
			}
		}

		v[i][3] -= cs;
		totalCt = v[i - 1][3];
	}

	void display(vector<vector<int>>v) {
		sort(v.begin(), v.end(), comparator2);

		cout << endl << endl;

		cout << "---------------------------------------------------------------------------------" << endl;
		cout << "|PID\t|" << "Arrival\t|" << "Burst\t|" << "Completion\t|" << "TurnAround\t|" << "Waiting\t|" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < n; ++i)
		{
			int tat = (v[i][3] - v[i][1]);
			totalTat += tat;
			int wt = tat - v[i][2];
			totalWt += wt;
			cout << "|" << v[i][0] << "\t|" << v[i][1] << "\t\t|" << v[i][2] << "\t|" << v[i][3] << "\t\t|" << tat << "\t\t|" << wt << "\t\t|" << endl;
		}

		cout << "---------------------------------------------------------------------------------" << endl;

		cout << "\n\nRESULT: " << endl << endl;
		cout << "The average Waiting Time is " << totalWt / n << " units" << endl << endl;
		cout << "The average Turn Around Time is " << totalTat / n << " units" << endl << endl;
		cout << "The average Completion Time is " << totalCt / n << " units" << endl << endl;
	}
};

int main() {
// #ifndef ONLINE_JUDGE
//   	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cout << "Enter the number of processes: ";
	cin >> n;
	cout << endl;

	Solution f(n);

	vector<vector<int>> v(n, vector<int>(5, 0));

	f.getData(v);

	f.RR(v);

	f.display(v);

	return 0;
}

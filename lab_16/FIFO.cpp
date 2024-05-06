#include <bits/stdc++.h>
using namespace std;

#pragma LLVM optimize("Os")
#pragma LLVM optimize("Ofast")
#pragma LLVM target("avx,avx2,fma")

class Solution {
public:

	int f;
	int n;
	int pageFault = 0;
	int pageHit = 0;
	queue <int> q;
	vector<int> v;

	Solution(int n, int f) {
		this->n = n;
		this->f = f;
	}

	void ratio() {
		cout << endl << endl;

		cout << "Page Hit = " << pageHit << endl;
		cout << "Page Fault = " << pageFault << endl;;
		cout << "Hit Ratio = " << (float)(pageHit) / (float)(pageHit + pageFault) << endl;
		cout << "Fault Ratio = " << (float)(pageFault) / (float)(pageHit + pageFault) << endl;
	}

	void getData() {
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
	}

	void print_queue(std::queue<int> q)
	{
		while (!q.empty())
		{
			std::cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	void FIFO() {

		while (q.size() <= f) {
			int n = q.front();

		}
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int fs;
	int n;
	cin >> n;
	cin >> fs;
	Solution f(n, fs);

	f.getData();



	return 0;
}
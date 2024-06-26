#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 

	int nFrame = 0;
	int n = 0;

	Solution(int nFrame, int n) {
		this->nFrame = nFrame;
		this->n = n;
	}

	vector <int> refStrings;

	set <int> currentFrame;

	void setRefStrings(){
		for (int i = 0; i < n; ++i)
		{
			// cout << "Enter Reference String at " << i + 1 << ": ";
			int x = 0;
			cin >> x;
			refStrings.push_back(x);
		}
	}

	void getRefStrings(){
		for (auto itr : refStrings)
		{
			cout << itr << " ";
		}
		cout << endl << endl;
	}

	void FIFO(vector<vector<int>> &v, vector<int> &r){
		int itr = 0; // Iterates the First In
		int itrElement = 0;

		int i = 0;

		while(i < n){ 
			int elementFromRefString = refStrings[i];

			if(currentFrame.find(elementFromRefString) != currentFrame.end()){
				// Hit
				r[i] = true;
				for (int j = 0; j < nFrame; ++j)
				{
					v[j][i] = v[j][i - 1];
				}
			} else {
				// Fault
				if(i + 1 > nFrame) {
					itrElement = v[itr][i - 1];
					currentFrame.erase(itrElement);
				}
				currentFrame.insert(elementFromRefString);

				for (int j = 0; j < nFrame; ++j)
				{
					v[j][i] = v[j][i - 1];
					if(j == itr) v[j][i] = elementFromRefString;
				}

				itr++;
				if(itr >= nFrame) itr = 0;
			}

			i++;
		}
	}

		void display(vector<vector<int>> &v, vector<int> &r) {
		int nHit = 0;

		cout << "---------------------------------------------------" << endl;
		for (int i = 0; i < nFrame; ++i)
		{
			cout << "| f" << i + 1<< " \t";
		}
		cout << "| Page Fault |" << endl;
		cout << "---------------------------------------------------" << endl;
		for (int i = 0; i < n; ++i)
		{	
			for (int j = 0; j < nFrame; ++j)
			{
				if(i > nFrame || i >= j) cout << "| " << v[j][i] << " \t";
				else cout << "| \t\t";
			}

			if(r[i] == 1) {
				cout << "|\t HIT \t |";
				nHit++;
			} else {
				cout << "|\t  *  \t |";
			}
			cout << endl;
		}
		cout << "---------------------------------------------------" << endl;
		cout << endl << endl;

		cout << "Result: " << endl;
		cout << "Number of Page Hits:   \t" << nHit << endl;
		cout << "Number of Page Faults: \t" << (n - nHit) << endl;
		cout << "Ratio of Page Hits:    \t" << nHit << "/" << n << " = " << (float)(nHit)/(float)n << endl;
		cout << "Ratio of Page Faults:  \t" << (n - nHit) << "/" << n << " = " << (float)(n - nHit)/(float)n << endl;
	}

};	

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int nFrame;
	// cout << "Enter number of frames: ";
	cin >> nFrame;

	int n;
	// cout << "Enter the number of reference strings: ";
	cin >> n;

	Solution f(nFrame, n);

	vector <int> r(n, 0);
	// false: Fault
	// true: hit

	vector< vector<int> > v(nFrame, vector<int>(n, 0));

	f.setRefStrings();
	// f.getRefStrings();

	f.FIFO(v, r);

	f.display(v, r);

	return 0;
}

// 3
// 15
// 7
// 0
// 1 
// 2 
// 0 
// 3 
// 0 
// 4 
// 2 
// 3 
// 0 
// 3 
// 1 
// 2 
// 0

// *   	7 	
// *   	7 	0 	
// *   	7 	0 	1 	
// *   	2 	0 	1 	
// HIT 	2 	0 	1 	
// *   	2 	3 	1 	
// *   	2 	3 	0 	
// *   	4 	3 	0 	
// *   	4 	2 	0 	
// *   	4 	2 	3 	
// *   	0 	2 	3 	
// HIT 	0 	2 	3 	
// *   	0 	1 	3 	
// *   	0 	1 	2 	
// HIT 	0 	1 	2 	

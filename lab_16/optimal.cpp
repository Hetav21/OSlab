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

	void Optimal(vector<vector<int>> &v, vector<int> &r){
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
				// Fault:
				if (currentFrame.size() < nFrame) {
					currentFrame.insert(elementFromRefString);
					for (int j = 0; j < nFrame; ++j)
					{
						v[j][i] = v[j][i - 1];
					}
					v[currentFrame.size() - 1][i] = elementFromRefString;
				}

				else {	
					set <int> s = currentFrame;

					for (int j = i; j < n; ++j)
					{	
						if(s.size() == 1) break;
						int ele = refStrings[j];
						if(s.find(ele) != s.end()){
							s.erase(ele);
						}
					}

					int ele = *s.begin();
					
					currentFrame.erase(ele);
					currentFrame.insert(elementFromRefString);

					for (int j = 0; j < nFrame; ++j)
					{
						v[j][i] = v[j][i - 1];
						if(v[j][i - 1] == ele) v[j][i] = elementFromRefString;
					}
				}
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

	f.Optimal(v, r);

	f.display(v, r);

	return 0;
}


// 4
// 20
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
// 2
// 1 
// 2
// 0
// 1
// 7
// 0
// 1


// *   	7 	
// *   	7 	0 	
// *   	7 	0 	1 	
// *   	7 	0 	1 	2 	
// HIT 	7 	0 	1 	2 	
// *   	3 	0 	1 	2 	
// HIT 	3 	0 	1 	2 	
// *   	3 	0 	4 	2 	
// HIT 	3 	0 	4 	2 	
// HIT 	3 	0 	4 	2 	
// HIT 	3 	0 	4 	2 	
// HIT 	3 	0 	4 	2 	
// HIT 	3 	0 	4 	2 	
// *   	3 	0 	1 	2 	
// HIT 	3 	0 	1 	2 	
// HIT 	3 	0 	1 	2 	
// HIT 	3 	0 	1 	2 	
// *   	7 	0 	1 	2 	
// HIT 	7 	0 	1 	2 	
// HIT 	7 	0 	1 	2 	


// Number of Page Hits:   	12
// Number of Page Faults: 	8
// Ratio of Page Hits:    	12/20 = 0.6
// Ratio of Page Faults:  	8/20 = 0.4

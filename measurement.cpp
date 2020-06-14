/*
 * ID: your_id_here
 * PROG: sample
 * LANG: C++11
 * */
#include <algorithm>
#include <iostream>
#include <sstream> 
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool compareTwo(vector<int> arr1,vector<int> arr2) {
	return arr1[0]< arr2[0];
}

int main(int argc, char* argv[]) {
	const char* FIN = "measurement.in";
	const char* FOUT = "measurement.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int n;
	cin >> n;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	int maxx = 0;
	bool a11 = true;
	bool a22 = true;
	bool a33 = true;
	vector<vector<int>> v;
	for (int i = 0; i < n; ++i) {
		vector<int> v1;
		int d1;
		cin >> d1;
		v1.push_back(d1);
		string s;
		cin >> s;
		if (s == "Bessie") {
			v1.push_back(0);
		}
		else if (s == "Mildred") {
			v1.push_back(1);
		}
		else {
			v1.push_back(2);
		}
		string s1;
		cin >> s1;
		string s2 = s1.substr(1);
		stringstream geek(s2);
		int x = 0;
		geek >> x;
		if (s1[0] == '-') {
			v1.push_back(-x);
		}
		else {
			v1.push_back(x);
		}
		v.push_back(v1);
	}
	sort(v.begin(), v.begin()+n, compareTwo);

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		bool na1;
		bool na2;
		bool na3;
		if (v[i][1] == 0) {
			a1 += v[i][2];
		}
		else if (v[i][1] == 1) {
			a2 += v[i][2];
		}
		else {
			a3 += v[i][2];
		}
		maxx = max(a1, max(a2, a3));
		na1 = a1 >= maxx;
		na2 = a2 >= maxx;
		na3 = a3 >= maxx;

		if (maxx > a1 && maxx > a2 && maxx > a3) {
			maxx = max(a1, max(a2, a3));
			if (maxx == a1) { na1 = true; }
			if (maxx == a2) { na2 = true; }
			if (maxx == a3) { na3 = true; }
			++sum;
		}
		else if (a11 != na1 || a22 != na2 || a33 != na3) {
			++sum;
		}
		a11 = na1;
		a22 = na2;
		a33 = na3;
		
	}

	cout << sum << endl;

	// End of your soulution.
	//////////////////////////////////////

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

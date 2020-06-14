/*
 * ID: your_id_here
 * PROG: sample
 * LANG: C++11
 * */
#include <algorithm>
#include <iostream>
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

int main(int argc, char* argv[]) {
	const char* FIN = "shuffle.in";
	const char* FOUT = "shuffle.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int n;
	cin >> n;
	int rever[100];
	int id[100];
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		rever[k - 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> id[i];
	}
	for (int i = 0; i < 3; ++i) {
		int id1[100];
		for (int i = 0; i < n; ++i) {
			id1[rever[i]] = id[i];
		}
		for (int i = 0; i < n; ++i) {
			id[i] = id1[i];
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << id[i] << endl;
	}



	// End of your soulution.
	//////////////////////////////////////

	return 0;
}

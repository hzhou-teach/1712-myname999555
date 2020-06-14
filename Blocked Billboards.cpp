// Blocked Billboards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	const char* FIN = "billboard.in";
	const char* FOUT = "billboard.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream fin(inFile);
	ofstream fout(FOUT);

	//////////////////////////////////////
	// Start your solution from here...

	int ax1, ax2, ay1, ay2;
	int bx1, bx2, by1, by2;
	int cx1, cx2, cy1, cy2;
	int sum = 0;

	fin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2 >> cx1 >> cy1 >> cx2 >> cy2;

	if ((cx1 >= ax1 && cx1 <= ax2 && cy1 >= ay1 && cy1 <= ay2)) {
		sum += (min((ax2 - cx1), cx2-cx1) * min((ay2 - cy1), cy2-cy1));
	}
	else if ((cx2 >= ax1 && cx2 <= ax2 && cy2 >= ay1 && cy2 <= ay2)) {
		sum += (min((cx2 - ax1), cx2-cx1) * min((cy2 - ay1), cy2-cy1));
	}
	else if ((cx2 >= ax1 && cx2 <= ax2 && cy1 >= ay1 && cy1 <= ay2)) {
		sum += (cx2 - ax1) * (ay2 - cy1);
	}
	else if (cx1 >= ax1 && cx1 <= ax2 && cy2 >= ay1 && cy2 <= ay2) {
		sum += (ax2 - cx1) * (cy2 - ay1);
	}
	else if (cy1 <= ay2 && cy2 >= ay1 && cx1 <= ax2 && cx2 >= ax1) {
		sum += (min(ay2 - ay1, min(cy2 - cy1, min(ay2 - cy1, cy2 - ay1))) * min(ax2 - ax1, min(cx2 - cx1, min(ax2 - cx1, cx2 - ax1))));
	}

	if ((cx1 >= bx1 && cx1 <= bx2 && cy1 >= by1 && cy1 <= by2)) {
		sum += (min((bx2 - cx1), cx2 - cx1) * min((by2 - cy1), cy2 - cy1));
	}
	else if ((cx2 >= bx1 && cx2 <= bx2 && cy2 >= by1 && cy2 <= by2)) {
		sum += (min((cx2 - bx1), cx2 - cx1) * min((cy2 - by1), cy2 - cy1));
	}
	else if ((cx2 >= bx1 && cx2 <= bx2 && cy1 >= by1 && cy1 <= by2)) {
		sum += (cx2 - bx1) * (by2 - cy1);
	}
	else if (cx1 >= bx1 && cx1 <= bx2 && cy2 >= by1 && cy2 <= by2) {
		sum += (bx2 - cx1) * (cy2 - by1);
	}
	else if (cy1 <= by2 && cy2 >= by1 && cx1 <= bx2 && cx2 >= bx1) {
		sum += (min(by2 - by1, min(cy2 - cy1, min(by2 - cy1, cy2 - by1))) * min(bx2 - bx1, min(cx2 - cx1, min(bx2 - cx1, cx2 - bx1))));
	}
	// End of your soulution.
	//////////////////////////////////////

	fout << ((ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - sum);
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

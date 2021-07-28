#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool oneAway(string input1, string input2) {
	int lengthDiff = std::abs((int)(input1.length() - input2.length())); 
	if (lengthDiff > 1) return false;

	int edits = 0;
	int max = std::max(input1.length(), input2.length());

	for (int i=0, j=0; i < input1.length() && (j < input2.length());) {
		if (input1[i] != input2[j]) edits++; //replace
		if (edits > 1) return false;

		if (lengthDiff != 0) {
			input1.length() > input2.length()?j++:i++;
		}

		j++; i++;
	}

	return true;
}

int main() {
	string input1 = "pile";
	string input2 = "rikle";


	cout << "The strings are " << (oneAway(input1, input2)?"":"not") << " one edit away" << endl;

	return 0;
}

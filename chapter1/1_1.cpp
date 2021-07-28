#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool duplicatesExistSort(vector<char> &input) {
	sort(input.begin(), input.end());
	for (int i=0;i<input.size() - 1;i++) {
		if (input[i] == input[i+1]) return true;
	}

	return false;
}

bool duplicatesExistHash(vector<char> &input) {
	unordered_set<char> set;
	for (char c : input) {
		if (set.find(c) != set.end()) return true;
		set.insert(c);
	}

	return false;
}


int main() {
	char arr[] = {'a', 'b', 'k', 'e'};
	vector<char> input(arr, arr+5);

	cout << "input has " << (duplicatesExistSort(input)?"duplicates":"no duplicates") << endl;
	cout << "input has " << (duplicatesExistHash(input)?"duplicates":"no duplicates") << endl;
}

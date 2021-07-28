#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool canBePalindrome(string input) {
	unordered_map<char, int> charCount;

	for (auto c : input) {
		if (c == ' ') continue;
		charCount[c]++;
	}

	int oddCount = 0;
	for (auto x : charCount) {
		if (oddCount > 1) return false;
		if (x.second % 2 != 0) oddCount++;
	}

	return true;
}

int main() {
	string input = "taco cati";

	cout << "The string " << (canBePalindrome(input)?"can be":"cannot be") << " palindrome";

	return 0;
}

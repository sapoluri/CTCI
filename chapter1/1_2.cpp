#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isAnagramSort(string str1, string str2) {
	if (str1.length() != str2.length()) return false;


	vector<char> s1(str1.begin(), str1.end());
	vector<char> s2(str2.begin(), str2.end());
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	for (int i=0;i<s1.size();i++) {
		if (s1[i] != s2[i]) return false;
	}

	return true;
}

bool isAnagramHash(string str1, string str2) {
	if (str1.length() != str2.length()) return false;
	unordered_map<char, int> charCount;

	for (int i=0;i<str1.length();i++) {
		charCount[str1.at(i)]++;
	}

	for (int i=0;i<str2.length();i++) {
		if (charCount[str2.at(i)]-- < 0) return false;
	}

	for (auto x : charCount) {
		if (x.second != 0) return false;
	}

	return true;
}

int main() {
	string str1 = "string";
	string str2 = "tringe";

	cout << "The two strings are " << (isAnagramSort(str1, str2)?"anagrams": "not anagrams") << endl;
	cout << "The two strings are " << (isAnagramHash(str1, str2)?"anagrams": "not anagrams") << endl;

	return 0;
}

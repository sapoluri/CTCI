#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void URLify(string& input, int length) {
	if (length == 0) return;

	int startIndex = input.length() - 1; //I missed this shit. Cmon grasshopper.
	for (int i = length - 1; i >= 0;) {
		if (input[i] == ' ') {
			input[startIndex--] = '0';
			input[startIndex--] = '2';
			input[startIndex--] = '%';
			i--;
		} else
			input[startIndex--] = input[i--];
	}
}

int main() {
	string input = "This string is legendary      ";

	URLify(input, 24);
        cout <<	input << endl;

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;


int makeChangeHelper(int total, vector<int>& denoms, int index) {
	int coin = denoms[index];

	if (index == (denoms.size() - 1)) {
		return (total%coin) == 0 ? 1: 0;
	}

	int ways=0;
	for (int amount=0;amount<=total;amount+=coin) {
		ways += makeChangeHelper(total-amount, denoms, index+1);
	}

	return ways;
}

int makeChange(int total, vector<int>& denoms) {
	return makeChangeHelper(total, denoms, 0);
}


int main(void) {
	int total;
	cin >> total;
	vector<int> denoms = {25, 10, 5, 1};
	int ways = makeChange(total, denoms);

	cout << ways << endl;

	return 0;
}

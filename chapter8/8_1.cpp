#include <iostream>
#include <vector>

using namespace std;

int tripleStep(int num, vector<long>& memo) {
	if (num < 0) return 0;
	if (num==0) return 1;

	if (memo[num-1] == 0)
		memo[num-1] = tripleStep(num-1, memo) +
		       	tripleStep(num-2, memo) +
		       	tripleStep(num-3, memo);

	return memo[num-1];
}

int main(void) {
	int num;
	cin >> num;
	vector<long> memo(num, 0);
	int ways = tripleStep(num, memo);

	cout << ways << endl;

	return 0;
}

#include <iostream>
#include <set>

using namespace std;

set<string> parens(int num) {
	set<string> results;
	if (num == 0) {
		results.insert("");
		return results;
	}		

	set<string> prev = parens(num-1);
	for (auto a : prev) {
		results.insert("()"+a);
		results.insert("("+a+")");
		results.insert(a+"()");
	}

	return results;
}

int main(void) {
	int num;
	cin >> num;
	set<string> results = parens(num);

	//for (auto a : results) cout << a << endl;
	cout << results.size() << endl;

	return 0;
}

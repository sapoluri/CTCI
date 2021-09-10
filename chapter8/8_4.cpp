#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<set<int>> allSubsets(vector<int>& superset,int index) {
	vector<set<int>> subsets;
	if (superset.size()-1 == index) {
		subsets.push_back(set<int>());
		return subsets;
	}
	
	subsets = allSubsets(superset, index+1);
	vector<set<int>> clonedSubset(subsets);

	//auto& indicates obtain a reference for modification. Otherwise, it is a copy.
	for (auto& subset: subsets) {
		subset.insert(superset[index+1]);
	}
	clonedSubset.insert(clonedSubset.end(), subsets.begin(), subsets.end());

	return clonedSubset;
}

int main(void) {
	vector<int> superset = {10, 15, 23, 45};

	vector<set<int>> subsets = allSubsets(superset, -1);

	for (auto a:subsets) {
		for (auto b: a) {
			cout << b << "|";
		}
		cout << endl;
	}

	return 0;
}

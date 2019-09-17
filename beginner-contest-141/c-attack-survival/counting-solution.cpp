#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/* time: O(n + q), space: O(n), where n = # of players, q = # of questions */
	vector<bool> attackSurvival(int n, int k, const vector<int>& questions) {
		const int q = questions.size();
		vector<int> nCorrect(n);
		for (int player : questions)
			++nCorrect[player - 1];

		vector<bool> ans(n);
		for (int i = 0; i < n; ++i)
			ans[i] = (k - (q - nCorrect[i])) > 0;
		return ans;
	}
};

int main() {
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> questions(q);
	for (int i = 0; i < q; ++i)
		cin >> questions[i];

	Solution sol;
	vector<bool> ans = sol.attackSurvival(n, k, questions);
	for (int i = 0; i < n; ++i)
		cout << (ans[i] ? "Yes" : "No") << endl;
	return 0;
}

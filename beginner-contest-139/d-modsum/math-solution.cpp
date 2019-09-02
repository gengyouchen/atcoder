#include <iostream>

using namespace std;
using LL = long long;

class Solution {
public:
	/* time: O(1), space: O(1) */
	LL modsum(int n) {
		/*
		 * The optimal permutation is:
		 *    n    %    1    =    0
		 *    1    %    2    =    1
		 *    2    %    3    =    2
		 *    3    %    4    =    3
		 *    .         .         .
		 *    .         .         .
		 *    .         .         .
		 * (n - 3) % (n - 2) = (n - 3)
		 * (n - 2) % (n - 1) = (n - 2)
		 * (n - 1) %    n    = (n - 1)
		 */
		return (LL)n * (n - 1) / 2;
	}
};

int main() {
	int n;
	cin >> n;

	Solution sol;
	LL ans = sol.modsum(n);
	cout << ans << endl;
	return 0;
}

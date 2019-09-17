#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
private:
	void insertBasis(LL num, array<LL, 64>& basis) {
		for (int d = 63; d >= 0; --d) {
			const LL bit = 1LL << d;
			if (num & bit) {
				if (basis[d]) {
					num ^= basis[d];
				} else {
					basis[d] = num;
					break;
				}
			}
		}
	}
public:
	/* time: O(n), space: O(1), where n = |A| */
	LL xorSum3(const vector<LL>& A) {
		LL oddBits = 0;
		for (LL num : A)
			oddBits ^= num;
		LL evenBits = ~oddBits;

		array<LL, 64> basis = {};
		for (LL num : A)
			insertBasis(num & evenBits, basis);

		LL maxEvenBits = 0;
		for (int d = 63; d >= 0; --d)
			maxEvenBits = max(maxEvenBits, maxEvenBits ^ basis[d]);
		return maxEvenBits * 2 + oddBits;
	}
};

int main() {
	int n;
	cin >> n;

	vector<LL> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];

	Solution sol;
	LL ans = sol.xorSum3(A);
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	/* time: O(1), space: O(1) */
	string weatherPrediction(const string& s) {
		if (s == "Sunny")
			return "Cloudy";
		if (s == "Cloudy")
			return "Rainy";
		return "Sunny";
	}
};

int main() {
	string s;
	cin >> s;

	Solution sol;
	string ans = sol.weatherPrediction(s);
	cout << ans << endl;
	return 0;
}

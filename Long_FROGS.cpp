// Author : Chaudhary Hamdan
// 100 Points

#include <bits/stdc++.h>
using namespace std;

int main() {

	int t; cin >> t;

	while (t--) {

		int n; cin >> n;

		int weights[n];

		for (int i = 0; i < n; i++)
			cin >> weights[i];

		int jumps[n];

		for (int i = 0; i < n; i++)
			cin >> jumps[i];

		map<int, pair<int, int>>data;
		for (int i = 0; i < n; i++) {

			data[weights[i]] = {jumps[i], i};
		}


		int answer = 0, current ;


		for (auto iter = data.begin(); iter != data.end(); iter++) {

			if (iter == data.begin()) {

				current = (iter->second).second;
			}
			else {

				int idx = (iter->second).second;

				while (current >= idx) {

					answer++;
					idx += ((iter->second).first);
				}
				current = idx;
			}
		}
		cout << answer << endl;

	}

	return 0;
}


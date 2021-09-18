#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin >> s;
	
	map<vector<int>, int> mp;
	int n = s.length();


	for (int i = 0; i < n; i++) {
		vector<int> freq(26, 0);
		for (int j = i; j < n; j++) {
			freq[s[j] - 'a']++;
			mp[freq]++;
		}
	}


	int result=0;
	for (auto i : mp) {
		result += (i.second * (i.second - 1) / 2);
	}

	cout << result << endl;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t; cin >> t;
	while (t--)
		solve();
}

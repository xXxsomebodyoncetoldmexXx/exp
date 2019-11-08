#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define el "\n"

map<set<char>, ll> root;

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("in", "r", stdin);

	ll n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		set<char> dict;
		for(auto i : s)
			dict.insert(i);
		root[dict]++;
	}
	cout << root.size();
	return 0;
}

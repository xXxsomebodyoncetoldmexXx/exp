#include <bits/stdc++.h>

typedef int64_t ll;
typedef uint64_t ull;
typedef double db;
const double PI  =3.141592653589793238463;

using namespace std;

#ifdef LOCAL_PROJECT
#define CURTIME() cerr << el << "[TIME]: " << clock() * 1.0 / CLOCKS_PER_SEC << "s" << el
#define INFILE(name) freopen(name, "r", stdin)
#define OUFILE(name) freopen(name, "w", stdin)
#define DEBUG cerr << "####################\nRunning on Line: " << __LINE__ << "\nIn Function: \t" << 	__FUNCTION__ << "\n####################\n"
#define DUMP(name, value) cerr << "[ " << (name) << " ]: " << (value) << el
#else
#define CURTIME() ;
#define INFILE(name) ;
#define OUFILE(name) ;
#define DEBUG ;
#define DUMP(name, value) ;
#endif

#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define prs(n) cout << fixed << setprecision(n)
#define el "\n"
#define sp " "

// RNG - for sum fun
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Combination calculate
// Note to self: n >= r
ll nCr(ll n, ll r){
	// The fomular:
	// n! / (r! * (n-r)!)
	// Complexity: O(r)
	ll tmp = n-r;
	for(ll i = n-1; i > tmp; i--)
		n *= i;

	for(ll i = r-1; i > 1; i--)
		r *= i;
	return n/r;
}

deque<char> ans;

bool allNine(string s){
	for(auto c : s)
		if(c != '9')
			return false;
	return true;
}

// CHECK IF FIRST HALF IS SMALLER THAN THE SECOND HALF INSIDE OUT
bool smaller(string s){
	ll idx = s.size()/2 - !(s.size()%2);
	ll siz = s.size();
	while(idx >= 0){
		if(s[idx] < s[siz - idx - 1])
			break;
		else if(s[idx] > s[siz - idx - 1])
			return false;
		idx--;
	}
	return true;
}

void overStep(string s){
	for(ll i = 0; i < s.size()-1; i++)
		ans.pb('0');
	ans.pb('1');
	ans.push_front('1');
}

void dup(string s){
	ll idx = s.size()/2;

	// If odd add that middle pos
	if(s.size()%2)
		ans.pb(s[idx]);
	
	idx--;

	// Duplicate first half
	while(idx >= 0){
		ans.pb(s[idx]);
		ans.push_front(s[idx]);
		idx--;
	}
}

void plusOne(string s){
	bool odd = s.size()%2;
	ll idx = s.size()/2 - !odd;
	bool carry = false;

	s[idx]++;
	s[idx] -= '0';
	carry = s[idx]/10;
	s[idx] %= 10;
	s[idx] += '0';
	ans.pb(s[idx]);

	// IF EVEN THERE IS NO MIDDLE POS
	// SO WE NEED TO ADD TO TWO END
	if(!odd)
		ans.pb(s[idx]);

	idx--;

	while(idx >= 0){
		if(carry){
			s[idx]++;
			s[idx] -= '0';
			carry = s[idx]/10;
			s[idx] %= 10;
			s[idx] += '0';
		}
		ans.pb(s[idx]);
		ans.push_front(s[idx]);
		idx--;
	}

	// NO IDEA HOW TO DEAL WITH THIS
	// MAYBE NEVER HAPPEN?
	// ANS: YEAH, IT NEVER HAPPEN CAUSE WE CAUGHT IT IN THE ALL 9 CASE
	if(carry)
		exit(0);
}

int main(int argc, char const *argv[]) {
	FASTIO;
	INFILE("in");
	//OUFILE("out");

	ll T;
	string s;
	cin >> T;
	DEBUG;
	while(T--){
		cin >> s;

		DUMP("s", s);

		if(allNine(s))
			overStep(s);
		else if(smaller(s))
			plusOne(s);
		else
			dup(s);

		// PRINT ANS
		while(!ans.empty()){
			cout << ans.front();
			ans.pop_front();
		}
		cout << el;

	}
	CURTIME();
	return 0;
}

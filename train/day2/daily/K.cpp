#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define po pop
#define pu push
#define ety empty
#define tp top
#define ft front
#define bk back
#define ll long long
 
int main()
{
    ios::sync_with_stdio(false);
	ll n,x=2;
	cin>>n;
	cout<<2<<endl;
	for (ll i=2;i<=n;i++){
		cout<<i*(i+1ll)*(i+1ll)-(i-1ll)<<endl;
	}
}

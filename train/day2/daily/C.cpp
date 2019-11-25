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
int a[104],b[104];
int main()
{
    ios::sync_with_stdio(false);
	int n,m,mi;
	cin>>n>>m; mi=m;
	if(m>n*9 || (!m && n!=1)) { cout<<    -1 << " -1"; return   0     ;}
	if(!m && n==1) { cout<< "0 0";   return   0  ;	}
	mi-=a[0]=1;
	for(int i=n-1; mi; i--){
		a[i]+= mi<9?mi:9;
		mi-=a[i];
	}
	for(int i=0;i<n;i++) cout<<a[i]; cout<<" ";
	
	for(int i=0;m;i++){
		b[i]+= m<9?m:9;
		m-=b[i];
	}
	
	for(int i=0;i<n;i++) cout<<b[i];
}

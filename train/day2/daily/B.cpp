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
	ll n,m,tmp;
	cin>>n;
	ll a[n]={};
	for (int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	ll b[m]={};
	for (int i=0;i<m;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	ll c[n][m]={};
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++){
			if (i>0 and c[i][j]<c[i-1][j]) 
				c[i][j]=c[i-1][j]; 
			if (j>0 and c[i][j]<c[i][j-1]) 
				c[i][j]=c[i][j-1]; 
			
			if (abs(a[i]-b[j])<=1)
				tmp=1;
			else 
				tmp=0;
				
			if (i>0 and j>0 and c[i][j]<c[i-1][j-1]+tmp) 
				c[i][j]=c[i-1][j-1]+tmp;
			if (c[i][j]<tmp)
				c[i][j]=tmp;
		}
	cout<<c[n-1][m-1];
}

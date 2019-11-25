    #include<bits/stdc++.h>
    using namespace std;
    //
    #define LL                               long long
    #define ULL                              unsigned long long
    #define VI                               vector<int>
    #define VII                              vector< VI >
    #define PII                              pair<int,int>
     
    #define FAST_IN                          ios_base::sync_with_stdio(false);cin.tie(NULL);
     
    #define MOD                              1000000007ll
    #define INF                              (1LL<<32)
     
    // output
    #define pr                               cout
    #define ii(x)                            << (x) << ' '
    #define nt								 ;
    #define spc                              << ' ' 
    #define fixed(x)                         << fixed << setprecision(x) 
    #define ln                               << '\n'
    #define prno                             cout<<"NO\n";
    #define pryes                            cout<<"YES\n";
    #define pryon                            pryes else prno
     
    // read-write file
    #define REF(filename)                    freopen((filename),"r",stdin)
    #define WRF(filename)                    freopen((filename),"w",stdout)
     
    // loop
    #define rep(i,a,b)                       for(int i=a;i<b;i++)
    #define rev(i,a,b)                       for(int i=a-1;i>=b;i--)
    #define when(n)                          while(n--)
     
    // min-max
    #define Max(a,b)                         a = (a>b?a:b);
    #define Min(a,b)                         a = (a<b?a:b);
     
    // Degree and Radian
    //const double PI = 2 * acos(0);
    //double DEG(double x) { return (180.0*x)/(PI*1.0);  }
    //double RAD(double x) { return (x*(PI*1.0))/(180.0);}
     
    // dir[][0] = x value, dir[][1] = y value
    //int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} };                                  // 4 Direction
    //int dir[9][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}};       // 8 direction
    //int dir[9][2] = { {0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };    // Knight Direction
    //int dir[8][2] = { {0,0},{2,0},{1,1},{-1,1} ,{-2,0} , {-1,-1} ,{1,-1} };               // Hexagonal Direction
     
    // function
    //LL gcd(LL a,LL b){while( (a %= b) && (b %= a) );return a+b;}
    //LL lcm(LL a,LL b){return (a)/(gcd(a,b))*b;}
     
    // random
    //#define RAND_BETWEEN(x,y)             ((rand()%((y)-(x)+1))+x)
     
    //==================================//==
    ///for global variable
    int a[1005][1005];
    //==================================//==
    ///for function
     
    //==================================//==
    int main()
    {
    	FAST_IN;
    	// REF("in.txt");
    	// WRF("out.txt");
    	
    	int n,m;
    	char cur,ch;
    	cin>>n>>m;
    	rep(i,0,n) rep(j,0,m){
    		cin>>ch;
    		a[i][j] = 1 + (j?(ch==cur)*a[i][j-1]:0);
    		cur=ch;
    	}
    	// rep(i,0,n){ rep(j,0,m) pr ii(a[i][j]); pr ln;} pr ln;
    	int ans=0,x;
    	rep(k,0,m){
    		int i=0,j=i+1,mi;
    		while(i<n){
    			mi=a[i][k];
    			rep(t,i,j) Min(mi,a[t][k]);
    			while(j-i<mi && j<n){
    				Min(mi,a[j][k]);j++;
    			}
    			x=min(min(a[i][k],a[j-1][k]),j-i);
    			// if(k>1){
    			// 	pr ii(k)ii(i)ii(j)ln;
    			// 	pr ii(x)ln;
    			// }
    			Max(ans,x);
    			i++;
    		}
    	}
    	pr ii(1LL*ans*ans);
    	return 0;
    }

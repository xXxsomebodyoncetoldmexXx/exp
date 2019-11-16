// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

const int mod = 1000 * 1000 * 1000 + 7;
int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

const int max_n = 1001;
pair<int, bool> dp[2 * max_n][2 * max_n];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    n *= 2;

    assert(n / 2 < max_n);
        
    
    dp[0][0] = make_pair(0, true);
    
    for (int len = 1; len <= n; ++len) {
        for (int bal = 0; bal <= n; ++bal) {
            // (len, bal) -> (len - 1, bal + 1)
            // (len, bal) -> (len - 1, bal - 1)

            int sum = 0;
            bool has = false;

            if (bal != 0) {
                sum = add(sum, dp[len - 1][bal - 1].first);
                has = has or dp[len - 1][bal - 1].second;
            }

            if (bal + 1 <= len - 1) {
                sum = add(sum, dp[len - 1][bal + 1].first);
                has = has or dp[len - 1][bal + 1].second;
            }

            if (has)
                dp[len][bal] = make_pair(add(sum, 1), false);
            else
                dp[len][bal] = make_pair(sum, true);
        }
    }
    
    for(int i = 1; i <= n; i++){
      for(int j = 0; j <= n; j++)
        printf("%d ", dp[i][j].first);
      puts("");
        // std::cout << dp[i][j] << " ";
      // std::cout << std::endl;
    }
    puts("");
    for(int i = 1; i <= n; i++){
      for(int j = 0; j <= n; j++)
        printf("%d ", dp[i][j].second);
      puts("");
        // std::cout << dp[i][j] << " ";
      // std::cout << std::endl;
    }
    cout << dp[n][0].first << "\n";
    
    return 0;
}

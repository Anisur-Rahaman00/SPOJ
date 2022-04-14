#include <bits/stdc++.h>

#define I_O ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//~~~~~~~~~~~~ Sort Form Of Long~~~~~~~~~~~//
#define ll long long int
#define lls int64_t
#define ld long double
#define db double
#define ull unsigned long long int

//~~~~~~~~~~~~~~Pair~~~~~~~~~~~~~~~~~~//
#define pii pair<int, int>
#define pll pair<lls, lls>
#define pdd pair<db,db>
#define psi pair<string,int>
#define vi vector<int>
#define vl vector<lls>
#define vd vector<db>
#define vs vector<string>
#define vb vector<bool>
#define vpi vector<pii>
#define vpl vector<pll>
#define vpd vector<pdd>
#define vpsi vector<psi>
#define vvi vector<vector<int>>

//~~~~~~~~~~~~~~Shorts~~~~~~~~~~~~~~~~~//
#define ff first
#define ss second
#define Br break
#define Cn continue
#define al(v) v.begin(),v.end()
#define alr(v) v.rbegin(), v.rend()
#define srt(v) sort(al(v))
#define srtr(v) sort(al(v), greater<int>());
#define len(x) ((int)(x).size())
#define rev(v) reverse(al(v))
#define btcnt(n) __builtin_popcount(n)
#define acl(v, n) accumulate(al(v), n)
#define Lrt(s, c) rotate(s.begin(), s.begin() + c, s.end())
#define Rrt(s, c) rotate(s.begin(), s.begin() + s.size() - c, s.end())
#define lb(v, kk) lower_bound(al(v), kk) - v.begin()
#define ub(v, kk) upper_bound(al(v), kk) - v.begin()
#define tpu(str) transform(al(str), str.begin(), ::toupper)
#define tpl(str) transform(al(str), str.begin(), ::tolower)
#define cignr cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define mxv(v) *max_element(al(v))
#define mnv(v) *min_element(al(v))

const int MOD = 1e9 + 7;
const lls INF = 2e18;
const int mxn = 2e9 + 9;
const int mxd = 2e5 + 5;
const int mxa = 2e6 + 5;

//~~~~~~~~~~~~~~~~~~Function~~~~~~~~~~~~~~~~~~~~//
lls gcd(lls a, lls b){ if(b == 0LL) return a; return gcd(b, a % b); }
lls lcm(lls a, lls b){ return (a / gcd(a, b) * b); }
lls maxll(lls x, lls y){ return x > y ? x : y; }
lls minll(lls x, lls y){ return x < y ? x : y; }

//~~~~~~~~~~~~~~~Loops and Short~~~~~~~~~~~~~~~~//

#define PI acos(-1)
#define N '\n'
#define fopen freopen("input.txt", "r", stdin);
#define rep(i, n) for(lls i = 0; (lls)i < n; i++)
#define test_case() int T; cin >> T; while(T--)

using namespace std;

// ===================================~~~~~~ SOLUTION STARTS HERE ~~~~~~=================================== //

//int a, b, c, d, e, res = 0, ans = 0, prod = 1, n, m, cnt = 0, k, l, r, s, t, x, y, f, i, j, p;

int save[101][101], a[101][101];

int findMax(int i, int j, int n, int m) {
    if (i >= n or i < 0 or j >= m or j < 0) return 0;

    if (save[i][j]) return save[i][j];

    int temp = a[i][j] + max({findMax(i + 1, j - 1, n, m), findMax(i + 1, j, n, m), findMax(i + 1, j + 1, n, m)});
    return save[i][j] = temp;
}

void Run_Case() 
{
    int n, m;
    cin >> n >> m;

    rep (i, n) {
        rep (j, m) save[i][j] = 0;
    }

    rep (i, n) {
        rep (j, m) cin >> a[i][j];
    }

    int ans = 0, sum = 0;

    for (int i = 0; i < m; i++) {
        sum = findMax(0, i, n, m);
        ans = max(ans, sum);
    }

    cout << ans << N;
}

int main()
{
   I_O
   test_case()
   {
      Run_Case();
   }

   return 0;
}

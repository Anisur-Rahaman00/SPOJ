
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

//~~~~~~~~~~~~~~Vector~~~~~~~~~~~~~~~~~//
#define pb push_back
#define pf push_front
#define MP make_pair
#define in insert
#define ff first
#define ss second
#define al(v) v.begin(),v.end()
#define alr(v) v.rbegin(), v.rend()
#define srt(v) sort(al(v))
#define srtr(v) sort(al(v), greater<int>());
#define len(x) ((int)(x).length())
#define sz(x) ((int)(x).size())
#define rev(v) reverse(al(v))
#define btcnt(n) __builtin_popcount(n)
#define acl(v, n) accumulate(al(v), n)
#define eb emplace_back
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
const ll INF = 2e18;
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
#define Cn continue
#define Br break
#define off return 0
#define N '\n'
#define fopen freopen("input.txt", "r", stdin);
#define rep(i, n) for(lls i = 0; (lls)i < n; i++)
#define repn(i, a, b) for(lls i = (lls)(a); i < (lls)(b); i++)
#define repr(i, a, b) for(lls i = (lls)(a) - 1; i >= (lls)(b); i--)
#define test_case() int T; cin >> T; while(T--)

using namespace std;

// Stores the accessible directions
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// ===================================~~~~~~ SOLUTION STARTS HERE ~~~~~~=================================== //

//int a, b, c, d, e, res = 0, ans = 0, prod = 1, n, m, cnt = 0, k, l, r, s, t, x, y, f, i, j, p;

int vis[mxd];
vi graph[mxd];

void dfs(int node) {
   vis[node] = 1;

   //cout << node << " ";
   for (auto aa: graph[node]) {
      if (!vis[aa]) {
         dfs(aa);
      }
   }
}

void Run_Case() 
{

   int n, m, u, v;
   cin >> n >> m;
   for (int i = 1; i <= n; i++) graph[i].clear();
   for (int i = 1; i <= m; i++) {
      cin >> u >> v;
      u++, v++;
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   memset(vis, 0, sizeof(vis));
   int cc = 0;
   for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
         dfs(i);
         cc++;
      }
   }

   // cc = connected components
   cout << cc << N;
}

int main()
{
   I_O
   test_case()
   {
      Run_Case();
   }
   off;
}


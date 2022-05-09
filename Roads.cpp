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
#define Read(x) freopen(x, "r", stdin)
#define Write(x) freopen(x, "w", stdout)
#define rep(i, n) for(lls i = 0; (lls)i < n; i++)
#define test_case() int T; cin >> T; while(T--)

using namespace std;

vector<pair<int, pii>> g[mxd];
int n, k, r, u, v, l, t;

void Run_Case() 
{
   cin >> k >> n >> r;
   for (int i = 1; i <= n; i++) g[i].clear();

   while (r--) {
      cin >> u >> v >> l >> t;
      g[u].push_back({v, {l, t}});
   }

   priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
   
   pq.push({0, {0, 1}});

   int f = 0;
   while (!pq.empty()) {
      pair<int, pii> tmp = pq.top();
      pq.pop();
      l = tmp.ff;
      t = tmp.ss.ff, u = tmp.ss.ss;

      if (u == n) {
         f = 1;
         break;
      }

      for (auto aa: g[u]) {
         tmp = aa;
         v = aa.ff;

         int bb = tmp.ss.ff;
         int cc = tmp.ss.ss;

         if (t + cc <= k) {
            pq.push({l + bb, {t + cc, v}});
         }
      }
   }

   if (f) cout << l << N;
   else cout << "-1" << N;
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

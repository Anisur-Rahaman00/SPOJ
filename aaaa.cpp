#include<bits/stdc++.h>
using namespace std;
typedef     vector<int> vi;
#define pb  push_back
int mn;
vi ans;
vi sorted_v;
vector<vi>tr;
vi flip(vi v, int x) {
    reverse(v.begin(), v.begin() + x);
    return v;
}

bool is_short(vi v) {
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) return false;
    }
    return true;
}

int heautistic(vi v) {
    int h = 0, i;
    for (i = 0; i < v.size(); i++) {
        if (v[i] != sorted_v[i]) h++;
    }
    return h;
}

void bfs_search(vi v) {
    map<vi, int>vis;
    map<vi, int>mp;
    map<vi, vi>path;
    map<vi, vi>parent;
    queue<vi>q;
    q.push(v);
    vis[v] = 1;
    while (!q.empty()) {
        vi cur = q.front();
        q.pop();
        if (is_short(cur)) {
            ans = path[cur];
            while (cur != v) {
                tr.pb(cur);
                cur = parent[cur];
            }
            reverse(tr.begin(), tr.end());
            return;
        }
        int sz = cur.size();
        for (int i = 2; i <= sz; i++) {
            vi next = flip(cur, i);
            if (vis[next]) continue;
            vis[next] = 1;
            parent[next] = cur;
            q.push(next);
            path[next] = path[cur];
            path[next].pb(i);
            mp[next] = mp[cur] + 1;
        }
    }
}

void Astar_serarch(vi v) {
    map<vi, int>vis;
    map<vi, int>mp;
    map<vi, vi>path;
    map<vi, vi>parent;
    priority_queue<pair<int, vi>>q;
    int h = heautistic(v);
    q.push({ -h, v});
    vis[v] = 1;
    while (!q.empty()) {
        pair<int, vi> node = q.top();
        vi cur = node.second;
        q.pop();
        if (is_short(cur)) {
            ans = path[cur];
            while (cur != v) {
                tr.pb(cur);
                cur = parent[cur];
            }
            reverse(tr.begin(), tr.end());
            return;
        }
        int sz = cur.size();
        for (int i = 2; i <= sz; i++) {
            vi next = flip(cur, i);
            if (vis[next]) continue;
            vis[next] = 1;
            parent[next] = cur;
            h = heautistic(next);
            mp[next] = mp[cur] + 1;
            int g = mp[next];
            int gh = h + g;
            q.push({ -gh, next});
            path[next] = path[cur];
            path[next].pb(i);
        }
    }
}

int main() {
    int n, i, j, x, y;
    cout << "Enter number of pancake : ";
    cin >> n;
    cout << endl << endl;
    cout << "Enter the size of n pancake : ";
    vi v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    cout << endl << endl;
    sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    bfs_search(v);
    cout << "minimum step using bfs : ";
    cout << ans.size() << endl;
    cout << endl << endl;

    cout << "the steps towards the solution:" << endl << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
    int index = 0;
    for (vi vv : tr) {
        cout << "reverse first " << ans[index++] << " Element --->" << endl;
        for (int x : vv) cout << x << " ";
        cout << endl;
    }
   cout<<endl<<endl<<endl<<"A star Search----"<<endl<<endl;
    tr.clear();
    ans.clear();
    Astar_serarch(v);
    cout << "minimum step using A star search : ";
    cout << ans.size() << endl;
    cout << endl << endl;

    cout << "the steps towards the solution:" << endl << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
     index = 0;
    for (vi vv : tr) {
        cout << "reverse first " << ans[index++] << " Element --->" << endl;
        for (int x : vv) cout << x << " ";
        cout << endl;
    }
}

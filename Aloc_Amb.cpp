#include <bits/stdc++.h>
#define _ ios::sync_with_stdio(false);cin.tie(0);
#define f first
#define s second
 
using namespace std;
const int MAX = 1e3;
const int INF = 0x3f3f3f3f;
 
vector<pair<int,int> > g[MAX];
vector<int> dist, amb;
int n, m, q;
 
void dijkstra(){
    priority_queue<pair<int,int> > pq;
    for(int i = 0; i < n; i++){
        if(amb[i]){
            dist[i] = 0;
            pq.push({0, i});
        }
    }
    
    while(!pq.empty()){
        int u = pq.top().s;
        int d = -pq.top().f;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto pv: g[u]){
            int v = pv.first;
            int new_d = pv.second;
            if(dist[v] > dist[u] + new_d){
                dist[v]  = dist[u] + new_d;
                pq.push({-dist[v], v});
            }
        }
    }
}
 
void solve(){
    for(int i = 0; i < n; i++) g[i].clear();
    dist = vector<int>(n, INF);
    amb = vector<int>(n, 0);
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w; a--, b--;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    for(int i = 0; i < q; i++){
        int x; cin >> x; x--;
        amb[x] = 1;
    }
    dijkstra();
    int maior = -1;
    for(int i = 0; i < n; i++)
        maior = max(maior, dist[i]);
    cout << maior << endl;
} 
 
int main() {_
 
    while(cin >> n >> m >> q)
        solve();
 
    return 0;
}

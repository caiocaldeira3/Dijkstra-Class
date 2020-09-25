#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define _ ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int,int> Edge;
typedef vector<vector<Edge> > Graph;

void add_edge(Graph &g, int from, int to, int weight=1){
	g[from].pb({to, weight});
	g[to].pb({from, weight});
}

vector<int> dijkstra(Graph &g, int source){
	vector<int> d(g.size(), INF);
	vector<int> vis(g.size(), 0);
	
	priority_queue<Edge> pq;
	pq.push({0, source}); 
	d[source] = 0;
	
	while(!pq.empty()){
		pair<int,int> aux = pq.top(); pq.pop();
		int u = aux.s, w = -aux.f;
		if(d[u] < w or vis[u]) continue;
		vis[u] = 1;
		for(Edge edg : g[u]){
			if(d[edg.f] > w + edg.s){
				d[edg.f] = (w + edg.s);
				pq.push({-d[edg.f], edg.f});	
			}
		}
	}
	return d;
}


int main(){_
	
	int n, m, x;
	cin >> n >> m >> x;
	
	Graph grp(n, vector<Edge>());
	Graph rev_grp(n, vector<Edge>());
	vector<int> friends(x);

	for(int i = 0; i < m; i++){
		int a, b, w;
		cin >> a >> b >> w; a--, b--;
		add_edge(grp, a, b, w);
		add_edge(rev_grp, a, b, w);
	}
	for(int &fri: friends)
		cin >> fri;

	vector<int> to_friends = dijkstra(grp, 0);
	vector<int> to_icecream = dijkstra(rev_grp, n-1);
	
	pair<int,int> ans = {INF, -1};
	for(int fri: friends){
		int dist = to_friends[fri-1] + to_icecream[fri-1];
		if(ans.f > dist)
			ans = {dist, fri};
	}

	cout << ans.f << endl;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 303;
const int M = 14000<<1;
const int INF = 0x3fffffff;
int n, m, vs, vt;
int c[N], r[N], t[N][2];

vector <pair<int, int> > g[N];
int getColor(int u, int T) {
	T%= t[u][0]+t[u][1];
	if(T < r[u] || T >= r[u]+t[u][c[u]^1]) return c[u];
	return c[u]^1;
}
int getNext(int u, int T) {
	int tmp = T%(t[u][0]+t[u][1]);
	if(tmp < r[u]) return T+r[u]-tmp;
	else if(tmp >= r[u]+t[u][c[u]^1])
		return T+r[u]+t[u][0]+t[u][1]-tmp;
	return T+r[u]+t[u][c[u]^1]-tmp;
}
int getVal(int u, int v, int T) {
	int step = 3;
	int cu, cv;
	do {
		cu = getColor(u, T);
		cv = getColor(v, T);
		if(cu == cv) return T; 
		T = min(getNext(u, T), getNext(v, T));
	}while(step--);
	return -1;
}
int dp[N], pre[N];
bool vis[N];
void output(int u) {
	if(!u) return;
	output(pre[u]);
	if(pre[u]) printf(" ");
	printf("%d", u);
}
queue <int> Q;
void spfa() {
	for(int i = 0; i <= n; i++)
		dp[i] = INF;
	dp[vs] = 0, Q.push(vs), vis[vs] = true;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = false;
		for(int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].first;
			int val = getVal(u, v, dp[u]);
			if(val == -1) continue;
			val += g[u][i].second;
			if(val < dp[v]) {
				pre[v] = u;
				//	printf("u=%d v=%d w=%d val=%d\n", u, v, g[i].w, val);
				dp[v] = val;
				if(!vis[v]) {
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
	if(dp[vt] == INF) 
		puts("0");
	else { 
		printf("%d\n", dp[vt]);
		output(vt), puts("");
	}
}
int main() {
	int i, j;
	scanf("%d%d%d%d", &vs, &vt, &n, &m);
	for(i = 1; i <= n; i++) {
		char buf[3];
		scanf("%s%d%d%d", buf, &r[i], &t[i][0], &t[i][1]);
		c[i] = (buf[0] == 'P');
	}
//	init();
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}
	spfa();
	return 0;
}
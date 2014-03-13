#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int l[103], r[103];
struct Edge {
    int v, next, vis;
}g[103*103];
int head[8], etot;
void add(int s, int t) {
    g[etot].v = t;
    g[etot].next = head[s];
    head[s] = etot++;
}
void dfs(int u) {
    int i;
    for(i = head[u]; i!=-1; i=g[i].next) {
        if(g[i].vis) continue;
        g[i].vis = g[i^1].vis = 1;
        dfs(g[i].v);

        if(i&1)printf("%d +\n", (i>>1)+1);
        else printf("%d -\n", (i>>1)+1);
    }
}
int val = 0;
void cal(int u) {
    int i;
    for(i = head[u]; i!=-1; i=g[i].next) {
        if(g[i].vis) continue;
        g[i].vis = g[i^1].vis = 1;
        val++;
        cal(g[i].v);
    }
}
int d[8], n;
int main() {
    int i, j;
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    etot = 0;
    memset(d, 0, sizeof(d));
    int pos = -1;
    for(i = 0; i < n; i++) {
        scanf("%d%d", &l[i], &r[i]);
        add(l[i], r[i]);
        add(r[i], l[i]);
        d[l[i]]++;
        d[r[i]]++;
        pos = r[i];
    }
    int cnt = 0;
    for(i = 0; i <= 6; i++)
        if(d[i]&1) cnt++, pos = i;
    cal(pos);
    for(i = 0; i < etot; i++)
        g[i].vis = 0;
    if(val != n) {
       puts("No solution");
       return 0;
    }
    if(cnt == 2||cnt == 0)
        dfs(pos);
    else
        puts("No solution");
    return 0;
}

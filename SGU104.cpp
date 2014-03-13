#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0xfffffff;
int F, V;
int dp[103][103];
int pre[103][103];
int a[103][103];
void out(int i, int j) {
	if(!i) return;
	out(i-1, pre[i][j]);
	printf("%d ", j);
}
int main() {
    int i, j, k;
    scanf("%d%d", &F, &V);
    for(i = 0; i <= F; i++)
        for(j = 0; j <= V; j++)
            dp[i][j] = -INF;
    for(i = 0; i <= V; i++)
        dp[0][i] = 0;
    for(i = 1; i <= F; i++)
        for(j = 1; j <= V; j++)
            scanf("%d", &a[i][j]);
   for(i = 0; i < F;i++)
        for(j = 0; j < V; j++) if(dp[i][j] != -INF)
            for(k = j+1; k <= V; k++) {
            	if(dp[i+1][k] < dp[i][j] + a[i+1][k]) {
            		dp[i+1][k] = dp[i][j]+a[i+1][k];
            		pre[i+1][k] = j;
            	}
            }
   int ans = -INF, pos = -1;
   for(i = F; i <= V; i++) if(ans < dp[F][i]) {
	   pos = i;
	   ans = dp[F][i];
   }
   printf("%d\n", ans);
   out(F, pos), puts("");
   return 0;
}
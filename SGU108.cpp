#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int a[66], ans;
int n, k;
struct node {
    int v, id, ans;
    bool operator<(const node &t)const {
        return id < t.id;
    }
}b[5005];
bool cmp(node a, node b){
    return a.v < b.v;
}
int main() {
	vector <int> vec;
	int i, j, cur = 0;
	scanf("%d%d", &n, &k);
	for(i = 0; i < k; i++)
		scanf("%d", &b[i].v), b[i].id = i;
    sort(b, b+k, cmp);
	for(i = 1; i <= n; i++) {
		if(!a[i&63]) ans++;
		j = i;
		int v = i;
		while(j > 0) v += j%10, j/=10;
		a[v&63] = 1;
		while(cur <= k && b[cur].v < ans) cur++;
		int sta = cur;
		while(cur <= k && b[cur].v == ans) cur++;
		for(j = sta; j < cur; j++)
			if(b[j].v == ans && !a[i&63]) {
				b[j].ans = i;
			}
		a[i&63] = 0;
	}
	sort(b, b+k);
	printf("%d\n", ans);
	for(i = 0; i < k; i++) {
		if(i) printf(" ");
		printf("%d", b[i].ans);
	}
	puts("");
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	if(n <= 8)
		puts("0");
	else if(n == 9)
		puts("8");
	else {
		n -= 10;
		printf("72");
		for(int i = 0; i < n; i++)
			printf("0");
		puts("");
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n/3*2+ (n%3==2));
	return 0;
}
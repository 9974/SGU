#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
void gcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0) {
		x = 1, y = 0;
		return;
	}
	gcd(b, a%b, y, x);
	y -= a/b*x;
    
}
ll a, b, c, x1, x2, y1, y2;
ll debug() {
    ll x, ans = 0;
    for(x = x1; x <= x2; x++) {
        ll t = -(a*x+c);
        if(t%b==0) {
            ll y = t/b;
            if(y >= y1 && y <= y2)
                ans++, cout <<"x="<<x <<"y="<<y<<endl;
        }
    }
    return ans;
}
int main() {
	cin >>a>>b>>c>>x1>>x2>>y1>>y2;
    //cout << debug() << endl;
	if(a < 0)
		a = -a, b = -b;
	else
		c = -c;
	ll t = __gcd(a, b);
	if(!a && !b && c) {
		cout << "0\n";
		return 0;
	}
	if(!a && !b && !c) {
		cout << (x2-x1+1)*(y2-y1+1) << endl;
		return 0;
	}
	if(!a && b) {
		if(c%b == 0 &&  c/b >= y1 && c/b <= y2)
			cout << x2-x1+1<<endl;
		else
			cout << "0\n";
        return 0;
	}
	if(a && !b) {
		if(c%a==0 && c/a >= x1 && c/a <= x2)
			cout << y2-y1+1 << endl;
		else
			cout << "0\n";
        return 0;
	}
	if(c%t) {
		cout << "0\n";
		return 0;
	}
	c/=t, a/=t, b/=t;
	ll x, y;
	gcd(a, b, x, y);
	x *= c, y *= c;
	ll l1, r1;
	if(b < 0) {
		b = -b, x1 = -x1, x2 = -x2;
		swap(x1, x2);
	}
	t = x2-x;
	if(t > 0)
		r1 = t/b;
	else
		r1 = (t-b+1)/b;
	t = x1-x;
	if(t > 0)
		l1 = (t+b-1)/b;
	else
		l1 = t/b;

	ll l2, r2;
	y1 = -y1, y2 = -y2, y = -y;
	swap(y1, y2);
	if(a < 0) {
		a = -a, y1 = -y1, y2 = -y2;
		swap(y1, y2);
	}
	t = y2-y;
	if(t > 0)
		r2 = t/a;
	else
		r2 = (t-a+1)/a;
	t = y1-y;
	if(t > 0)
		l2 = (t+a-1)/a;
	else 
		l2 = t/a;
	l1 = max(l1, l2);
	r1 = min(r1, r2);
	if(l1 > r1)
		cout <<"0\n";
	else 
		cout <<r1-l1+1<<endl;

/*
	ll z1 = c-b*y2, z2 = c-b*y1;
	if(b < 0) swap(z1, z2);
	if(a < 0) swap(z1, z2), z1*=-1, z2*=-1,a*=-1;
    
	if(z2 >= 0) z2 /= a;
	else z2 = (z2-a+1)/a;
	if(z1 <= 0) z1 /= a;
	else z1 = (z1+a-1)/a;
    
	x1 = max(x1, z1);
	x2 = min(x2, z2);
    
	if(x1 < x)
		x1 = x - (x-x1)/b*b;
	else
		x1 = x + (x1-x+b-1)/b*b;
	if(x2 < x)
		x2 = x - (x-x2+b-1)/b*b;
	else
		x2 = x + (x2-x)/b*b;
	if(x1 > x2)
		cout << "0" << endl;
	else
		cout << (x2-x1)/b+1<<endl;
		*/
	return 0;
}
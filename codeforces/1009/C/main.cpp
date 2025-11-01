#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, x, d;
ll sum;
int main() {
    cin>>n>>m;
    sum=0;
    for (int i=0; i<m; i++) {
        cin>>x>>d;
        sum+=x*n;
        if (d<0) {
            if (n&1) {
                sum+=1LL*d*(n/2)*(n/2+1);
            } else {
                int tmp=n-1;
                sum+=1LL*d*(tmp/2)*(tmp/2+1);
                sum+=1LL*d*(tmp/2+1);
            }
        } else {
            sum+=1LL*d*(n-1)*n/2;
        }
    }
    printf("%.8Lf\n", 1.0L*sum/n);
    return 0;
}

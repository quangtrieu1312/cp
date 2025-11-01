#include <bits/stdc++.h>
#define PMAX 10004
using namespace std;
typedef pair<int, int> pii;
int t, n;
vector<int> a, prefix, suffix;
bool res;

int gcd(int x, int y) {
    if (x==0) return y;
    if (y==0) return x;
    if (x>y) swap(x,y);
    return gcd(x,y%x);
}
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        res=false;
        a.resize(n);
        prefix.resize(0);
        prefix.resize(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
            if (i==0) {
                prefix[i]=a[i];
            } else {
                prefix[i]=gcd(prefix[i-1],a[i]);
            }
        }
        suffix.resize(0);
        suffix.resize(n);
        for (int i=n-1; i>=0; i--) {
            if (i==n-1) {
                suffix[i]=a[i];
            } else {
                suffix[i]=gcd(suffix[i+1],a[i]);
            }
        }
        int ind=-1;
        for (int i=0; i<n; i++) {
            if (i==0) {
                if (a[i]!=suffix[i+1]) {
                    res=true;
                    ind=i;
                    break;
                }
            } else if (i==n-1) {
                if (prefix[i-1]!=a[i]) {
                    res=true;
                    ind=i;
                    break;
                }
            } else {
                if (gcd(prefix[i-1],suffix[i+1])!=a[i]) {
                    res=true;
                    ind=i;
                    break;
                }
            }
        }
        if (res) {
            cout<<"YES"<<endl;
            for (int i=0; i<n; i++) {
                if (i==ind) {
                    cout<<1<<" ";
                } else {
                    cout<<2<<" ";
                }
            }
            cout<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

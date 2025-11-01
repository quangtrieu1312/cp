#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t;
int n;
string s;
ll k;
vector<ll> a;

ll findLargestSub(vector<ll> x) {
    if (x.size()==0) {
        return 0;
    }
    vector<ll> prefix;
    int m=x.size();
    prefix.resize(m,0);
    prefix[0]=x[0];
    for (int i=1; i<m; i++) {
        prefix[i]=prefix[i-1]+x[i];
    }
    vector<ll> sufmax;
    sufmax.resize(m, 0);
    sufmax[m-1]=prefix[m-1];
    for (int i=m-2; i>=0; i--) {
        sufmax[i]=max(sufmax[i+1],prefix[i]);
    }
    ll maxsub=0;
    for (int i=0; i<m; i++) {
        if (i==0) {
            maxsub=sufmax[0];
        } else {
            maxsub=max(maxsub,sufmax[i]-prefix[i-1]);
        }
    }
    return maxsub;
}

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        cin>>s;
        a.resize(n);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        int firstZero=-1;
        int lastZero=-2;
        for (int i=0; i<n; i++) {
            if (s[i]=='0') {
                firstZero=i;
                break;
            }
        }
        for (int i=n-1; i>=0; i--) {
            if (s[i]=='0') {
                lastZero=i;
                break;
            }
        }
        vector<ll> b;
        for (int i=0; i<n; i++) {
            if (s[i]=='1') {
                b.push_back(a[i]);
            } else {
                b.push_back(-2000000000012LL);
            }
        }
        ll maxsub=findLargestSub(b);
        if (maxsub>k || (firstZero<0 && maxsub!=k)) {
            cout<<"No"<<endl;
            continue;
        }
        if (maxsub==k) {
            cout<<"Yes"<<endl;
            for (int i=0; i<n; i++) {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        int l=firstZero;
        int r=lastZero;
        ll tmp;
        tmp=0;
        for (int i=firstZero-1; i>=0; i--) {
            tmp+=a[i];
            if (tmp>0) {
                l=i;
            }
        }
        tmp=0;
        for (int i=lastZero+1; i<n; i++) {
            tmp+=a[i];
            if (tmp>0) {
                r=i;
            }
        }
        tmp=0;
        for (int i=l; i<=r; i++) {
            if (s[i]=='1') {
                tmp+=a[i];
            }
        }
        for (int i=firstZero; i<=lastZero; i++) {
            if (s[i]=='1') continue;
            if (i!=lastZero) {
                a[i]=0;
            } else {
                a[i]=k-tmp;
            }
        }
        cout<<"Yes"<<endl;
        for (int i=0; i<n; i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int t, n, res;
vector<int> a, b, adja, adjb;
vector<pii> moves;
map<pii, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("inp.txt", "r", stdin);
    //freopen("outp.txt", "w", stdout);
    cin>>t;
    while (t--) {
        cin>>n;
        a.resize(n);
        b.resize(n);
        adja.resize(n+1);
        adjb.resize(n+1);
        moves.resize(0);
        for (int i=0; i<n; i++) {
            cin>>a[i];
        }
        for (int i=0; i<n; i++) {
            cin>>b[i];
        }
        m.clear();
        for (int i=0; i<n; i++) {
            adja[a[i]]=b[i];
            adjb[b[i]]=a[i];
            m[pii(a[i],b[i])]=i;
        }
        res=-2;
        int cntDup=0;
        int dupInd=0;
        for (int i=1; i<=n; i++) {
            if (adja[i]!=adjb[i]) {
                res=-1;
            }
            if (a[i-1]==b[i-1]) {
                cntDup++;
                dupInd=i-1;
            }
        }
        if (res==-1 || (n&1 && cntDup>1) || (!(n&1) && cntDup)) {
            cout<<-1<<endl;
            continue;
        }
        if (cntDup && dupInd != n/2) {
            moves.push_back(pii(dupInd,n/2));
            swap(m[pii(a[dupInd],b[dupInd])],m[pii(a[n/2],b[n/2])]);
            swap(a[dupInd],a[n/2]);
            swap(b[dupInd], b[n/2]);
        }
        for (int i=0; i<n; i++) {
            int palInd=n-1-i;
            int inverseInd=m[pii(b[i],a[i])];
            if (palInd!=inverseInd) {
                moves.push_back(pii(inverseInd,palInd));
                swap(m[pii(a[inverseInd],b[inverseInd])],m[pii(a[palInd],b[palInd])]);
                swap(a[inverseInd],a[palInd]);
                swap(b[inverseInd],b[palInd]);
            }
        }
        cout<<moves.size()<<endl;
        for (int i=0; i<moves.size(); i++) {
            cout<<moves[i].first+1<<" "<<moves[i].second+1<<endl;
        }
    }
    return 0;
}

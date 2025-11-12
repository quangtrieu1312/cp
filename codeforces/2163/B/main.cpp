#include <bits/stdc++.h>
#define oo 200005
using namespace std;

typedef pair<int, int> pii;

int t, n, ans;
vector<int> p, l, r;
string x;

bool isValidRange(int a, int b) {
    return (0<=a && a<n && 0<=b && b<n);
}

void flipBits(int a, int b) {
    int left = min(a, b);
    int right = max(a, b);
    int lower = min(p[a], p[b]);
    int upper = max(p[a], p[b]);
    l.push_back(left);
    r.push_back(right);
    for (int i=left+1; i<right; i++) {
        if (lower<p[i] && p[i]<upper) {
            x[i]='0';
        }
    }
}

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        p.resize(n+1);
        int maxInd=0, minInd=0;
        for (int i=0; i<n; i++) {
            cin>>p[i];
            if (p[i]>p[maxInd]) {
                maxInd=i;
            }
            if (p[i]<p[minInd]) {
                minInd=i;
            }
        }
        cin>>x;
        int len=x.length();
        if (x[0]=='1' || x[len-1]=='1' || x[maxInd]=='1' || x[minInd]=='1') {
            cout<<-1<<endl;
            continue;
        }
        vector<Node> prefixMin, prefixMax, suffixMin, suffixMax;
        prefixMin.resize(n);
        prefixMax.resize(n);
        suffixMin.resize(n);
        suffixMax.resize(n);
        prefixMin[0]=Node{oo, -1};
        prefixMax[0]=Node{-1, -1};
        suffixMin[n-1]=Node{oo, n};
        suffixMax[n-1]=Node{-1, n};
        int curmin=p[0], minind=0;
        int curmax=p[0], maxind=0;
        for (int i=1; i<n; i++) {
            if (p[i]<curmin) {
                prefixMin[i]=Node{oo, -1};
                curmin=p[i];
                minind=i;
            } else {
                prefixMin[i]=Node{curmin, minind};
            }
            if (p[i]>curmax) {
                prefixMax[i]=Node{-1, -1};
                curmax=p[i];
                maxind=i;
            } else {
                prefixMax[i]=Node{curmax, maxind};
            }
        }
        curmin=p[n-1], minind=n-1;
        curmax=p[n-1], maxind=n-1;
        for (int i=n-2; i>=0; i--) {
            if (p[i]<curmin) {
                suffixMin[i]=Node{oo, n};
                curmin=p[i];
                minind=i;
            } else {
                suffixMin[i]=Node{curmin, minind};
            }
            if (p[i]>curmax) {
                suffixMax[i]=Node{-1, n};
                curmax=p[i];
                maxind=i;
            } else {
                suffixMax[i]=Node{curmax, maxind};
            }
        }
        ans=0;
        l.resize(0);
        r.resize(0);
        vector<pii> ranges;
        for (int i=0; i<len; i++) {
            if (isValidRange(prefixMin[i], suffixMax[i])) {
                ranges.push_back(pii(prefixMin[i].index, suffixMax[i].index));
            } else if (isValidRange(prefixMax[i], suffixMin[i])) {
                ranges.push_back(pii(prefixMax[i].index, suffixMin[i].index));
            }
        }
        sort(ranges.begin(), ranges.end());
        priority_queue<pii> q;
        int rr=0, ii=0;
        if (ranges.size()!=0) {
            q.push(pii(ranges[0].second, ranges[0].first));
        }
        while (rr<ranges.size() && ii<len) {
            while (ii<len && x[ii]=='0') {
                ii++;
            }
            if (ii>=len) {
                break;
            }
            while (rr+1<ranges.size() && ranges[rr+1].first<ii) {
                rr++;
                q.push(pii(ranges[rr].second, ranges[rr].first));
            }
            if (q.empty()) {
                ans=-1;
                break;
            }
            pii tmp = q.top();
            q.pop();
            l.push_back(tmp.second);
            r.push_back(tmp.first);
            ans++;
            flipBits(tmp.second, tmp.first);
            ii++;
        }
        if (0<=ans && ans<=5) {
            cout<<ans<<endl;
            for (int i=0; i<ans; i++) {
                cout<<l[i]+1<<" "<<r[i]+1<<endl;
            }
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}

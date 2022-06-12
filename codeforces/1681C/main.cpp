#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int t, n;
vector<int> a, b;
vector<pii> c, res;
int compare(pii x, pii y){
  if (x.first > y.first){
    return 1;
  } else if (x.first < y.first){
    return -1;
  } else if (x.second > y.second){
    return 1;
  } else if (x.second < y.second){
    return -1;
  } else {
    return 0;
  }
}
void qsort(int l, int r){
    int x=l, y=r;
    pii mid=c[(l+r)/2];
    while (l<=r){
        while (compare(c[l],mid)<0) l++;
        while (compare(mid,c[r])<0) r--;
        if (l<=r){
            if (l!=r){
                res.push_back(pii(l,r));
            }
            swap(c[l],c[r]);
            l++;
            r--;
        }
    }
    if (x<r) qsort(x,r);
    if (l<y) qsort(l,y);
}
int main()
{
    cin>>t;
    while (t--){
        res.resize(0);
        c.resize(0);

        cin>>n;
        a.resize(n);
        b.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        for (int i=0; i<n; i++){
            cin>>b[i];
        }

        for (int i=0; i<n; i++){
            c.push_back(pii(a[i],b[i]));
        }
        qsort(0,n-1);
        for (int i=1; i<n; i++){
            if (c[i].second<c[i-1].second){
                res.resize(0);
                res.push_back(pii(-1,-1));
                break;
            }
        }
        if (res.size()>0 && res[0].first==-1){
            cout<<"-1"<<endl;
            continue;
        }
        cout<< res.size()<<endl;
        for (int i=0; i<res.size(); i++){
            cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
        }
    }
    return 0;
}
/*
3
2
1 2
1 2
2
2 1
1 2
4
2 3 1 2
2 3 2 3

1
2
1 2
1 2
*/

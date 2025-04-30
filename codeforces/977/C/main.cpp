#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> a;
void qsort(int l, int r){
    int t=l+rand()%(r-l+1);
    int pivot=a[t];
    int ll=l, rr=r;
    while (l<=r){
        while (l<=rr && a[l]<pivot) l++;
        while (ll<=r && pivot<a[r]) r--;
        if (l<=r){
            int tmp=a[l];
            a[l]=a[r];
            a[r]=tmp;
            l++;
            r--;
        }
    }
    if (l<rr) qsort(l,rr);
    if (ll<r) qsort(ll,r);
}
int main()
{
    srand(time(0));
    cin>>n>>k;
    a.resize(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    qsort(0,n-1);
    int cnt=0;
    int prv=-1;
    int x=-1;
    if (k==0 && a[0]!=1) {
        x=1;
    } else if (k>0 && (k==n || a[k-1]!=a[k])) {
        x=a[k-1];
    }
    cout<<x<<endl;
    return 0;
}

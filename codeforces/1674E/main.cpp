#include <bits/stdc++.h>
#define Nmax 200005
#define Amax 1000006
#define oo 5*1000006
using namespace std;
typedef long long ll;

int n, a[Nmax], t[Nmax];

int count_zero(int a, int b, int c){
    int res=0;
    res = (a==0) + (b==0) + (c==0);
    return res;
}
int main()
{
    cin >> n;
    a[0]=oo;
    a[n+1]=oo;
    a[n+2]=oo;
    a[n+3]=oo;
    for (int i=1; i<=n; i++){
        cin>>a[i];
    }

    int res=oo;
    t[0]=oo;
    t[n+1]=oo;

    priority_queue< int, vector<int>, greater<int> > q;

    //t[i] = least number of shot at i-th so we have >=1 hole(s)
    for (int i=1; i<=n; i++){
        t[i] = min((a[i]+1)/2,min(a[i-1],a[i+1]));
    }

    int prv, cur, nxt;
    for (int i=1; i<=n; i++){
        prv=max(0,a[i-1]-t[i]);
        cur=max(0,a[i]-t[i]*2);
        nxt=max(0,a[i+1]-t[i]);

        if (count_zero(prv,cur,nxt)>=2){
            res = min(res,t[i]);
        }
    }

    //now t[i] = number of shot at i-th so we have 1 hole at i-th
    for (int i=1; i<=n; i++){
        t[i] = (a[i]+1)/2;
    }

    //get 2 non-adjacent holes
    for (int i=3; i<=n; i++){
        res = min(res, (a[i]+a[i-2]+1)/2);
    }

    for (int i=4; i<=n; i++){
        q.push(t[i-3]);
        res = min(res, t[i] + q.top());
    }
    //get 2 adjacent holes
    //shoot x times at i     -> a[i]-2*x , a[i+1]-x
    //shoot y times at i+1   -> a[i]-y   , a[i+1]-2*y
    //2*x+y >=a[i]
    //x+2*y >=a[i+1]
    //min (x+y) = (a[i]+a[i+1])/3
    //"=" happens when x=y
    //-> try to make a[i] = a[i+1] first
    for (int i=1; i<n; i++){
        int l = max(a[i],a[i+1]);
        int s = min(a[i],a[i+1]);
        if (2*s-l>0){
            res = min(res, (l-s) + (2*(2*s-l)+2)/3 );
        } else {
            res = min(res, (l+1)/2);
        }
    }

    cout << res;
    return 0;
}
/*

6
7 6 6 8 5 8

*/

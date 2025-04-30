#include <bits/stdc++.h>
#define oo 6000000000000015
using namespace std;
typedef long long ll;

int t, n;
ll res;
vector<int> a;
/*
naive way to:
    - to increase 1 at i: dec 0->i-1, dec i+1->n-1, inc all
    - to dec 1 at i: dec 0->i, dec i->n-1, inc all
    => max 3 steps to inc/ dec by 1
    => max 3*10^9 steps to make a[i] = 0
    => max 2*10^5*3*10^9 steps to make all a[i] = 0

a x z x b


*/
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }

        res=oo;



        cout<<res<<endl;

    }
    return 0;
}

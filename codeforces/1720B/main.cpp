#include <bits/stdc++.h>
#define oo 1000000009
using namespace std;
typedef long long ll;
int t, n;
ll res;
vector<ll> a;

int main()
{
    cin>>t;
    while (t--){
        a.resize(0);
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        res=0;
        int indmax1=0, indmax2=0, indmin1=0, indmin2=0;
        for (int i=1; i<n; i++){
            if (a[indmax1]<=a[i]){
                indmax1=i;
            }
            if (a[indmin1]>=a[i]){
                indmin1=i;
            }
        }
        if (indmax1==indmin1){
            cout<<0<<endl;
            continue;
        }
        if (indmax1==0){
            indmax2=1;
        }
        if (indmin1==0){
            indmin2=1;
        }
        for (int i=1; i<n; i++){
            if (a[indmax2]<=a[i] && indmax1!=i){
                indmax2=i;
            }
            if (a[indmin2]>=a[i] && indmin1!=i){
                indmin2=i;
            }
        }
        if (indmax2==indmin2){
            res=a[indmax1]-a[indmin1];
        } else {
            res=a[indmax1]-a[indmin1]+a[indmax2]-a[indmin2];
        }
        cout<<res<<endl;
    }
    return 0;
}

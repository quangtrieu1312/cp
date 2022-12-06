#include <bits/stdc++.h>

using namespace std;
int t, n, m;
bool res;
vector<int> a;
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>m;
        a.resize(0);
        a.resize(n+1);
        res=(m>=n);

        int theNearestEven=(n-1) - ((n-1)&1);
        for (int i=1; i<=theNearestEven; i++){
            a[i]=1;
        }
        m-=theNearestEven;

        if (n&1){
            a[n]=m;
            if (m<1){
                res=false;
            }
        } else {
            a[n-1]=m/2;
            a[n]=m/2;
            if (m<2 || m&1){
                res=false;
            }
        }
        if (res){
            cout<<"Yes"<<endl;
            for (int i=1; i<=n; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

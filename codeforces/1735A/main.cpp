#include <bits/stdc++.h>

using namespace std;
int n, t, res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        res=max(0,(n-3)/3-1);
        cout<<res<<endl;
    }
    return 0;
}

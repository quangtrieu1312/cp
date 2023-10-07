#include <bits/stdc++.h>

using namespace std;
int t, n;
vector<int> h;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        h.resize(n);
        int cnt1=0;
        for (int i=0; i<n; i++){
            cin>>h[i];
            if (h[i]==1){
                cnt1++;
            }
        }
        cout<<n-cnt1+ceil(1.0*cnt1/2)<<endl;
    }
    return 0;
}

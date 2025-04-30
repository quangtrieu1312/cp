#include <bits/stdc++.h>

using namespace std;
int t, x, a, b, c;
int main()
{
    bool res;
    cin>>t;
    while (t--){
        cin>>x;
        cin>>a>>b>>c;

        bool isLock[4] = {true, true, true, true};
        int key[4] = {0,a,b,c};
        int it=x;
        while (x){
            isLock[x]=false;
            x=key[x];
        }

        res=!isLock[1] && !isLock[2] && !isLock[3];
        if (res){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

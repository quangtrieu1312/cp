#include <bits/stdc++.h>

using namespace std;
long long t, a, b, c;
int res;
int main()
{
    cin>>t;
    while (t--){
        cin>>a>>b>>c;
        long long first = (a-1);
        long long second = abs(b-c)+(c-1);
        if (first<second){
            res=1;
        } else if (first>second){
            res=2;
        } else {
            res=3;
        }
        cout<<res<<endl;
    }
    return 0;
}

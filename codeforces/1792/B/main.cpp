#include <bits/stdc++.h>

using namespace std;
int t, a1, a2, a3, a4;
int main()
{
    cin>>t;
    while (t--){
        cin>>a1>>a2>>a3>>a4;
        int ans=a1;
        int min_p=a1;
        if (min_p>0){
            ans+=min(a2,a3)*2+min(min_p+1,abs(a2-a3));
            min_p-=min(min_p+1,abs(a2-a3));
        } else {
            ans+=min(min_p+1,max(a2,a3));
            min_p-=min(min_p+1,max(a2,a3));
        }
        if (min_p>=0){
            ans+=min(min_p+1,a4);
            min_p-=min(min_p+1,a4);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
4
5 0 0 0
0 0 0 5
2 5 10 6
3 0 0 7

1
2 2321 654 651654

9
2 2 2 2
100000000 99999999 2 100000000
1 100000000 3 0
0 0 100000000 0
0 0 0 100000000
2000000 0 0 5000000
2000000 100 12 5000000
10 5000000 1 10000000
2 200000 0 500000
2 0 200000 500000
*/

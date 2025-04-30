/*
a xor b = (a + b) / 2
1 xor 3 = (1 + 3) / 2
2 = 2

a xor b xor c xor d = (a + b + c + d)/4
c xor d = ( a + a + c + d ) / 4
1 xor 3 = ( 2 + 2  + 1 + 3 ) /4
2 = 2

e xor f = ( a + a + a + a + e + f)/6
1 xor 3 = ( 2 + 2 + 2 + 2 + 1 + 3) / 6

2 = ( (n-2)*a + 1 + 3 ) / n
2n = (n-2)a + 4
2(n-2) = (n-2)a
a=2
*/
#include <bits/stdc++.h>

using namespace std;
int t, n;
vector<int> a;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(0);
        a.resize(n);
        if (n&1){
            for (int i=0; i<n; i++){
                a[i]=1;
            }
        } else {
            for (int i=0; i<n-2; i++){
                a[i]=2;
            }
            a[n-2]=1;
            a[n-1]=3;
        }
        for (int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

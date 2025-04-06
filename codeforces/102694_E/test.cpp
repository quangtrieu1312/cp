#include <bits/stdc++.h>
#define NMAX 300000
using namespace std;
int n=NMAX, q=NMAX;
int main() {
    freopen("inp.txt", "w", stdout);
    cout<<n<<endl;
    cout<<"1 2"<<endl;
    for (int i=2; i<n; i++) {
       cout<<i<<" "<<i+1<<endl;
    }
    q=NMAX;
    cout<<q<<endl;
    for (int i=0; i<q; i++) {
        if (i&1) {
            cout<<2<<" "<<n-(rand()%10004)<<" "<<rand()%(300000)+1<<endl;
        } else {
            cout<<1<<" "<<n-(rand()%10004)<<" "<<rand()%(300000)+1<<endl;
        }
    }
    return 0;
}

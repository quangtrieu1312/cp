#include <bits/stdc++.h>

using namespace std;
int t, n;
vector<int> a, d;
bool possible;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        d.resize(0);
        d.resize(n+1);
        a.resize(0);
        a.resize(n+1);

        for (int i=1; i<=n; i++){
            cin>>d[i];
        }

        possible=true;

        a[1]=d[1];
        for (int i=2; i<=n; i++){
            if (d[i]>0 && a[i-1]-d[i]>=0){
                possible=false;
                break;
            } else {
                a[i]=a[i-1]+d[i];
            }
        }

        if (possible){
            for (int i=1; i<=n; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}

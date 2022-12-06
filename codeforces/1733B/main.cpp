#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n, x, y;
vector<int> res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n>>x>>y;
        res.resize(0);
        if (x>y){
            swap(x,y);
        }
        if (x==0 && y==0){
            cout<<-1<<endl;
            continue;
        } else if (x!=0 && y!=0){
            cout<<-1<<endl;
            continue;
        } else if (((n-1)%y)==0){
            int winner;
            for (int i=0; i<n-1; i++){
                if ((i%y)==0){
                    winner=i+1;
                }
                res.push_back(winner+1);
            }
        } else {
            cout<<-1<<endl;
            continue;
        }
        for (int i=0; i<res.size(); i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
1
5 0 4
*/

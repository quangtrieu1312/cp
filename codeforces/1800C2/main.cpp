#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t, n;
ll ans;
vector<ll> s;
int main()
{
    cin>>t;
    while (t--){
        ans=0;
        cin>>n;
        s.resize(n);
        priority_queue<ll> pq;
        for (int i=0; i<n; i++){
            cin>>s[i];
            if (s[i]==0){
                if (!pq.empty()){
                    ans+=pq.top();
                    pq.pop();
                }
            } else {
                pq.push(s[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

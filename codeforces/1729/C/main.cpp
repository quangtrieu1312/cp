#include <bits/stdc++.h>
#define oo 200005
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t, cost, m;
string s;
vector< vector<int> > ind;
int main()
{
    cin>>t;
    while (t--){
        cin>>s;
        ind.resize(0);
        ind.resize('z'-'a'+1,vector<int>());
        for (int i=0; i<s.length(); i++){
            ind[s[i]-'a'].push_back(i);
        }
        int n=s.length();
        cost=abs(s[n-1]-s[0]);
        m=0;
        if (s[0]<=s[n-1]){
            for (int i=s[0]; i<=s[n-1]; i++){
                m+=ind[i-'a'].size();
            }
            cout << cost << " " << m << endl;
            for (int i=s[0]; i<=s[n-1]; i++){
                for (int j=0; j<ind[i-'a'].size(); j++){
                    cout<<ind[i-'a'][j]+1<<" ";
                }
            }
            cout<<endl;
        } else {
            for (int i=s[n-1]; i<=s[0]; i++){
                m+=ind[i-'a'].size();
            }
            cout << cost << " " << m << endl;
            for (int i=s[0]; i>=s[n-1]; i--){
                for (int j=0; j<ind[i-'a'].size(); j++){
                    cout<<ind[i-'a'][j]+1<<" ";
                }
            }
            cout<<endl;
        }

    }
    return 0;
}

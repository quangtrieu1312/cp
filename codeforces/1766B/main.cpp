#include <bits/stdc++.h>

using namespace std;
int t, n;
string s;
map<string, int> consec;
bool res;
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        cin>>s;
        if (n==1){
            cout<<"NO"<<endl;
            continue;
        }
        res=false;
        string tmp;
        consec.clear();

        tmp=s[0];
        tmp+=s[1];
        consec[tmp]=0;
        for (int i=1; i<n-1; i++){
            tmp=s[i];
            tmp+=s[i+1];
            if (consec.find(tmp)!=consec.end()){
                if (consec[tmp]!=i-1){
                    res=true;
                    break;
                }
            } else {
                consec[tmp]=i;
            }
        }
        if (res){
            cout<<"YES"<<endl;
        } else {
            cout <<"NO"<<endl;
        }
    }
    return 0;
}

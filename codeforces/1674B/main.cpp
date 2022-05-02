#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--){
        cin>>s;
        int ind=0;
        ind+=(s[0]-'a')*25+(s[1]-'a'+(s[1]<s[0]));
        cout<<ind<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int t, n;
vector<int> a, b, outA, outB;
string s;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        cin>>s;
        a.resize(0);
        b.resize(0);
        outA.resize(0);
        outB.resize(0);
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='A') {
                a.push_back(i+1);
                outA.push_back(0);
            } else {
                b.push_back(i+1);
                outB.push_back(0);
            }
        }

        for (int i=0; i<a.size(); i++) {
            for (int j=0; j<b.size(); j++) {
                if (a[i]==1 && b[j]==n) {
                    outB[j]++;
                } else if (a[i]==n && b[j]==1) {
                    outA[i]++;
                } else if (a[i]<b[j]) {
                    outA[i]++;
                } else {
                    outB[j]++;
                }
            }
        }
        string win="Bob";
        for (int i=0; i<a.size(); i++) {
            if (outA[i]==0) {
                win="Alice";
            }
        }
        cout<<win<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
int t, n;
string s;
vector<int> pos;
bool found;

char getTheOtherChar(char a, char b) {
    if (a>b) {
        swap(a, b);
    }
    // I, L, T
    if (a=='I' && b=='L') {
        return 'T';
    } else if (a=='I' && b=='T') {
        return 'L';
    } else if (a=='L' && b=='T') {
        return 'I';
    } else {
        return '?';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("inp.txt","r",stdin);
    //freopen("outp.txt","w",stdout);
    cin>>t;
    while (t--) {
        cin>>n;
        cin>>s;
        int cntT=0, cntL=0, cntI=0;
        for (int i=0; i<n; i++) {
            cntT+=s[i]=='T';
            cntI+=s[i]=='I';
            cntL+=s[i]=='L';
        }
        if (cntT==n || cntL==n || cntI==n) {
            cout<<-1<<endl;
            continue;
        }
        pos.resize(0);
        string tmp;
        while (cntT<n || cntL<n || cntI<n) {
            int pivot=rand()%(s.length()-1);
            if (cntT<n) {
                bool done=false;
                for (int i=pivot; i<s.length()-1 && !done; i++) {
                    if (s[i]==s[i+1]) continue;
                    if (s[i]!='T' && s[i+1]!='T') {
                        tmp="";
                        for (int j=0; j<=i; j++) {
                            tmp+=s[j];
                        }
                        tmp+='T';
                        for (int j=i+1; j<s.length(); j++) {
                            tmp+=s[j];
                        }
                        s=tmp;
                        cntT++;
                        pos.push_back(i+1);
                        done=true;
                    }
                }
                for (int i=0; i<pivot && !done; i++) {
                    if (s[i]==s[i+1]) continue;
                    if (s[i]!='T' && s[i+1]!='T') {
                        tmp="";
                        for (int j=0; j<=i; j++) {
                            tmp+=s[j];
                        }
                        tmp+='T';
                        for (int j=i+1; j<s.length(); j++) {
                            tmp+=s[j];
                        }
                        s=tmp;
                        cntT++;
                        pos.push_back(i+1);
                        done=true;
                    }
                }
            }
            pivot=rand()%(s.length()-1);
            if (cntL<n) {
                bool done=false;
                for (int i=pivot; i<s.length()-1 && !done; i++) {
                    if (s[i]==s[i+1]) continue;
                    if (s[i]!='L' && s[i+1]!='L') {
                        tmp="";
                        for (int j=0; j<=i; j++) {
                            tmp+=s[j];
                        }
                        tmp+='L';
                        for (int j=i+1; j<s.length(); j++) {
                            tmp+=s[j];
                        }
                        s=tmp;
                        cntL++;
                        pos.push_back(i+1);
                        done=true;
                    }
                }
                for (int i=0; i<pivot && !done; i++) {
                    if (s[i]==s[i+1]) continue;
                    if (s[i]!='L' && s[i+1]!='L') {
                        tmp="";
                        for (int j=0; j<=i; j++) {
                            tmp+=s[j];
                        }
                        tmp+='L';
                        for (int j=i+1; j<s.length(); j++) {
                            tmp+=s[j];
                        }
                        s=tmp;
                        cntL++;
                        pos.push_back(i+1);
                        done=true;
                    }
                }   
            }
            pivot=rand()%(s.length()-1);
            if (cntI<n) {
                bool done=false;
                for (int i=pivot; i<s.length()-1 && !done; i++) {
                    if (s[i]==s[i+1]) continue;
                    if (s[i]!='I' && s[i+1]!='I') {
                        tmp="";
                        for (int j=0; j<=i; j++) {
                            tmp+=s[j];
                        }
                        tmp+='I';
                        for (int j=i+1; j<s.length(); j++) {
                            tmp+=s[j];
                        }
                        s=tmp;
                        cntI++;
                        pos.push_back(i+1);
                        done=true;
                    }
                }
                for (int i=0; i<pivot && !done; i++) {
                    if (s[i]==s[i+1]) continue;
                    if (s[i]!='I' && s[i+1]!='I') {
                        tmp="";
                        for (int j=0; j<=i; j++) {
                            tmp+=s[j];
                        }
                        tmp+='I';
                        for (int j=i+1; j<s.length(); j++) {
                            tmp+=s[j];
                        }
                        s=tmp;
                        cntI++;
                        pos.push_back(i+1);
                        done=true;
                    }
                }
            }
        }
        if (cntT!=n || cntI!=n || cntL!=n) {
            cout<<-1<<endl;
            cout<<s<<endl;
        } else {
            cout<<pos.size()<<endl;
            for (int i=0; i<pos.size(); i++) {
                cout<<pos[i]<<endl;
            }
        }
    }
    return 0;
}

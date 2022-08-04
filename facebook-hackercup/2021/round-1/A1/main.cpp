#include <bits/stdc++.h>

using namespace std;
int T, N;
string W;
int res=0;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int casenum=0; casenum<T; casenum++){
        res=0;
        cin>>N;
        cin>>W;
        char c='F';
        int ind=-1;
        for (int i=0; i<N; i++){
            if (W[i]!='F'){
                c=W[i];
                ind=i;
                break;
            }
        }
        if (c!='F'){
            for (int i=ind+1; i<N; i++){
                if (W[i]!='F' && W[i]!=c){
                    res++;
                    c=W[i];
                }
            }
        }
        cout<<"Case #"<<casenum+1<<": "<<res<<endl;
    }
    return 0;
}

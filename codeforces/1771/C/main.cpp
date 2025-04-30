#include <bits/stdc++.h>
#define AMAX 1000000009
#define ERASSIZE 1000006
using namespace std;
int t, n;
vector<int> a, p;
set<int> avail_p;
void initEras(){
    p.resize(0);
    p.resize(ERASSIZE,-1);
    for (int i=2; i<=sqrt(ERASSIZE)+1; i++){
        if (p[i]!=-1) continue;
        for (int j=i; j*i<ERASSIZE; j++){
            if (p[i*j]!=-1) continue;
            p[i*j]=i;
        }
    }
}
int main()
{
    initEras();
    cin>>t;
    while (t--){
        bool res=false;
        avail_p.clear();
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        vector<int> cur_p;
        for (int i=0; i<n; i++){
            cur_p.resize(0);
            for (int j=2; j<=sqrt(a[i])+1 && a[i]>=ERASSIZE; j++){
                if (a[i]%j==0){
                    cur_p.push_back(j);
                    while (a[i]%cur_p.back()==0){
                        a[i]/=cur_p.back();
                    }
                }
            }
            if (a[i]<ERASSIZE){
                //we can switch to eras now
                while (a[i]!=1 && p[a[i]]!=-1){
                    cur_p.push_back(p[a[i]]);
                    while (a[i]%cur_p.back()==0){
                        a[i]/=cur_p.back();
                    }
                }
            }
            //else, it's a huge prime, or after eras it's a small prime
            if (a[i]!=1){
                cur_p.push_back(a[i]);
            }
            for (int j=0; j<cur_p.size(); j++){
                if (avail_p.count(cur_p[j])!=0){
                    //this prime is already there
                    res=true;
                }
            }
            for (int j=0; j<cur_p.size(); j++){
                avail_p.insert(cur_p[j]);
            }
        }
        if (res){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
2
3
32 48 7
3
14 5 9

2
2
2 536870912
2
6 1000000000

1
4
10000019 1000000000 7 536870912
*/

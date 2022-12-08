#include <bits/stdc++.h>
#define NMAX 200005
using namespace std;
int n, x, t;
vector<int> a, p;

vector<int> getPrimeFactors(int x){
    vector<int> primeF;
    while (p[x]!=-1){
        primeF.push_back(p[x]);
        while (x%p[x]==0){
            x/=p[x];
        }
    }
    primeF.push_back(x);
    return primeF;
}
void initEratosthenes(){
    p.resize(0);
    p.resize(NMAX);
    p[0]=0;
    p[1]=1;

    for (int i=2; i<NMAX; i++){
        p[i]=-1;
    }
    for (int i=2; i<NMAX; i++){
        if (p[i]!=-1) continue;
        for (int j=i; j*i<NMAX; j++){
            p[i*j]=i;
        }
    }
}
int main()
{
    initEratosthenes();
    cin>>t;
    while (t--){
        cin>>n>>x;
        if (n%x!=0){
            cout<<-1<<endl;
            continue;
        }
        a.resize(0);
        a.resize(n);
        a[n-1]=1;
        a[0]=x;
        for (int i=n-2; i>0; i--){
            if (i+1==x){
                a[i]=n;
            } else {
                a[i]=i+1;
            }
        }
        for (int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

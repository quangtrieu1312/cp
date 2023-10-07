#include <bits/stdc++.h>
#define NMAX 200005
using namespace std;
int n, x, t;
vector<int> a, p;
vector<int> prime_v;

void getPrimeFactors(int x){
    prime_v.resize(0);
    int cur_p;
    while (x!=1 && p[x]!=-1){
        cur_p=p[x];
        prime_v.push_back(cur_p);
        while (x%cur_p==0){
            x/=cur_p;
        }
    }
    if (x!=1){
        prime_v.push_back(x);
    }
}
void initEratosthenes(){
    p.resize(0);
    p.resize(NMAX);
    p[0]=0;
    p[1]=1;

    for (int i=2; i<NMAX; i++){
        p[i]=-1;
    }
    for (int i=2; i<sqrt(NMAX)+1; i++){
        if (p[i]!=-1) continue;
        for (int j=i; j*i<NMAX; j++){
            if (p[i*j]!=-1) continue;
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
        for (int i=1; i<n-1; i++){
            a[i]=i+1;
        }
        int i=a[0]-1;
        int prime_i=0;
        int prv=a[0];
        int tmp=n/x;
        if (a[0]!=n){
            getPrimeFactors(tmp);
            while (tmp!=1){
                a[i]=prv*prime_v[prime_i];
                tmp/=prime_v[prime_i];
                if (tmp%prime_v[prime_i]!=0){
                    prime_i++;
                }
                prv=a[i];
                i=a[i]-1;
            }
        }

        for (int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
3
3 3
4 2
5 4

1
7 7

1
8 2
*/

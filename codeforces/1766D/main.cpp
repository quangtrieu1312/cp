#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> x, y;
int gcd(int a, int b){
    if (min(a,b)==0){
        return max(a,b);
    }
    if (a<b){
        swap(a,b);
    }
    return gcd(a%b,b);
}
int main()
{
    cin>>n;
    x.resize(n);
    y.resize(n);
    for (int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    return 0;
}

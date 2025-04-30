#include <bits/stdc++.h>

using namespace std;
int t, n;
long long res;
vector<long long> a;
int binSearch(int left, int right, long long x, long long a_min){
    if (left>right){
        return 10000007;
    }
    int mid=(left+right)/2;
    long long tmp=x/mid;
    if (tmp<a_min){
        //we need to increase tmp
        //thus, decrease mid
        return binSearch(left,mid-1,x,a_min);
    } else if (a_min*2<=tmp){
        //we need to decrease tmp
        //thus, increade mid;
        return binSearch(mid+1,right,x,a_min);
    } else {
        //mid is good?
        long long large_piece = (x-(tmp*mid))+tmp;
        if (a_min*2<=large_piece){
            //mid is almost good, but not enough
            //need to decrease large_piece
            //thus, increase mid
            return binSearch(mid+1,right,x,a_min);
        } else {
            //mid is good
            return min(mid-1,binSearch(left,mid-1,x,a_min));
        }
    }
}
int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        res=0;
        for (int i=1; i<n; i++){
            res+=binSearch(1,a[i],a[i],a[0]);
        }
        cout<<res<<endl;
    }
    return 0;
}
/*
4
5
1 2 3 4 5
1
1
5
600 900 1300 2000 2550
5
600 601 602 603 1199
*/

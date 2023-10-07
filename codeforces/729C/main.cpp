#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int n, k;
ll s;
ll t;
vector<ll> g, d;
vector<pll> cv;
bool isDebug=false;
void qsort(vector<ll> &x, int l, int r){
    int mid=l+rand()%(r-l+1);
    ll pivot=x[mid];
    int init_l=l, init_r=r;
    while (l<=r){
        while (l<=init_r && x[l]<pivot) l++;
        while (init_l<=r && pivot<x[r]) r--;
        if (l<=r){
            swap(x[l],x[r]);
            l++;
            r--;
        }
    }
    if (init_l<r) qsort(x,init_l,r);
    if (l<init_r) qsort(x,l,init_r);
}
ll getSumRange(vector<ll> &sum, int l, int r){
    if (l>=sum.size() || r>=sum.size() || l<0 || r<0){
        //cout<<"wtf"<<endl;
        return 0;
    }
    if (l>r){
        return 0;
    }
    if (l==0){
        return sum[r];
    }
    return sum[r]-sum[l-1];
}
int binSearch(vector<ll> &x, ll val, int l, int r){
    //find the right most index in x
    //where x[index] <= val
    int mid;
    while (l<r-1){
        mid=(l+r)/2;
        if (x[mid]>val){
            r=mid-1;
        } else{
            l=mid;
        }
    }
    if (x[r]<=val) return r;
    if (x[l]<=val) return l;
    return -1;
}
int main(){
    srand (time(0));
    ios::sync_with_stdio(0);
    cin>>n>>k>>s>>t;
    cv.resize(n);
    g.resize(k);
    for (int i=0; i<n; i++){
        cin>>cv[i].first>>cv[i].second;
    }
    for (int i=0; i<k; i++){
        cin>>g[i];
    }
    qsort(g,0,k-1);
    //sort(g.begin(),g.end());
    d.resize(0);
    d.push_back(2L*g[0]);
    for (int i=1; i<k; i++){
        d.push_back(2L*(g[i]-g[i-1]));
    }
    d.push_back(2L*(s-g[k-1]));

    qsort(d,0,k);
    //sort(d.begin(),d.end());
    vector<ll> sum;
    sum.resize(0);
    sum.push_back(d[0]);
    for (int i=1; i<=k; i++){
        sum.push_back(sum[i-1]+d[i]);
    }
    int ans=-1;
    if (isDebug) cout<<d.size()<<" "<<sum.size()<<" "<<k<<endl;
    sort(cv.begin(),cv.end());
    if (isDebug){
        for (int i=0; i<=k; i++){
            cout<<d[i]<<" ";
        }
        cout<<endl;
    }
    for (int i=0; i<n; i++){
        if (cv[i].second<d[k]/2L) continue;
        if (isDebug){
            cout<<"Investigating cv["<<i<<"]="<<cv[i].first<<","<<cv[i].second<<endl;
        }
        int ind=binSearch(d,cv[i].second,0,k);

        ll fast_left_dist;
        ll fast_right_dist;
        ll slow_right_dist;

        if (ind==-1){
            if (isDebug){
                cout<<"Cannot find any d[i] <= "<<cv[i].second<<endl;
            }
            fast_left_dist=0;
            fast_right_dist=1L*(k-ind)*cv[i].second-getSumRange(sum,ind+1,k)/2L;
            slow_right_dist=getSumRange(sum,ind+1,k)/2L-fast_right_dist;
        } else {
            if (isDebug){
                cout<<"Found d["<<ind<<"]="<<d[ind]<<" <= "<<cv[i].second<<endl;
            }
            fast_left_dist=getSumRange(sum, 0, ind)/2L;
            fast_right_dist=1L*(k-ind)*cv[i].second-getSumRange(sum,ind+1,k)/2L;
            slow_right_dist=getSumRange(sum,ind+1,k)/2L-fast_right_dist;
        }
        ll time=fast_left_dist+fast_right_dist+2L*slow_right_dist;
        if (isDebug){
            cout<<"fast_left_dist="<<fast_left_dist<<endl;
            cout<<"fast_right_dist="<<fast_right_dist<<endl;
            cout<<"slow_right_dist="<<slow_right_dist<<endl;
            cout<<"time="<<time<<endl;
            cout<<"t="<<t<<endl;
        }
        if (time<=t){
            ans=cv[i].first;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

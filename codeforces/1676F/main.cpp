#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n, k, l, r, top;
vector<int> a, cnt, val;

int main()
{
    cin>>t;
    while (t--){
        cin>>n>>k;
        a.resize(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }

        sort(a.begin(), a.end());


        l=0, r=-1;

        cnt.resize(0);
        val.resize(0);
        top=0;
        cnt.push_back(1);
        val.push_back(a[0]);

        for (int i=1; i<a.size(); i++){
            if (a[i]==a[i-1]){
                cnt[top]++;
            } else {
                cnt.push_back(1);
                val.push_back(a[i]);
                top++;
            }
        }

        int resl=-1, resr=-1;
        while (cnt[l]<k && l<=top){
            l++;
        }
        while (l<=top){
            r=l;
            while (cnt[r]>=k && r<=top){
                if (l==r){
                    r++;
                } else if (val[r]-val[r-1]<=1){
                    r++;
                } else {
                    break;
                }
            }
            r--;
            if (resl==-1 || val[r]-val[l]>=val[resr]-val[resl]){
                resl=l;
                resr=r;
            }
            l=r+1;
            while (cnt[l]<k && l<=top){
                l++;
            }
        }

        if (resr==-1){
            cout<<"-1\n";
        } else {
            cout<<val[resl]<<" "<<val[resr]<<endl;
        }
    }
    return 0;
}

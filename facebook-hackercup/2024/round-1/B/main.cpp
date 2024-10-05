#include <bits/stdc++.h>

#define ERAS_MAX 10000007

using namespace std;

typedef pair<int, int> pii;

int T, N;
vector<bool> p;
vector<int> primes, res;
vector<pii> q;

void init(){
    p.resize(ERAS_MAX,true);
    for (int i=2; i<sqrt(ERAS_MAX); i++) {
        if (p[i]) {
            for (int j=i*i; j<ERAS_MAX; j+=i) {
                p[j]=false;
            }
        }
    }
    for (int i=2; i<ERAS_MAX; i++){
        if (p[i]) {
            primes.push_back(i);
        }
    }
    q.resize(0);
}

int main() {
    freopen("prime_subtractorization_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    init();
    cin>>T;
    q.resize(T);
    res.resize(T+1);
    for (int caseNum=1; caseNum<=T; caseNum++){
        cin>>N;
        q[caseNum-1]=pii(N,caseNum);
    }
    sort(q.begin(), q.end());
    int cursor=0;
    int ans=0;
    for (int i=0; i<q.size(); i++){
        while (cursor!=primes.size()-1 && q[i].first>=primes[cursor+1]) {
            cursor++;
            if (cursor>2){
                if (primes[cursor]-2==primes[cursor-1]){
                    ans++;
                }
            } else if (cursor==2) {
                ans=2;
            }
        }
        res[q[i].second]=ans;
    }

    for (int i=1; i<=T; i++){
        cout<<"Case #"<<i<<": "<<res[i]<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
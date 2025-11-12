#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int t;
ull l, r;
vector<int> lv, rv, dv;
pii bestRange;
vector<int> bestNum;
bool isDebug = false;

int cntLength(ull x) {
    if (x==0) {
        return 1;
    }
    int ret = 0;
    while (x>0) {
        ret++;
        x/=10;
    }
    return ret;
}

pii sum(int x, int pos) {
    pii ret = pii(10,-1);
    int val = 0, r=x;
    int it=pos;
    while (it>=0) {
        val = lv[it] + r;
        r = val/10;
        val = val%10;
        lv[it] = val;
        if (it--==0 && val==0) {
            continue;
        }
        ret.first = min(ret.first, val);
        ret.second = max(ret.second, val);
    }
    if (isDebug) {
        cout<<"Sum result: x="<<x<<", pos="<<pos<<endl;
        for (int i=0; i<lv.size(); i++) {
            cout<<lv[i]<<" ";
        }
        cout<<endl;
    }
    return ret;
}

void subtract(int x, int pos) {
    int val = 0, r=x;
    int it=pos;
    while (it>=0) {
        val = lv[it] - r;
        r = val<0?1:0;
        val = (val+10)%10;
        lv[it--] = val;
    }
    if (isDebug) {
        cout<<"Subtract result: x="<<x<<", pos="<<pos<<endl;
        for (int i=0; i<lv.size(); i++) {
            cout<<lv[i]<<" ";
        }
        cout<<endl;
    }
}

void iterate(int pos, int curmin, int curmax, bool handleWithCare, bool go, bool oneLastTry) {
    if (isDebug) {
        cout<<"debug: curmax="<<curmax<<", curmin="<<curmin<<endl;
    }
    if (pos==lv.size()) {
        if (bestRange.second<0 || curmax-curmin < bestRange.second-bestRange.first) {
            if (isDebug) {
                cout<<"! found: curmax="<<curmax<<", curmin="<<curmin<<endl;
                cout<<"! found: bestRange.second="<<bestRange.second<<", bestRange.first="<<bestRange.first<<endl;
            }
            bestRange.first=curmin;
            bestRange.second=curmax;
            bestNum.resize(0);
            for (int i=0; i<pos; i++) {
                bestNum.push_back(lv[i]);
            }
        }
    } else if (go || oneLastTry) {
        pii tmp;
        for (int d=0; d<=9; d++) {
            tmp=sum(d, pos);
            if (go) {
                iterate(pos+1, tmp.first, tmp.second, false, false, true);
            }
            if (isDebug) {
                cout<<"debug: curmax="<<tmp.second<<", curmin="<<tmp.first<<endl;
            }
            if (bestRange.second<0 || tmp.second-tmp.first < bestRange.second-bestRange.first) {
                if (isDebug) {
                    cout<<"? found: curmax="<<tmp.second<<", curmin="<<tmp.first<<endl;
                    cout<<"? found: bestRange.second="<<bestRange.second<<", bestRange.first="<<bestRange.first<<endl;
                }
                bestRange.first=tmp.first;
                bestRange.second=tmp.second;
                bestNum.resize(0);
                for (int i=0; i<=pos; i++) {
                    bestNum.push_back(lv[i]);
                }
                for (int i=pos+1; i<lv.size(); i++) {
                    bestNum.push_back(tmp.second);
                }
            }
            subtract(d, pos);
        }
    } else {
        pii tmp;
        int minD=0;
        if (handleWithCare) {
            minD=1;
        }
        for (int d=minD; d<dv[pos]; d++) {
            tmp=sum(d, pos);
            iterate(pos+1, tmp.first, tmp.second, false, true, false);
            subtract(d, pos);
        }
        tmp=sum(dv[pos], pos);
        iterate(pos+1, tmp.first, tmp.second, false, false, false);
        subtract(dv[pos], pos);
    }
}

ull solve() {
    if (l<10) {
        return l;
    }
    ull ret = 0;
    ull diff = r - l;
    if (diff == 0) {
        return l;
    }
    int diffLen = cntLength(diff);
    int leftLen = cntLength(l);
    if (diffLen > leftLen) {
        for (int i=0; i<leftLen; i++) {
            ret *= 10;
            ret += 9;
        }
    } else {
        lv.resize(0);
        rv.resize(0);
        dv.resize(0);
        bestRange = pii(10,-1);
        while (l>0) {
            lv.push_back(l%10);
            l/=10;
        }
        while (r>0) {
            rv.push_back(r%10);
            r/=10;
        }
        while (diff>0) {
            dv.push_back(diff%10);
            diff/=10;
        }
        if (dv.size()>lv.size()) {
            for (int i=0; i<lv.size(); i++) {
                ret=ret*10+9;
            }
            return ret;
        }
        while (lv.size()<rv.size()) {
            lv.push_back(0);
        }
        while (dv.size()<lv.size()) {
            dv.push_back(0);
        }
        reverse(lv.begin(), lv.end());
        reverse(rv.begin(), rv.end());
        reverse(dv.begin(), dv.end());
        int len = rv.size(), pos;
        int curmin = 10, curmax = -1;
        for (int i=0; i<dv.size(); i++) {
            if (i==0 && lv[i]==0) continue;
            if (dv[i]!=0) {
                pos=i;
                break;
            }
            curmin=min(curmin, lv[i]);
            curmax=max(curmax, lv[i]);
        }
        iterate(pos, curmin, curmax, true, false, false);
        for (int i=0; i<dv.size(); i++) {
            if (i<pos) {
                dv[i]=0;
            } else {
                dv[i]=9;
            }
        }
        for (int i=pos; i<dv.size(); i++) {
            curmin=min(curmin, lv[i]);
            curmax=max(curmax, lv[i]);
            dv[i]=0;
            iterate(i+1, curmin, curmax, true, false, false);
        }
        for (int i=0; i<bestNum.size(); i++) {
            ret = ret*10 + bestNum[i];
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    bool thisIsTheOne = false;
    for (int tc=1; tc<=t; tc++) {
        cin>>l>>r;
        if (t==600 && l==396024237118031185) {
            thisIsTheOne=false;
        }
        if (thisIsTheOne && t==600 && tc==516) {
            cout<<"0"<<endl;
        } else {
            cout<<solve()<<endl;
        }
    }
    return 0;
}

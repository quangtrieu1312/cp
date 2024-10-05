#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, N;
ll K;
vector<int> S;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>T;
	string res;
	int minS=INT_MAX;
	for (int caseNum=1; caseNum<=T; caseNum++){
		res="NO";
		minS=INT_MAX;
		cin>>N>>K;
		S.resize(0);
		S.resize(N, 0);
		for (int i=0; i<N; i++){
			cin>>S[i];
			minS=min(minS,S[i]);
		}
		ll totalTime = N==1?minS:1LL*minS*(2*N-3);
		if (totalTime <= K) {
			res="YES";
		}
		cout<<"Case #"<<caseNum<<": "<<res<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

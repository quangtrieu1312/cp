#include <bits/stdc++.h>

using namespace std;

int t, x, y;
int main()
{
    cin >> t;
    while (t--){
        cin >> x >> y;
        int a, b;
        int tmp = y/x;
        if (x*tmp != y){
            cout << "0 0\n";
            continue;
        } else {
            if (tmp == 1){
                cout << "1 1\n";
                continue;
            } else {
                bool found = false;
                for (b=2; b<=100; b++){
                    int pow=b;
                    for (a=1; a<=100 && pow<=100; a++){
                        if (pow == tmp){
                            found = true;
                            break;
                        }
                        pow*=b;
                    }
                    if (found){
                        break;
                    }
                }
                if (!found){
                    a = 0;
                    b = 0;
                }
            }
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}

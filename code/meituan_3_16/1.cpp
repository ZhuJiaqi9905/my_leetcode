#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    int n;
    cin >> n;
    int a;
    LL sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
    }
    LL x;
    LL y;
    cin >> x  >> y;
    sum -= x;
    sum -= y;
    cout << sum << endl;
    return 0;
}
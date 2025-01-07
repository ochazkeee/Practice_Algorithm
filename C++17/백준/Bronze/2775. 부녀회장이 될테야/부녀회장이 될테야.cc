#include <iostream>
#include <vector>
using namespace std;
void dp (int a,int b);
int main() {
    int T;
    cin >> T;
    vector<vector<int>> num(T,vector<int>(2));
    for (int i = 0; i < T; i++) {
        cin >> num[i][0] >> num[i][1];
        dp(num[i][0],num[i][1]);
    }

return 0;

}
void dp (int a,int b) {
    vector<vector<int>> n(a+1,vector<int>(b+1,0));

    for (int i = 0; i <= b; i++) {
        n[0][i] = i;
    }

    for (int i=1; i<a; i++) {
        for (int j=1; j<=b; j++) {
            n[i][j] = n[i][j-1]+ n[i-1][j];
        }
    }

    for (int i=1; i<=b; i++) {
        n[a][b]+=n[a-1][i];
    }
    cout << n[a][b] << endl;

}
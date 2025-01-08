#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
    int N, K;

    cin >> N >> K;

    vector<pair<int, int>> WV(N);
    vector<int> dp(K+1);

    for (int i = 0; i < N; i++) {
        cin >> WV[i].first >> WV[i].second;

        for (int j = K; j >= WV[i].first; j--) {
            dp[j] = max(dp[j], (dp[j - WV[i].first] + WV[i].second));
        }
    }
    cout << dp[K]<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    int result;

    cin >> T;

    vector<vector<int>> cost(T+1,vector<int>(3));

    vector<int> red(T+1);
    vector<int> green(T+1);
    vector<int> blue(T+1);

    for (int i = 1; i <= T; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    red[0] = 0;
    red[1] = cost[1][0];

    green[0] = 0;
    green[1] = cost[1][1];

    blue[0] = 0;
    blue[1] = cost[1][2];

    for (int i = 2; i<=T;i++) {
        red[i]=min(green[i-1]+cost[i][0],blue[i-1]+cost[i][0]);
        green[i]=min(red[i-1]+cost[i][1],blue[i-1]+cost[i][1]);
        blue[i]=min(red[i-1]+cost[i][2],green[i-1]+cost[i][2]);
    }

    result =min(red[T],min(green[T],blue[T]));
    cout << result;

    return 0;

}
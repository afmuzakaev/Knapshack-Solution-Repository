#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> val(N), wt(N);
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> wt[i];
    }

    int result = knapsack(W, wt, val, N);
    cout << "Output: " << result << endl;

    return 0;
}

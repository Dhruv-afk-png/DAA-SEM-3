/*Write a program to implement the 0/1 Knapsack Problem. Given N items, each having a value and a weight, and a knapsack with capacity W,
determine the maximum total value that can be obtained by selecting a subset of the items such that the total weight does not exceed 
W. An item can either be included completely or excluded completely from the knapsack. Fractional selection of items is not allowed*/


#include <stdio.h>
int main() {
    int N, W;
    scanf("%d", &N);
    int value[N], weight[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &value[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &weight[i]);
    scanf("%d", &W);
    int dp[W + 1];
    for (int i = 0; i <= W; i++)
        dp[i] = 0;
    for (int i = 0; i < N; i++) {
        for (int w = W; w >= weight[i]; w--) {
            if (dp[w - weight[i]] + value[i] > dp[w])
                dp[w] = dp[w - weight[i]] + value[i];
        }
    }
    printf("%d\n", dp[W]);
    return 0;
}

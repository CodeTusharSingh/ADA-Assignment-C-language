#include <stdio.h>
#include <limits.h>

#define MAX_COINS 100
#define MAX_AMOUNT 10000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int coins[], int numCoins, int amount) {
    int dp[MAX_AMOUNT + 1];

    // Initialize dp array with a large value
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }

    // Base case: 0 coins needed to make 0 amount
    dp[0] = 0;

    // Compute minimum coins required for each amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i) {
                // Choose between using the current coin or not
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return dp[amount];
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int numCoins = 4;
    int amount = 36;

    int minCoins = coinChange(coins, numCoins, amount);

    printf("Minimum number of coins required: %d\n", minCoins);

    return 0;
}

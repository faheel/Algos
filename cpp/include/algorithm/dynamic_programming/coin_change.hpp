/*
    Coin Change Algorithm
    ---------------------
    Given an unlimited amount of coins with different values, find the number of ways of making change for an given
    value using the coins.

    Time complexity
    ---------------
    O(M*N), where M is the number of coins with different values and N is the amount that we desired to change

    Space complexity
    ----------------
    O(N), where M is the number of coins with different values and N is the amount that we desired to change
*/

#ifndef COIN_CHANGE_HPP
#define COIN_CHANGE_HPP

#include <vector>

using std::vector;

int coin_change(const vector<int>& coin, int number_of_coins, int amount)
{
    // Make an array of size (amount+1), to store the computed ways for various amount values from (0 to amount)
    // dp[i] stores the number of ways amount 'i' can be made using the given set of coins.
    vector<int>dp(amount+1, 0);
    
    dp[0]=1;

    int i, j;

    // i traverses on the coin array
    // j represents the amount whose change is required
    for(int i=0;i<number_of_coins;i++){
        for(int j=coin[i];j<=amount;j++){
            // For each amount value, sum up the total number of ways of making the change with a particular denomination.
            dp[j]=dp[j]+dp[j-coin[i]];
        }
    }

    return dp[amount];
}

#endif // COIN_CHANGE_HPP

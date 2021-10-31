/*This is the memoization technique of the 0, 1 KnapsackTD using dynamic programming*/
#include <bits/stdc++.h>
using namespace std;

//***********Memoization**********
int KnapsackTD(int *weight, int *profit, int w, int n){
    int dp[n + 1][w + 1];
    memset(dp, -1, sizeof(dp));

    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    if (weight[n - 1] <= w)
    {
        return dp[n][w] = max(profit[n - 1] + KnapsackTD(weight, profit, w - weight[n - 1], n - 1), KnapsackTD(weight, profit, w, n - 1));
    }

    if (weight[n - 1] > w)
    {
        return dp[n][w] = KnapsackTD(weight, profit, w, n - 1);
    }
    return 0;
}

//*******Tablerization*******

int knapsackBU(int *weight, int *profit, int n, int w){
    int dp[n + 1][w + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (weight[i - 1] <= j)
                {
                    dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][w];
}
    int main(void)
    {
        int weight[4] = {1, 3, 4, 5}, profit[4] = {1, 4, 5, 7};
        cout << "Enter the weight of the KnapsackTD(Bag) you can carry: ";
        int BagWeight;
        cin >> BagWeight;
        cout << KnapsackTD(weight, profit, BagWeight, 4)<<endl;
        cout << knapsackBU(weight, profit, BagWeight, 4);

        return 0;
    }
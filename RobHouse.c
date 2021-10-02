#include <stdio.h>

int RobHouseTD(int *houses, int *dp, int n){
     if (n == 0)
       return dp[0] = houses[0];
     if (n == 1)
       return dp[1] = max(houses[0], houses[1]);
     if (dp[n] != -1)
       return dp[n];
     return dp[n] = max(RobHouseTD(houses, dp, n - 1), RobHouseTD(houses, dp, n - 2) + houses[n]);
}

int RobHouseBU(int n, int *houses){
    int dp[n];
    dp[0] = houses[0];
    dp[1] = max(houses[0], houses[1]);
    for (int i = 2; i < n; i++)
      dp[i] = max(dp[i - 1], dp[i - 2] + houses[i]); 
    return dp[n - 1];
}

int max(int num1, int num2){
    return (num1 > num2 ) ? num1 : num2;
}

int main(void){
  int n;
  printf("Enter the number of Houses you want to Rob: ");
  scanf("%d", &n);
  int houses[n];
  printf("Enter the Houses: ");
  for (int i = 0; i < n; i++)
      scanf("%d", &houses[i]);
  int dp[n + 1];
  for (int i = 0; i < n + 1; i++) 
      dp[i] = -1;
  printf("The Top Down Approach to Rob the House: %d",RobHouseTD(houses, dp, n - 1));
  printf("\nThe Bottom Up approach to Rob the House: %d",RobHouseBU(n, houses));
  return 0;
}
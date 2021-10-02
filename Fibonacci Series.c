/*
Time Complexit - O(n)
Space Complexity - O(n)
*/
#include<stdio.h>
//Top Down Approach Starts here -

int fibTD(int n, int *dp){
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibTD(n - 1, dp) + fibTD(n - 2, dp);
}
//Bottom up Approach Starts here -

int fibBU(int n){
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
       dp[i] =  dp[ i- 1] + dp[i - 2];
    return dp[n];
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    int dp[n];
    for (int i = 0; i <= n + 1; i++)
        dp[i] = -1;
   printf("The Top Down Approach of Fibonacci number: %d",fibTD(n ,dp));
   printf("\nThe Bottom up Approach of Fibonacci number: %d",fibBU(n));
   return 0;
}

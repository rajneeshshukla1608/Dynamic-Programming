#include<stdio.h>
#include<stdlib.h>
#define infinity 99999;

int min(int x, int y, int z){
    int c = 0;
    while (x && y && z) {
        x--;
        y--;
        z--;
        c++;
    }
    return c;
}

int MinStepsToOneTD(int n, int *dp){
    if( n == 2 || n == 3) return 1;
    if( n == 1) return 0;
    if(n < 1) return infinity;
    if(dp[n] != 0) return dp[n];
    int div_by_3 = infinity;
    int div_by_2 = infinity;
    int sub_by_1 = infinity;
    if(n%3 == 0){
        div_by_3 = 1 + MinStepsToOneTD( n / 3, dp);
    }
    if(n%2 == 0){
        div_by_2 = 1 + MinStepsToOneTD( n / 2, dp);
    }
    sub_by_1 = 1 + MinStepsToOneTD(n - 1, dp);
    return dp[n] =  min(div_by_3, div_by_2, sub_by_1);
}

int MinStepsToOneBU(int n){
    int dp[n + 1];
    for(int i = 0; i < n + 1; i++){
        dp[i] = 0;
    }
    dp[0] = infinity;
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i = 4; i < n + 1; i++){
        int div_by_3 = infinity;
        int div_by_2 = infinity; 
        int sub_by_1 = infinity;
        if(i % 3 == 0){
            div_by_3 = 1 + dp[i/3];
        }
        if(i % 2 == 0){
            div_by_2 = 1 + dp[i/2];
        }
        sub_by_1 = 1 + dp[i - 1];
        dp[i] = min(div_by_3, div_by_2, sub_by_1);
    }
    return dp[n];
}


int main(){
    int n;
    printf("Enter the number to make it to 1: ");
    scanf("%d", &n);
    int dp[n + 1];
    for(int i = 0; i < n + 1; i++){
        dp[i] = 0;
    }
    printf("Min Steps to One Top Down - %d",MinStepsToOneTD(n, dp));
    printf("\nMin Steps to one Bottom Up - %d",MinStepsToOneBU(n));
}
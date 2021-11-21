#include<bits/stdc++.h>
using namespace std;

bool SubsetSum(int *arr, int n, int sum){

    bool dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i < sum + 1; i++)
        dp[0][i] = false;


     for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            if (j >= arr[i - 1])
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    return dp[n][sum];
}

int main(){
    int n;
    cout<<"Enter the size of the aray: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to the array: ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to find the sum of: ";
    int sum;
    cin>>sum;
    if (SubsetSum(arr, n, sum) == true)
        cout <<"Found a subset with given sum";
    else
        cout <<"No subset found with given sum";
    return 0;
}
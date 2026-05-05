// Maximum Subarray Sum using Kadane's Algorithm and also printing the subarray that gives the maximum sum

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Number of elements: " << endl;
    cin >> n;

    vector<int> vec(n);
    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    int currSum = 0, maxSum = INT_MIN;
    int start = 0, tempStart = 0;
    int maxStart = 0, maxEnd = 0;

    for(int i=0; i<n; i++){
        currSum += vec[i];
        
        if(currSum > maxSum){
            maxSum = currSum;
            maxStart = tempStart;
            maxEnd = i;
        }
        
        if(currSum < 0){
            currSum = 0;
            tempStart = i + 1;
        }
    }

    cout << "Maximum subarray sum: " << maxSum << endl;

    cout << "Subarray: ";
    for(int i=maxStart; i<=maxEnd; i++){
        cout << vec[i];
        if(i < maxEnd) cout << ", ";
    }
    cout << endl;
    return 0;
}
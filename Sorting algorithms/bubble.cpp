#include <bits/stdc++.h>
using namespace std;

void bubble_sort( vector<int>& arr ){
    
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        for(int j =0;j<n-i-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j] , arr[j+1]);
        } 
    }

}


/*
obtimized version with flag


void bubble_sort( vector<int>& arr ){
    
    bool flag = true;
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        for(int j =0;j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                flag = false;
            }
        } 
        if(flag == true ) 
            break;
    }

}
*/


int main(){
    vector<int> arr = { 7 , 2 , 9 , 4 , 3 , 8 , 1 };
    bubble_sort(arr);
    for(auto &it : arr) cout << it << " ";
}
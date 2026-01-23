#include <bits/stdc++.h>
using namespace std;

void selection_sort( vector<int>& arr ){

    int minidx;
    int n = arr.size();

    for(int i=0; i< n-1; i++ ){
        minidx = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minidx]) 
                minidx = j;
        }

        swap(arr[minidx] , arr[i]);
        
    }
}

int main(){
    vector<int> arr = { 7 , 2 , 9 , 4 , 3 , 8 , 1 };
    selection_sort(arr);
    for(auto &it : arr) cout << it << " ";
}
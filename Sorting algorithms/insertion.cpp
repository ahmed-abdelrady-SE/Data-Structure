#include <bits/stdc++.h>
using namespace std;

void insertion_sort( vector<int>& arr ){
    
    int n = arr.size();
    int key,j;

    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while( j>=0 and arr[j] > key ){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

}

int main(){
    vector<int> arr = { 7 , 2 , 9 , 4 , 3 , 8 , 1 };
    insertion_sort(arr);
    for(auto &it : arr) cout << it << " ";
}
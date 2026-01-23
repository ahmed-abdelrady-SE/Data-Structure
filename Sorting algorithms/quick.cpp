#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int begin , int end ){
    int i = begin;
    int j = end;
    int pivot = i;

    while(true){
        while(arr[pivot] <= arr[j] && pivot != j){
            j--;
        }
        if(pivot == j) break;
        else if(arr[pivot] > arr[j]){
            swap(arr[j], arr[pivot]);
            pivot = j;
        }

        while(arr[pivot] >= arr[i] && pivot != i){
            i++;
        }
        if(pivot == i) break;
        else if(arr[pivot] < arr[i]){
            swap(arr[i], arr[pivot]);
            pivot = i;
        }
    }
    
    return pivot;

}

void quick_sort( vector<int>& arr , int l , int r ){
    if(l<r){
        int pivot = partition(arr,l,r);
        quick_sort(arr,l,pivot-1);
        quick_sort(arr,pivot+1,r);
    }
}

int main(){
    vector<int> arr = { 7 , 2 , 9 , 4 , 3 , 8 , 1 };
    quick_sort(arr , 0 , arr.size()-1 );
    for(auto &it : arr) cout << it << " ";
}   
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr , int l , int r, int m){    // m = l + (r-l)/2
    int i,j,k;
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(n1) , R(n2);
    
    for(int i=0; i<n1; i++){
        L[i] = arr[i+l];
    }

    for(int i=0; i<n2; i++){
        R[i] = arr[m+1+i];
    }

    i=j=0;
    k=l;

    while( i<n1 && j < n2 ){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort( vector<int>& arr , int l , int r ){
    if(l<r){

        int m = l + (r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);

        merge(arr,l,r,m);

    }
}

int main(){
    vector<int> arr = { 7 , 2 , 9 , 4 , 3 , 8 , 1 };
    merge_sort( arr , 0 , arr.size()-1 );
    for(auto &it : arr) cout << it << " ";
}
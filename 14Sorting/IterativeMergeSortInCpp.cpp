#include <iostream>

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
void Merge(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}
 
void IterativeMergeSort(int A[], int n){
    int p,i,low,mid,high;
    for (p=2; p<=n; p=p*2){
        for (i=0; i+p-1<n; i=i+p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            Merge(A, low, mid, high);
        }
        if(n-i>p/2)
        {
            low=i;
            high=i+p-1;
            mid=(low+high)/2;
            Merge(A,low,mid,n-1);
        }
    }
    if (p/2 < n){
        Merge(A, 0, p/2-1, n-1);
    }
}
 
int main() {
 
    int A[] = {11,13,7,12,16,9,24,5,10,3,11,2,22,4};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\tA");
    IterativeMergeSort(A, n);
    Print(A, n, " Sorted A");
 
    return 0;
}
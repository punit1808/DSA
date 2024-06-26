#include<iostream>
using namespace std;
void Heapify(int *arr,int size,int index){
    int i=index;
    int leftIndex=2*i;
    int rightIndex=2*i+1;
    int largest=i;
    if(leftIndex<=size && arr[leftIndex]>arr[largest]){
        largest=leftIndex;
    }
    if(rightIndex<=size && arr[rightIndex]>arr[largest]){
        largest=rightIndex;
    }
    if(i!=largest){
        swap(arr[i],arr[largest]);
        i=largest;
        Heapify(arr,size,i);
    }
    else{
        return;
    }
}
void BuildHeap(int *arr,int size){
    for(int i=size/2;i>0;i--){
        Heapify(arr,size,i);
    }
}
int main(){
    int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
    int n = 11;
    BuildHeap(arr, n);

    cout << "printint the heap "<< endl;
    for(int i=1; i<=n; i++) {
            cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
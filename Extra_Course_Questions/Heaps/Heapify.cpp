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
int main(){

    return 0;
}
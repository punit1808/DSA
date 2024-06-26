#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        size=0;
        arr[0]=-1;
    }
    Heap(int data){
        arr[0]=-1;
        size=size+1;
        arr[size]=data;
    }
    void Insertion(int data){
    size=size+1;
    int index=size;
    arr[size]=data;
    while(index>1){
        int parentIndex=index/2;
        if(arr[parentIndex]<arr[index]){
            swap(arr[parentIndex],arr[index]);
            index=parentIndex;
        }
        else{
            break;
        }
    }
    }
};
int main(){
  Heap h;

    h.Insertion(50);
    h.Insertion(30);
    h.Insertion(70);
    h.Insertion(40);
    h.Insertion(80);
    h.Insertion(100);

    cout << "printing the heap " << endl;
    for(int i=1; i<=h.size; i++) {
            cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
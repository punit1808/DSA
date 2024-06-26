#include <iostream>
#include<cstring>
using namespace std;

int main() {
 int arr[5]={0};
 memset(arr,'1',sizeof(arr));

  cout<<arr;
 
  return 0;
}
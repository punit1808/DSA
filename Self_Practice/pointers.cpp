#include <bits/stdc++.h>
using namespace std;

int main(){
    int x=20;
    int *ptr;
    int **p;
    ptr = &x;
    p=&ptr;
    cout <<x <<endl;
    cout <<ptr <<endl;
    cout <<p <<endl;
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n = 6; // For general pattern, we take n
    // First print the full pyramid pattern
    for(int i = 0;i<n;i++){ // This for loop is for number of rows
        
        // First print the spaces
        int space = n - i - 1;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Then print the stars
        for(int j = 0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    // Print the inverted full pyramid pattern
    for(int i = 0;i<n;i++){ // This for loop is for number of rows
        // First print the spaces
        int space = i;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Then prin    t the stars
        for(int j = 0;j<n-i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
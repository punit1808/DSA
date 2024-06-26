#include<iostream>
using namespace std;
void printdigit(int num){
    if(num<=0){
        return;
    }
    int digit=num%10;
    cout<<digit<<" ";
    num=num/10;
    printdigit(num);

}
int main(){
    int num=526;
    printdigit(num);
}
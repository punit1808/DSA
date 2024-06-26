#include<iostream>
using namespace std;
class test{
    public:
    int num=10;
  void test1(){
    cout<<"Num= "<<num;
    }
};
class test2:public test{
    public:
    void test1(){
         cout<<"Num= "<<num+10;

    }
};
int main(){
    test2 t;
    t.test1();
}
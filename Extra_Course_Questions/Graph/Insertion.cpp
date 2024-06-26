#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> map;

    void Insertion(int u,int v,bool check){
        map[u].push_back(v);
        if(!check){
            map[v].push_back(u);
        }
    }

    void display(){
        for(auto node:map){
            cout<<node.first<<"->";
            for(auto i:node.second){
                cout<<i<<",";
            }
            cout<<endl;
        }
        }


};

int main(){

    Graph g;
    g.Insertion(0,1,1);
    g.Insertion(0,3,1);
    g.Insertion(1,2,1);
    g.Insertion(2,3,1);
    g.display();

    return 0;
}
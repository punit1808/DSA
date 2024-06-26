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

    void bfs_LevelOrderTraversal(int start,unordered_map<int,bool>& visited){
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int element=q.front();
            q.pop();
            cout<<element<<" ";
            for(auto i:map[element]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    void DFS(int start,unordered_map<int,bool>& visited2){
        cout<<start<<" ";
        visited2[start]=true;
        for(auto i:map[start]){
            if(!visited2[i]){
                DFS(i,visited2);
            }
        }
    }

};

int main(){

    Graph g;
    g.Insertion(0,1,1);
    g.Insertion(0,3,1);
    g.Insertion(1,2,1);
    g.Insertion(2,3,1);

    unordered_map<int,bool> visited;

    cout<<"Data in Graph :"<<endl;
    g.display();

    cout<<endl<< "Printing bfs or level order traversal in Graph :"<<endl;
    g.bfs_LevelOrderTraversal(0,visited);

    unordered_map<int,bool> visited2;
    
    cout<<endl<<"Printing DFS : "<<endl;
    g.DFS(0,visited2);

    return 0;
}
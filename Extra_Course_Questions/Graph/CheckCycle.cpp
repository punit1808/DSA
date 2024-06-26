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

    bool CheckCycleUsingBFS(int source,unordered_map<int,bool>& visited){
        queue<int> q;
        unordered_map<int,int> parent;

        q.push(source);
        visited[source]=true;
        parent[source]=-1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto i:map[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    parent[i]=frontNode;
                }
                else{
                    if(i!=parent[frontNode]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
        bool CheckCycleUsingDFS(int source,unordered_map<int,bool>& visited,int parent){
            visited[source]=true;
            for(auto i: map[source]){
                if(!visited[i]){
                    bool ans=CheckCycleUsingDFS(i,visited,source);
                    if(ans){
                        return true;
                    }
                }
                else{
                    if(i!=parent){
                        return true;
                    }
                }
            }
            return false;
    }

};

int main(){

    Graph g;

    // Cycle is Present->undirected

    g.Insertion(0,1,0);
    g.Insertion(0,3,0);
    g.Insertion(1,2,0);
    g.Insertion(2,3,0);

    // Cycle is Absent->undirected

    // g.Insertion(0,1,0);
    // g.Insertion(1,3,0);
    // g.Insertion(1,2,0);


    unordered_map<int,bool> visited;

    cout<<"Data in Graph :"<<endl;
    g.display();

    cout<<endl<< "Printing bfs or level order traversal in Graph :"<<endl;
    g.bfs_LevelOrderTraversal(0,visited);

    // unordered_map<int,bool> visited2;
    // bool ans=g.CheckCycleUsingBFS(0,visited2);
    // if(ans){
    //     cout<<endl<<"Cycle is Present "<<endl;
    // }
    // else
    // cout<<endl<<"Cycle is not Present"<<endl;

        unordered_map<int,bool> visited2;
    bool ans=g.CheckCycleUsingDFS(0,visited2,-1);
    if(ans){
        cout<<endl<<"Cycle is Present "<<endl;
    }
    else
    cout<<endl<<"Cycle is not Present"<<endl;


    return 0;
}
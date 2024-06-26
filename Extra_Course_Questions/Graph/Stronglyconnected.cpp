#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> map;

    void Insertion(int u,int v,bool mode){
        map[u].push_back(v);
        if(!mode){
            map[v].push_back(u);
        }
    }

    void print(){
        for(auto i:map){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }

    void dfs(int start,unordered_map<int,bool>& visited,stack<int>& s){
        visited[start]=true;
        for(auto i:map[start]){
            if(!visited[i]){
                dfs(i,visited,s);
            }
        }
        s.push(start);
    }

    void dfsReversed(int start,unordered_map<int,bool>& visited2,
    unordered_map<int,list<int>>& Reversedmap){
        visited2[start]=true;
        cout << start << ", ";
        for(auto i:Reversedmap[start]){
            if(!visited2[i]){
                dfsReversed(i,visited2,Reversedmap);  
            }
        }
        
    }

    int Stronglyconnected(int size){
        // Storing Topological Sort in Stack
        stack<int> s;
        unordered_map<int,bool> visited;
        for(int i=1; i<size; i++) {
            if(!visited[i]) {
                dfs(i,visited,s);
            }
        }

        // Reversing and storing in another map;
        unordered_map<int,list<int>> Reversedmap;
        for(auto i:map){
            for(auto node:i.second){
                Reversedmap[node].push_back(i.first);
            }
        }


        // Comparing and incrementing in count
        int count=0;
        unordered_map<int,bool> visited2;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(!visited2[top]){
            cout<<"Call for "<<top<<" --> ";
            dfsReversed(top,visited2,Reversedmap);
            count++;
            cout<<endl;
            }
        }

        return count;

    }

};

int main(){
    graph g;

    g.Insertion(2,1,1);
    g.Insertion(1,3,1);
    g.Insertion(3,4,1);
    g.Insertion(4,2,1);
    g.Insertion(4,5,1);
    g.Insertion(5,6,1);

    g.Insertion(6,8,1);
    g.Insertion(8,7,1);
    g.Insertion(7,6,1);

    int size=9;

    // g.print();

    int StronglyConnectedComponents=g.Stronglyconnected(size);
    
    cout<<"StronglyConnectedComponents : "<<StronglyConnectedComponents;

    return 0;

}
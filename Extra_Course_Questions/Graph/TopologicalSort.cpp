#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
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

    void topologicalSortusingDFS(int start,unordered_map<int,bool>& visited2,stack<int>& s){
        cout<<start<<" ";
        visited2[start]=true;
        for(auto i:map[start]){
            if(!visited2[i]){
                topologicalSortusingDFS(i,visited2,s);
            }
        }
        s.push(start);
    }

    void topologicalSortusingBFS(int size,vector<int>& ans){
        unordered_map<int,int> inDegree;
        // Storing InDegree of all Nodes
        for(auto i:map){
            for(auto j:i.second){
                inDegree[j]++;
            }
        }
        queue<int> q;
        // Pushing Nodes with 0 InDegree in Queue
        for(int i=0; i<size; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}

        while(!q.empty()){
            int top=q.front();
            // cout<<"calling for top element : "<<top<<endl;
            ans.push_back(top);
            q.pop();
            for(auto i:map[top]){
                inDegree[i]--;
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
        }
    }
    
};

int main(){

    Graph g;

	int n = 4;
	g.Insertion(0,1,1);
    g.Insertion(1,3,1);
    g.Insertion(0,2,1);
    g.Insertion(2,3,1);


    unordered_map<int,bool> visited;

    cout<<"Data in Graph :"<<endl;
    g.display();

    stack<int> s;
    unordered_map<int,bool> visited2;
    g.topologicalSortusingDFS(0,visited2,s);
    cout<<endl<<"Printing Toplogical Sort : "<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    vector<int> ans;
    g.topologicalSortusingBFS(n,ans);

    cout<<endl<<"Printing Topological Sort Using BFS : "<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}
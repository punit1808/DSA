#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<set>

using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> map;

    void Insertion(int u,int v,int distance,bool check){
        map[u].push_back({v,distance});
        if(!check){
            map[v].push_back({u,distance});
        }
    }

    void display(){
    for(auto node:map){
        cout<<node.first<<"->";
        for(auto i:node.second){
            cout<<"("<<i.first<<" , "<< i.second<<") , ";
        }
        cout<<endl;
    }
    }

    void ShortestPath(int source,int destination){

        //  When Distance between the Nodes is same 

        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        q.push(source);
        visited[source]=true;
        parent[source]=-1;

        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto i:map[top]){
                if(!visited[i.first]){
                    q.push(i.first);
                    visited[i.first]=true;
                    parent[i.first]=top;
                }
            }
        }

        vector<int> ans;
        int node=destination;
        while(node!=-1){
            ans.push_back(node);
            node=parent[node];
        }

        reverse(ans.begin(),ans.end());

        for(auto i: ans){
            cout<<i<<" -> ";
        }
        cout<<endl;
    }

    void topoSortDfs(int src, unordered_map<int, bool>& visited, stack<int>& ans) {
		
		visited[src] = true;

		for(auto neighbour: map[src]) {
			if(!visited[neighbour.first] ) {
				topoSortDfs(neighbour.first, visited, ans);
			}
		}

		// while returning, store the node in stack
		// cout << "Pushing " << src << endl;
		ans.push(src);
	}

    int ShortestPathConsideringDistance(int destination,int size,stack<int>& topoSort){
        vector<int> ans(size,INT_MAX);
        
        int top=topoSort.top();
        ans[top]=0;
        topoSort.pop();
        for(auto i:map[top]){
            if(ans[top]+i.second < ans[i.first]){
                ans[i.first]=ans[top]+i.second;
            }
        }
        
        while(!topoSort.empty()){
            int top=topoSort.top();
            topoSort.pop();
        if(ans[top]!=INT_MAX){
            for(auto i:map[top]){
                if(ans[top]+i.second < ans[i.first]){
                ans[i.first]=ans[top]+i.second;
            }               
        }   }
        }

        // for(int i=0;i<size;i++){
        //     cout<<i<<" -> "<<ans[i]<<endl;
        // }
        return ans[destination];
    }

    int shortestDistanceDijkstra(int source,int destination,int size){
        vector<int> ans(size,INT_MAX);
        // set-> first(Distance) , second(Node)
        set<pair<int,int>> st;
        st.insert(make_pair(0,source));
        ans[source]=0;

        while(!st.empty()){
            auto top= *(st.begin());
            int dis=top.first;
            int node=top.second;

            st.erase(st.begin());

            for(auto i:map[node]){
                if(dis+i.second< ans[i.first]){
                    auto check=st.find(make_pair(ans[i.first],i.first));
                    if(check!=st.end()){
                        st.erase(check);
                    }
                    ans[i.first]=ans[node]+i.second;
                    st.insert(make_pair(dis+i.second,i.first));
                }

            }
        }
        // for(int i=0;i<size;i++){
        //     cout<<i<<" -> "<<ans[i]<<endl;
        // }
        return ans[destination];
    }
    
};

int main(){
	Graph g;

	g.Insertion(6,3,2,1);
	g.Insertion(6,1,14,1);
	g.Insertion(3,1,9,1);
	g.Insertion(3,2,10,1);
	g.Insertion(1,2,7,1);
	g.Insertion(2,4,15,1);
	g.Insertion(4,3,11,1);

	g.Insertion(6,5,9,1);
	g.Insertion(4,5,6,1);
 

	g.display();

    // g.ShortestPath(6,4);

    stack<int> s;
    unordered_map<int,bool> visited;
    g.topoSortDfs(6,visited,s);
    int minPath=g.ShortestPathConsideringDistance(4,16,s);
    cout<<endl<<"Minimum Distance between 6 and 4 : "<<minPath<<endl;
    minPath=g.shortestDistanceDijkstra(6,4,16);
    cout<<endl<<"Answer using Dijkstra Algorithm : "<<endl;
    cout<<"Minimum Distance between 6 and 4 : "<<minPath<<endl;


    return 0;
}
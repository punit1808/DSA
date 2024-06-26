#include<iostream>
#include<vector>
using namespace std;
bool issafe(int arr[][3],int i,int j,vector<vector<bool> > &visited,int row,int col){
    if((i<row&&j<col)&&(arr[i][j]==1)&&(visited[i][j]==false)){
        return true;
    }
    else{
        return false;
    }
}
void solvemaze(int arr[][3],int row,int col,vector<vector<bool> > &visited,int i,int j,vector<string> &path,string output){
    // Base Case
    if(i==row-1 && j==col-1){
        path.push_back(output);
        return;
    }
    // For left
    if(issafe(arr,i,j-1,visited,row,col)){
        visited[i][j-1]=true;
       solvemaze(arr,row,col,visited,i,j-1,path,output+'L');
       visited[i][j-1]=false;  
    }
    // For right
     if(issafe(arr,i,j+1,visited,row,col)){
        visited[i][j+1]=true;
       solvemaze(arr,row,col,visited,i,j+1,path,output+'R');
       visited[i][j+1]=false;  
    }
    // For up
     if(issafe(arr,i-1,j,visited,row,col)){
        visited[i-1][j]=true;
       solvemaze(arr,row,col,visited,i-1,j,path,output+'U');
       visited[i-1][j]=false;  
    }
    // For down
     if(issafe(arr,i+1,j,visited,row,col)){
        visited[i+1][j]=true;
       solvemaze(arr,row,col,visited,i+1,j,path,output+'D');
       visited[i+1][j]=false;  
    }
}
int main(){
    int arr[3][3]={{1,0,0},{1,1,0},{1,1,1}};
    int row=3;
    int col=3;
    int i=0;
    int j=0;
    vector<vector<bool> > visited(row,vector<bool> (col,false));
    visited[0][0]=true;
    vector<string> path;
    string output="";
    cout<<"Printing Output"<<endl;
    solvemaze(arr,row,col,visited,i,j,path,output);
    for(auto i:path){
        cout<<i<<" ";
    }
}
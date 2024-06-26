#include<iostream>
#include<limits.h>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextsmaller(vector<int> input){
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());
    for(int i=input.size()-1;i>=0;i--){
        int curr=input[i];
        while(s.top()!=-1 && input[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();

        s.push(i);
    }
    return ans;
}

vector<int> prevsmaller(vector<int> input){
    stack<int> s;
    s.push(-1);
    vector<int> ans(input.size());
    for(int i=0;i<input.size();i++){
        int curr=input[i];
        while(s.top()!=-1 && input[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int getRectangularAreaHistogram(vector<int>& height){
    vector<int> next=nextsmaller(height);
    vector<int> prev=prevsmaller(height);
    int maxArea=INT_MIN;
    for(int i=0;i<height.size();i++){
        int nextlength=next[i];
        int prevlength=prev[i];
        int heightlength=height[i];
        if(next[i]==-1){
            nextlength=height.size();
        }
        int area=heightlength*(nextlength-prevlength-1);
        maxArea=max(maxArea,area);
    }
    return maxArea;

}
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);

    cout << "MaxArea of Histogram : " << getRectangularAreaHistogram(v) << endl;
}
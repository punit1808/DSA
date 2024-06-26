#include<iostream>
using namespace std;
class Tries{
    public:
    char data;
    bool isNode;
    Tries* Children[26];
    Tries(char data){
        this->data=data;
        for(int i=0;i<26;i++){
            Children[i]=NULL;
        }
        isNode=false;
    }
};
void Insertion(Tries* root,string s){
    if(s.length()==0){
        root->isNode=true;
        return;
    }
    char ch=s[0];
    int index=ch-'a';
    Tries* child;
    if(root->Children[index]!=NULL){
        child=root->Children[index];
    }
    else{
        child=new Tries(ch);
        root->Children[index]=child;
    }
    Insertion(child,s.substr(1));
}

bool SearchWord(Tries* root,string s){
    if(s.length()==0){
        if(root->isNode){
            return true;
        }
        else{
            return false;
        }
    }
    char ch=s[0];
    int index=ch-'a';
    Tries* child;
    if(root->Children[index]!=NULL){
        child=root->Children[index];
    }
    else{
        return false;
    }

    return SearchWord(child,s.substr(1));

}

void deletion(Tries* root,string s){
    if(s.length()==0){
        root->isNode=false;
    }
    char ch=s[0];
    int index=ch-'a';
    Tries* child;
    if(root->Children[index]!=NULL){
        child=root->Children[index];
    }
    else{
        return;
    }

    deletion(child,s.substr(1));
    
}

int main(){
    Tries* root=new Tries('-');
    Insertion(root,"hello");
    Insertion(root,"apple");
    Insertion(root,"cat");
    Insertion(root,"appollo");
    Insertion(root,"hero");
    cout<<"Insertion Done"<<endl;
    if(SearchWord(root,"hero")){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    deletion(root,"hero");
    if(SearchWord(root,"hero")){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    return 0;
}
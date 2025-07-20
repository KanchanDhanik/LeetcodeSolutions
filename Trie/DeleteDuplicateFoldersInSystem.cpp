/*Understanding the question :
We are given a 2d vector or strings containg path of folders in a string array like if ["one","two","three"] this vector means
"one/two/three"  
Our task is to remove the marked folders :
Now who are mark folders:
mark folders in this question means two folders which are identical(that does not mean on same level they can be in diff level)
but needs to be identical if they are identical we will mark them and then remove them from the 2d array and return the final 
result of non identical paths*/

/*Proposed Solution: So as we have to find the indentical folders and this is the string question and we definitely can see the heirracical
structure we can make use of trie for this question the solution can be obtained in 3 steps
we will be using 2 data strutures :trie and unordered map

Trie: is used to create the folder heirrarcical structure after we have created the structure we will traverse on it to find out duplicate folders
to find those duplicate folder we will need a map to store the folder name and its cnt(i.e. how many times it has occurred) Once we have these two things
we can move to our 
step 2 : that is we will delete the folders which have cnt>1 all 

step 3:after removing from the trie we will be left with the non duplicate folders which we can traverse and 
using backtracking to store all paths and finally return the result
*/

//Solution Code:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node{
    string name;
    string subfolder;
    unordered_map<string,Node*>children;
};

struct Node*getNode(string val){
    struct Node*temp=new struct Node();
    temp->name=val;
    temp->subfolder="";
    return temp;
}
//insert function for trie
void insert(Node*root,vector<string>&path){
    
    for(auto&folder:path){
        if(!root->children.count(folder)){
            root->children[folder]=getNode(folder);
        }
        root=root->children[folder];
    }
}

//populate function to add subfolder name and map assingment

string populate(struct Node*root,unordered_map<string,int>&folderMap){
    vector<pair<string,string>>subFolderPath;

    for(auto it = root->children.begin(); it != root->children.end(); ++it){
    string childname = it->first;
    Node* childNode = it->second;
    string subfolderRes = populate(childNode, folderMap);
    subFolderPath.push_back({childname, subfolderRes});
}

    sort(subFolderPath.begin(),subFolderPath.end());

    string completepath="";

    for(auto it = subFolderPath.begin(); it != subFolderPath.end(); ++it){
    string childname = it->first;
    string subfolderRes = it->second;
    completepath += "(" + childname + subfolderRes + ")";
}

    root->subfolder=completepath;
    if(!completepath.empty()){
        folderMap[completepath]++;
    }
    return completepath;
}

///after populating we have to remove duplicates
void removeDuplicates(struct Node*root,unordered_map<string,int>&folderMap){

    for(auto it=root->children.begin();it!=root->children.end();){
        string childName=it->first;
        struct Node*childNode=it->second;
        if(!childNode->subfolder.empty()&& folderMap[childNode->subfolder]>1){
            it=root->children.erase(it);
        }else{
            removeDuplicates(childNode,folderMap);
            it++;
        }
    }
}

void construct(struct Node*root,vector<string>&path,vector<vector<string>>&res){
    for(auto it = root->children.begin(); it != root->children.end(); ++it){
    string childname = it->first;
    Node* childnode = it->second;
    path.push_back(childname);
    res.push_back(path);
    construct(childnode, path, res);
    path.pop_back();
}
}


vector<vector<string>>deleteDuplicateFolder(vector<vector<string>>&paths){
    struct Node*root=getNode("/");

    //insert into this trie
    for(auto &path:paths){
        insert(root,path);
    }
    //now we have trie now we need to populate the folderMAp count and trie with subfolder names on the basis of trie
    unordered_map<string,int>folderMap;
    populate(root,folderMap);

    //after populating we have to remove theduplicate folders
    removeDuplicates(root,folderMap);

    //afterRemoving we will construct the result from the trie traversal
    vector<vector<string>>res;
    vector<string>path;
    construct(root,path,res);
    return res;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<string>>paths(n,vector<string>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>paths[i][j];
        }
    }
    vector<vector<string>>res=deleteDuplicateFolder(paths);
    for(size_t i=0;i<res.size();i++){
        for(size_t j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
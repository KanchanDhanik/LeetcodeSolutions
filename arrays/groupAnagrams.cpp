/*anagrams are the words which have same size and same characters like ate and eat*/
/*so for grouping the anagrams we have use a map of string ,vector<string> that contains the key as sorted order of the characters of the word and
if any other word encountered with same characters we can insert it to that group
*/
#include<bits/stdc++.h>

using namespace std;
vector<vector<string>>groupAnagrams(vector<string>strs){
    unordered_map<string,vector<string>>mpp;
    for(auto &str:strs){
        string temp=str;
        sort(temp.begin(),temp.end());
            mpp[temp].push_back(str);
    }
    vector<vector<string>>ans;
    for(auto &v:mpp){
        ans.push_back(v.second);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string>strs(n);
    for(int i=0;i<n;i++){
        cin>>strs[i];
    }
    vector<vector<string>>ans=groupAnagrams(strs);
    for(auto &v:ans){
        for(auto &str:v){
            cout<<str<<" ";
            }
    }
}
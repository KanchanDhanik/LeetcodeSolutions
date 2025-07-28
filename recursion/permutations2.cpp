#include<bits/stdc++.h>
using namespace std;


void helper(vector<int>& temp, vector<bool>& visited, vector<vector<int>>& res, vector<int>& arr) {
    if (temp.size() == arr.size()) {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(arr[i]);
            helper(temp, visited, res, arr);
            temp.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> findpermu(vector<int>& arr) {
    vector<vector<int>> res;
    vector<bool> visited(arr.size(), false);
    vector<int> temp;
    helper(temp, visited, res, arr);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>ans=findpermu(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
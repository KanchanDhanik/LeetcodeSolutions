#include<bits/stdc++.h>
using namespace std;
vector<int> findpse(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return left;
}

vector<int> findnse(vector<int>& heights) {
    int n = heights.size();
    vector<int> right(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return right;
}

int largestrec(vector<int>&heights){
    int n = heights.size();
    int max_area = 0;
    vector<int>nse=findnse(heights);
    vector<int>pse=findpse(heights);
    int area=0;
    for(int i=0;i<n;i++){
        area=heights[i]*(nse[i]-pse[i]-1);
        max_area=max(max_area,area);
    }
    return max_area;

}




int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int maxarea=largestrec(arr);
    cout<<"max area : "<<maxarea;

}
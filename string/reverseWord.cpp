#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    cout << "Actual string: " << s << "\n";

 /*   stack<string> st;
    string word = "";

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            if (!word.empty()) st.push(word);
            word = "";
        } else {
            word += s[i];
        }
    }

    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
        if (!st.empty()) ans += " "; // Avoid extra space at the end
    }

    cout << "String after reversing: " << ans << "\n";
    return 0;
    */

    int left=0;
    int n=s.size();
    int right=n-1;
    string curr="";
    string rev="";
    while(left<=right){
        char ch=s[left];
        if(ch==' '){
            if(rev!="")rev=curr+" "+rev;
            else rev=curr;
            curr="";
        }else if(ch!=' '){
            curr+=ch;
        }
        left++;
    }
    if(curr!=""){
        if(rev!="")rev=curr+" "+rev;
        else rev=curr;
    }
    cout<<"after reverse : "<<rev;
}

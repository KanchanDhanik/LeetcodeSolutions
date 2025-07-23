#include<bits/stdc++.h>
using namespace std;
//using stack //space complexity 0(N)
/*string gain(string &s,string &rem){
    int n=s.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        if(!st.empty() && s[i]==rem[1] && st.top()==rem[0]){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    string temp="";
    while(!st.empty()){
        temp=st.top()+temp;
        st.pop();
    }
    return temp;
}*/
//using two pointers S.C=0(1);
string gain(string &s,string &rem){
   int i=0;//forwriting

   for(int j=0;j<s.size();j++){
    s[i]=s[j];
    i++;
    if(i>=2 && s[i-1]==rem[1] && s[i-2]==rem[0]){
        i-=2;
    }
   }
   s.erase(s.begin()+i,s.end());
   return s;
}
int maxGain(string &s,int x,int y){
    //so we can solve this problem in 2 passess as if we try to solve in one pass greedly
    //that may not give as optimal soln 
    //so in first pass we will remove the max points string and in second pass we will use 
    //the min points string to get the max gain
    int n=s.size();

    string maxStr=(x>y)?"ab":"ba";
    string minStr=(maxStr=="ab")?"ba":"ab";

    string firstPass=gain(s,maxStr);
    int l1=firstPass.size();

    int charRemoved=n-l1;

    int pointsgain=(charRemoved/2)*max(x,y);

    //second pass
    string secondPass=gain(firstPass,minStr);
    int l2=secondPass.size();
    charRemoved=l1-l2;

    pointsgain+=(charRemoved/2)*min(x,y);
    return pointsgain;
}
int main(){
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    int maxpoints=maxGain(s,x,y);
    cout<<endl;
    cout<<maxpoints<<endl;
}
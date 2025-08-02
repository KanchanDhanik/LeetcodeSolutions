#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>dp;
/*int helper(vector<vector<int>>&activities,int day,int last){
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,activities[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last+1]!=-1)return dp[day][last+1];
    int maxi=0;
    for(int i=0;i<=2;i++){
        if(i!=last){
            int activity=activities[day][i]+helper(activities,day-1,i);
            maxi=max(maxi,activity);
        }
    }
    return dp[day][last+1]=maxi;
}*/
int main(){
    int n;
    cin>>n;
    vector<vector<int>>activities(n,vector<int>(3));
    for(int i=0;i<n;i++){
        int run,fight,learn;
        cin>>run>>fight>>learn;
        activities[i]={run,fight,learn};
    }
    dp.resize(n,vector<int>(4,0));
    /*int maxprofit=helper(activities,n-1,-1);
    cout<<maxprofit<<endl;*/


   /* dp[0][0]=max(activities[0][1],activities[0][2]);
    dp[0][1]=max(activities[0][0],activities[0][2]);
    dp[0][2]=max(activities[0][1],activities[0][0]);
    dp[0][3]=max(activities[0][0],max(activities[0][2],activities[0][1]));

    for(int i=1;i<n;i++){
       for(int last=0;last<4;last++){
        dp[i][last]=0;
        for(int task=0;task<=2;task++){
            if(last!=task){
                int activity=activities[i][task]+dp[i-1][task];
                dp[i][last]=max(dp[i][last],activity);
            }
        }
       }
    }
    cout<<dp[n-1][3];*/

   // space optimised
    vector<int>prev(4,0);
    prev[0]=max(activities[0][1],activities[0][2]);
    prev[1]=max(activities[0][0],activities[0][2]);
    prev[2]=max(activities[0][0],activities[0][1]);
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int activity=0;activity<=2;activity++){
                if(last!=activity){
                    temp[last]=max(temp[last],activities[day][activity]+prev[activity]);
                }
            }
        }
        prev=temp;
    }
    cout<<prev[3];
}
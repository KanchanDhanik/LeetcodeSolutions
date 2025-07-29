#include<bits/stdc++.h>
using namespace std;
struct Job{
int id;
int dead;
int profit;
};

static bool compare(struct Job&a,struct Job&b){
    return a.profit>b.profit;
}

int main(){
    int n;
    cin>>n;
    vector<struct Job>jobs(n);
    for(int i=0;i<n;i++){
        cin>>jobs[i].id;
        cin>>jobs[i].dead;
        cin>>jobs[i].profit;
    }

    sort(jobs.begin(),jobs.end(),compare);
    int maxdeadline=0;
    for(int i=0;i<n;i++){
        maxdeadline=max(maxdeadline,jobs[i].dead);
    }

    vector<bool>slot(maxdeadline+1,false);
    vector<int>jobsequence;
    int profit=0;
    for(auto&job:jobs){
        for(int j=min(maxdeadline,job.dead);j>0;j--){
            if(slot[j]==false){
                slot[j]=true;
                profit+=job.profit;
                jobsequence.push_back(job.id);
                break;
            }
        }
    }
    cout<<"Job Sequence: ";
    for(auto&job:jobsequence){
        cout<<job<<" ";
    }
    cout<<endl;
    cout<<"Maximum Profit: "<<profit<<endl;
}
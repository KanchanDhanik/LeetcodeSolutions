#include<bits/stdc++.h>
using namespace std;

struct Item{
int val;
int weight;
};


int main(){
    int n;
    cin>>n;
    vector<struct Item>knapsack(n);
    for(int i=0;i<n;i++){
        int profit,weight;
        cin>>profit>>weight;
        knapsack[i].val=profit;
        knapsack[i].weight=weight;
    }

    sort(knapsack.begin(),knapsack.end(),[](const struct Item &a ,const struct Item &b){
        double r1=(double)a.val/(double)a.weight;
        double r2=(double)b.val/(double)b.weight;
        return r1>r2;
    });

    int capacity;
    cin>>capacity;
    int currcap=0;
    int profit=0;
    for(int i=0;i<n;i++){
        if(currcap+knapsack[i].weight<=capacity){
            profit+=knapsack[i].val;
            currcap+=knapsack[i].weight;
        }else{
            int rem=capacity-currcap;
            profit+=knapsack[i].val*(rem/(double)knapsack[i].weight);
            break;
        }
    }
    cout<<profit<<endl;
}
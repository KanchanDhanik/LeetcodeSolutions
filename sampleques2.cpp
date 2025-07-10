/*Ques-2 Given  m  heros and  n villans  all heros have strength h and villans have different strengths in vector vi 
we have to find after how many removal of villans from front can make the heros win
if strength hero>strength of villan hero win
if(strength of villan>strength of hero villan wins )
if both same bot dies ) if at end all are zeros than also hero wins as there is no villan left */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,h;
    cin>>n>>m>>h;
    vector<int>villans(n);
    for(int i=0;i<n;i++){
        cin>>villans[i];
    }
    int j=n-1;
    int i=0;
    while(i<m && j>=0){
        int stH=h;
        while(j>=0){
            if(stH>villans[j]){
                stH-=villans[j];
                j--;
            }else if(stH==villans[j]){
                i++;
                j--;
                break;
            }else{
                i++;
                break;
            }
        }
    }
    if(j>=0)cout<<j+1;
    else cout<<0;
}
//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string.h>

using namespace std;

int n, l, aliveCows;
int killList[2305];
bool cowIsDead[2305];

int main(){
    
    cin>>n>>l;
    memset(cowIsDead, 0, sizeof(cowIsDead));
    memset(killList, 0, sizeof(killList));
    
    for(int i=0; i<l; i++){
        cin>>killList[i];
    }
    aliveCows = n;
    
    int pos = -1;
    int killPos = 0;
    
    while(aliveCows>1) {
        int killNum = killList[killPos];
        while(killNum>0){
            pos += 1;
            pos %= n;
            if(!cowIsDead[pos]){
                killNum--;
            }
        }
//        pos -= 1;   this is to amend for the stupid for loop smh
//        pos += n;
//        pos %= n;
        cowIsDead[pos]=1;
        killPos++;
        killPos %= l;
        aliveCows--;
    }
    
    for(int i=0; i<n; i++){
        if(!cowIsDead[i]){
            cout<<i+1<<endl;
            break;
        }
    }
    
    return 0;
}

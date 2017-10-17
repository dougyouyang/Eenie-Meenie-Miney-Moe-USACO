/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/

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

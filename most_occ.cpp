#include <iostream>
using namespace std;
int main(){
       int n,h[99];
       cin>>n;
       for(int i=0;i<=99;i++){
               h[i]=0;
       }
        int max=0;
       for(int i=0;i<n;i++){
               int x;
               cin>>x;
               h[x]++;
               if(max<h[x])
               max=h[x];
       }
       for(int i=0;i<=99;i++)
       		if(h[i]==max)
       			cout<<i<<"  ";
       return 0;      
}
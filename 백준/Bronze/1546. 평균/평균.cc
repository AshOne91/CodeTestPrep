#include <iostream>
using namespace std;
int main(){
int n;double m=0,s=0,x;cin>>n;
for(int i=0;i<n;i++){cin>>x;if(x>m)m=x;s+=x;}
cout<<s/m*100/n;
}
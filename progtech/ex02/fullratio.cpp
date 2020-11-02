#include <iostream>
using namespace std ;
int main () {
int n;
cin >>n;
for(int i=0;i<n;i++)
{
char j;
int ar1,ar2,par1,par2;
cin>>j>>ar1>>par1>>ar2>>par2;
if(par1==0 or par2==0)
{cout<<"Error malakismeno"<< endl;return 0;}
if(j=='/'&&ar2==0)
{cout<<"Error malakismeno"<< endl;return 0;}
if(j=='+'){cout<<ar1*par2+ar2*par1<<" "<<par1*par2;return 0;}
if(j=='-'){cout<<ar1*par2-ar2*par1<< " "<<par1*par2;return 0;}
if(j=='/'){cout<<ar1*par2<<" "<< ar2*par1;return 0;}
if(j=='*'){cout<<ar1*ar2/par1*par2<<" "<< ar1*ar2%par1*par2; return 0;}

}
}

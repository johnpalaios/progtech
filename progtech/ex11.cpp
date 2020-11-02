#include <iostream>
using namespace std;


bool path(const int a[],int size1)
{
  int counter=0;
  for(int i=0;i<size1;++i)
  {if(a[i]%2!=0) {++counter;}}
  if(counter==2) return true;
  if(counter!=2) return false;
}
bool cycle(const int a[],int size1)
{
  int c=0;
  for(int i=0;i<size1;i++)
  {
  if(a[i]%2==1) {c++;}
  }
  if(c==0) return true;
  if(c!=0) return false;

}
int main()
{
  int edges,vertices;
  cin >> vertices >> edges ;
  int degree[vertices];
  for(int i=0;i<vertices;i++)
  {degree[i]=0;}
  for(int i=0;i<edges;i++)
  {
   int j,k;
   cin>> j >> k ;
   degree[j]++;degree[k]++;
  }
  /*for (int i=0;i<vertices;i++)  //where is the mistake?
  {cout << "The degree of the node " << i << " is : " << degree[i] << endl;}*/
  if(cycle(degree,vertices)==true) {cout << "CYCLE" << endl;}
  else if(path(degree,vertices)==true)
  {
  cout << "PATH";
  for(int i=0;i<vertices;i++)
  {if(degree[i]%2==1) cout << " " << i;}
  cout << endl;
  }
  else cout << "IMPOSSIBLE" << endl;

}

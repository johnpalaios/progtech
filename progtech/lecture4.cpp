#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;
template <typename K>
const void print (K &v)
{
  for (auto x:v)
    cout << x << endl;
}

int main() {
vector<int> v;
for (int i=1;i<=5;++i) v.push_back(i);
print(v);
list<int> l;
for(int i=1;i<=5;++i) l.push_back(i);
print(l);
list<string> h;
h.push_back("one");
h.push_back("two");
h.push_back("three");
print(h);



}

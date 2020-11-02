bool values()
{ bool c=true;T info=root->data;valuescheck(root,info,info,c);return c;}
void valuescheck(node*next,T min,T max,bool &c)
{
   T value=next->data;
   if (next->data < min || next->data > max) {c=false;return;}
   if(next->left!=nullptr) // LEFT SUBTREE
   { valuescheck(next->left,min,value-1,c);}
   if(next->left==nullptr)
   {return;}
   if(next->right!=nullptr) // RIGHT SUBTREE
   { valuescheck(next->right,value+1,max,c);}
   if(next->right==nullptr)
   {return;}
}
/*public:
bool sanity() const
{
  if(root==nullptr) return true;

  if(parent()!) return false;
  if(values()!) return false;
  if(avlbalance()!) return false;
  if(size()!) return false;
  return true;
}
private:
bool parent()
{bool c=true;parentcheck(root,nullptr,c);return c;}
void parentcheck(node*n,node*p,bool& c)
{
   if(n->parent!=p) {c=false;return;}
   if(n->left!=nullptr) // LEFT SUBTREE
   { parentcheck(n->left,n,c)}
   if(n->left==nullptr)
   {return;}
   if(n->right!=nullptr) // RIGHT SUBTREE
   { parentcheck(n->right,n,c); }
   if(n->right==nullptr)
   {return;}
}
bool values()
{ bool c=true;T info=root->data;valuescheck(root,info,info,c);return c;}
void valuescheck(node*next,T &min,T& max,bool &c)
{
   if (next->data < min || next->data > max) {c=false;return;}
   if(next->parent!=p) {c=false;return;}
   if(next->left!=nullptr) // LEFT SUBTREE
   { valuescheck(next->left,min,next->data-1,c));}
   if(next->left==nullptr)
   {return;}
   if(next->right!=nullptr) // RIGHT SUBTREE
   { valuescheck(next->right,next->data+1,max,c);}
   if(next->right==nullptr)
   {return;}
}
bool avlbalance()
{ bool c=true;int height=0;avlcheck(root,height,c);return c;}
void avlbalancecheck(node*next,int &height,bool &c)
{
   int height_left=0;,height_right=0;
   if(next->left!=nullptr) // LEFT SUBTREE
   { avlbalancecheck(next->left,height_left,c));}
   if(next->left==nullptr)
   {return;}
   if(next->right!=nullptr) // RIGHT SUBTREE
   { avlbalancecheck(next->right,height_right,c));}
   if(next->right==nullptr)
   {return;}
   if(abs1(height_left-height_right)>1) {c=false;return;}
   else if(height_left>height_right) {height=height_left+1;}
   else {height=height_right+1;}
   int dif=height_right-height_left;
   if( dif!=next->balance || abs1(dif)>1 ) {c=false;return;}
}
bool size()
{int s=0;size(root,s);if(s==the_size) return true;else return false;}
int size(node *n,int &s)
{
   if(n->left!=nullptr) // LEFT SUBTREE
   { size(n->left,s)}
   if(n->left==nullptr)
   {return;}
   if(n->right!=nullptr) // RIGHT SUBTREE
   { size(n->right,s); }
   if(n->right==nullptr)
   {return;}
   s++;return;
}*/

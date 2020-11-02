#include <string>
#include <cstring>
#include <iostream>


using namespace std;
class lexicon
{
private:
    struct node
    {
        node(string s): str(s),left(NULL),right(NULL),counter(10) {}
        string str;
        int counter;
        /*void c1() {counter++;};
        void c2(int k) {counter=counter+k;}*/
        int c3() {return counter;}
        node *left,*right;
    };
    node *root;
public:
    lexicon(void)
    {
        root=NULL;
    }
    ~lexicon()
    {
        destruct(root);
    }
    node* returnnode() {return root;}
    void insert(const string &s)
    {
       insert1(root,s);
    }
    int lookup(const string &s)
    {
        int c=counterprint(root,s);
        return c;
    }
     void in0rder()
     {
       inorder(root);
     }
    friend ostream & operator << (ostream &out, lexicon &l)
    {
       l.in0rder();
       return out;

    }
private:

    void destruct(node *n)
    {
        if(n)
        {
            destruct(n->left);
            destruct(n->right);
            delete n;
        }
    }
    void inorder(node *n)
     {

        if (n)
        {
            inorder(n->left);
            cout << n->str << " " << n->counter ;
            cout << endl;
            inorder(n->right);
        }          // display the right subtree
      }
    void insert1(node *&treeNode, const string s)
    {
        if(treeNode && treeNode->str==s)
        {
            treeNode->c3();
        }
        else
        {
            if (!treeNode)
            {
                treeNode = new node(s);
                root = treeNode;
            }
            else
            {
                if (s < treeNode->str)
                {
                    if (!treeNode->left)
                    {
                        node *treeTemp = new node(s);
                        treeNode->left = treeTemp;
                    }
                    else
                        insert1(treeNode->left, s);
                }
                else
                {
                    if (!treeNode->right)
                    {
                        node *treeTemp = new node(s);
                        treeNode->right = treeTemp;
                    }
                    else
                        insert1(treeNode->right, s);
                }
            }
        }
    }
    int counterprint(node *n,string s)
    {
      if(n->str==s) {return n->c3();}
      else if( n->)

    }

};
int main()
{
  lexicon l;
 l.insert("the");
 l.insert("boy");
 l.insert("and");
 l.insert("the");
 l.insert("wolf");
 cout << l.lookup("boy");
}

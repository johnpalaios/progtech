#include <string>
#include <cstring>
#include <iostream>


using namespace std;

class lexicon
{
private:
    struct node
    {
        node(string s): str(s),left(NULL),right(NULL),counter(1) {}
        string str;
        int counter;
        void c1()
        {
            counter++;
        };
        void c2(int k)
        {
            counter=counter+k;
        }
        int c3()
        {
            return counter;
        }
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

    void insert(const string &s)
    {
        insert1(root,s);
    }


    int lookup(const string &s)
    {
        int c=counterprint(root,s);
        return c;
    }
    int depth(const string &s)
    {
        return dpth(root,s,1);
    }

    void replace(string s1, string s2)
    {
        if(lookup(s1)>0)
        {
            int c1=lookup(s1);
            deletenode(root,s1);
            node *k=root;
            node *e=nullptr;
            searchKey(k,s2,e);
            addc(c1,k);
        }

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
    void addc(int c,node *n)
    {
        n->c2(c);
    }
    node* findit(node *n,string s)
    {
        if(s==n->str)
        {
            return n;
        }
        if(s>n->str)
        {
            findit(n->right,s);
        }
        if(s<n->str)
        {
            findit(n->left,s);
        }
    }
    // Helper function to find minimum value node in subtree rooted at curr
    node* minimumKey(node* curr)
    {
        while(curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }
    void searchKey(node* &curr, string key, node* &parent)
    {
        // traverse the tree and search for the key
        while (curr != nullptr && curr->str != key)
        {
            // update parent node as current node
            parent = curr;

            // if given key is less than the current node, go to left subtree
            // else go to right subtree
            if (key < curr->str)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    // Function to delete node from a BST
    void deletenode(node*& root, string key)
    {
        // pointer to store parent node of current node
        node* parent = nullptr;

        // start with root node
        node* curr = root;

        // search key in BST and set its parent pointer
        searchKey(curr, key, parent);

        // return if key is not found in the tree
        if (curr == nullptr)
            return;

        // Case 1: node to be deleted has no children i.e. it is a leaf node
        if (curr->left == nullptr && curr->right == nullptr)
        {
            // if node to be deleted is not a root node, then set its
            // parent left/right child to null
            if (curr != root)
            {
                if (parent->left == curr)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            // if tree has only root node, delete it and set root to null
            else
                root = nullptr;

            // deallocate the memory
            free(curr);	 // or delete curr;
        }

        // Case 2: node to be deleted has two children
        else if (curr->left && curr->right)
        {
            // find its in-order successor node
            node* successor  = minimumKey(curr->left);

            // store successor value
            string val = successor->str;

            // recursively delete the successor. Note that the successor
            // will have at-most one child (right child)
            deletenode(root, successor->str);

            // Copy the value of successor to current node
            curr->str = val;
        }

        // Case 3: node to be deleted has only one child
        else
        {
            // find child node
            node* child = (curr->left)? curr->left: curr->right;

            // if node to be deleted is not a root node, then set its parent
            // to its child
            if (curr != root)
            {
                if (curr == parent->left)
                    parent->left = child;
                else
                    parent->right = child;
            }

            // if node to be deleted is root node, then set the root to child
            else
                root = child;

            // deallocate the memory
            free(curr);
        }
    }

    int counterprint(node* n,const string &s)
    {
        if(n->str==s)
        {
            return n->c3();
        }
        else if(s>n->str)
        {
            if( n->right==nullptr)
            {
                return 333;
            }
            else
                return counterprint(n->right,s);
        }
        else if(s<n->str)
        {
            if (n->left==nullptr)
            {
                return 420;
            }
            else
                return counterprint(n->left,s);
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
            treeNode->c1();
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
    int dpth(node *n,const string &s,int d)
    {
        if(s==n->str)
            return d;
        else if(n->str<s)
        {
            if( n->right==nullptr)
            {
                return 0;
            }
            else
                return dpth(n->right,s,d+1);
        }
        else if(n->str>s)
        {
            if (n->left==nullptr)
            {
                return 0;
            }
            else
                return dpth(n->left,s,d+1);
        }
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
    cout << l;


}

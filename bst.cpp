#include<iostream>
using namespace std;

struct node{
    int data;
    node *left=NULL;
    node *right=NULL;
};

class bst {
    public:
    node *root = new node();

    bst(){
        cout<<"Enter the data of root node : ";
        int n;
        cin>>n;
        root->data=n;
        root->left=NULL;
        root->right =NULL;
    }

    void insert(node *root , int val){
        if(root==NULL){
            root->data=val;
            root->left=NULL;
            root->right =NULL;
            
            return;
        }

        if(val < root->data ){
            if(root->left==NULL){
                node *newNode = new node ();
                newNode->data=val;
                root->left=newNode;
            }
            else{
                root=root->left;
                insert(root , val);
            }
        }
        else{
            if(root->right==NULL){
                node *newNode = new node ();
                newNode->data=val;
                root->right=newNode;
            }
            else{
                root=root->right;
                insert(root , val);            
            }
        } 
    }

    void search(node *root , int key){
        if(key==root->data){
            cout<<"Key is present in tree !!!\n";
            return;
        }

        if(key < root->data && root->left!=NULL){
            root=root->left;
            search(root , key);
        }
        else if( key > root->data && root->right!=NULL){
            root=root->right;
            search(root , key);
        }
        else{
            cout<<"Key is NOT PRESENT !!\n";
            return;
        }
    }

    void inorder(node *root ){
        if(root!=NULL){
            inorder(root->left);
            cout<<root->data<<"  ";
            inorder(root->right);
        }
    }

    void preorder(node *root){
        if(root!=NULL){
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postOrder(node *root){
        if(root!=NULL){
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->data<<" ";
        }
    }

    void minimum(node *root){
        if(root->left!=NULL){
            minimum(root->left);
        }
        else{
            cout<<"Minimum  : "<<root->data<<endl;;
        }
    }

    void maximum (node *root){
        if(root->right!=NULL){
            maximum(root->right);
        }
        else{
            cout<<"Maximum : "<<root->data<<endl;
        }
    }

    void mirrior (node *root){
        if(root!=NULL){
            node *temp = root->right;
            root->right= root->left;
            root->left= temp;
            mirrior(root->left);
            mirrior(root->right);
        }
    }
};


int main (){
    bst tree;

    cout<<"1.Insert\n2.Search\n3.Display\n4.Minimum\n5.Maximum\n6.Mirrior\n7.Exit\n";
    while(true){
        cout<<"Enter your choice : ";
        int c;
        cin>>c;
        switch (c)
        {
        case 1:
            while(true)
            {
                cout<<"Enter the value added to tree : ";
                int n;
                cin>>n;
                tree.insert(tree.root , n);
                cout<<"Do you want to add more node (1/0) : ";
                int k;
                cin>>k;
                if(k==0){
                    break;
                }
            }
            break;
        case 2:
            cout<<"Enter the value to be searched in tree : ";
            int n;
            cin>>n;
            tree.search(tree.root , n);
            break;
        case 3:
            cout<<"Preorder: ";
            tree.preorder(tree.root);
            cout<<endl;

            cout<<"Inorder: ";
            tree.inorder(tree.root);
            cout<<endl;

            cout<<"Postorder: ";
            tree.postOrder(tree.root);
            cout<<endl;

            break;
        case 4:
            tree.minimum(tree.root);
            break;

        case 5:
            tree.maximum(tree.root);
            break;
        
        case 6: 
            tree.mirrior(tree.root);
            cout<<"Tree after mirrioring \n";
            cout<<"Inorder : ";
            tree.inorder(tree.root);
            break;

        case 7:
            exit(0);
        default:
            return;
        }
    }

    return 0;
}
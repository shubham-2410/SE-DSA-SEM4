#include<iostream>
using namespace std;

struct node{
    string key;
    string meaninig;
    node *left;
    node *right;
};

class avl{
    node *root;

    public:

        avl(){
            root=NULL;
        }

        void create (){
            int n;
            while (true)            
            {
                node *temp = new node();
                cout<<"Enter key : ";
                cin>>temp->key;
                cout<<"Enter meaning : ";
                cin>>temp->meaninig;
                temp->left=temp->right=NULL;
    
                root=insert(root, temp);
                cout<<"Do you want add more (1/0): ";
                cin>>n;
                if(n==0){
                    break;
                }
            }
        }

        node * insert(node *cur , node* temp){
            if(cur==NULL){
                return temp;
            }

            if(temp->key < cur->key){
                cur->left= insert(cur->left , temp);
                cur=balance(cur);
            }
            else if( temp->key > cur->key){
                cur->right=insert(cur->right , temp);
                cur=balance(cur);
            }

            return cur;
        }

        node * balance(node * temp ){
            int bal= diff(temp);

            if(bal>=2){
                if(diff(temp->left)<0){
                    temp=LR(temp);
                }
                else{
                    temp=LL(temp);
                }
            }

            else if (bal<=-2){
                if(diff(temp->right)<0){
                    temp=RR(temp);
                }
                else {
                    temp=RL(temp);
                }
            }

            return temp;
        }

        int diff(node * temp){
            int l = height(temp->left);
            int r = height(temp->right);

            return(l-r);
        }

        int height(node * temp){
            if(temp==NULL){
                return -1;
            }
            else
            return(max(height(temp->left), height(temp->right))+1);
        }

        node * LL(node * par){
            node *temp , *temp1;

            temp=par->left;
            temp1=temp->right;

            temp->right=par;
            par->left=temp1;

            return temp;
        }

        node * RR(node * par){
            node *temp , *temp1;

            temp=par->right;
            temp1=temp->left;

            temp->left=par;
            par->right=temp1;

            return temp;
        }

        node * LR(node *par){
            par->left=RR(par->left);
            return(LL(par));
        }

        node* RL(node * par){
            par->right =LL(par->right);

            return(RR(par));
        }

        void search(){
            cout<<"\nEnter key to be searched : ";
            string str;
            cin>>str;

            if(searchVal(root ,str)){
                cout<<"Key Found !!\n";
            }
            else{
                cout<<"Key not found !!\n";
            }
        }

        void ascending (node *temp){
            if(temp!=NULL){
                ascending(temp->left);
                cout<<temp->key <<"  : "<<temp->meaninig<<"\t\n";
                ascending(temp->right);
            }
        }

        void descending(node *temp){
            if(temp!=NULL){
                descending(temp->right);
                cout<<temp->key<<" : "<<temp->meaninig<<"\t\n";
                descending(temp->left);
            }
        }

        void display(){
            cout<<"Displaying in ascending : \n";
            ascending(root);

            cout<<"Displaying in descending : \n";
            descending(root);
        }
        bool searchVal(node *temp , string key){
            if(temp)
            {
                if(key==temp->key){
                    return true;
                }

                if(key<temp->key){
                    return searchVal(temp->left , key);
                }
                else if(key>temp->key){
                    return searchVal(temp->right , key);
                }
            }
            return false;
            
        }
};

int main(){
    char c;
    int ch;
    avl a;
    do
    {
        cout << "*********************************";
        cout << "\n 1.Insert a keyword in AVL tree.";
        cout << "\n 2.Display the AVL tree.";
        cout << "\n 3.Search a keyword";
        cout << "\n 4.Delete a keyword.";
        cout << "\n Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a.create();
            break;
        case 2:
            a.display();
            break;
        case 3:
            a.search();
            break;
        case 4:
            cout<<"\nDeletion is not implemented  ::\n";
            break;
        default:
            cout << "\n Wrong choice ! ";
        }
        cout << "\n Do you want to continue? (y/n): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

}
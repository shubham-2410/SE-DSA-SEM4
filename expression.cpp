#include<iostream>
#include<stack>
using namespace std;

struct  node
{
    char data;
    node *left;
    node *right;
};

class expression{
    string str;
    node *top;
    public :

        expression(string s){
            str=s;
        }

        void postOrder_nonRecursive(){
            node *T = top;

            stack <node *> s1;
            stack <node *> s2;

            s1.push(T);

            while (!s1.empty())
            {
                T=s1.top();
                s1.pop();
                s2.push(T);

                if(T->left!=NULL){
                    s1.push(T->left);
                }

                if(T->right!=NULL){
                    s1.push(T->right);
                }
            }

            while (!s2.empty())
            {
                T=s2.top();
                s2.pop();
                cout<<T->data;
            }
        }


        void express(){
            int len = str.length();
            stack <node *> s;
            

            for(int i=len-1 ;i>=0 ;i--){
                if(isalpha(str[i])){

                    node *newNode = new node();

                    newNode->data=str[i];
                    newNode->left=NULL;
                    newNode->right=NULL;
                    s.push(newNode);
                }

                else if (str[i]== '*' || str[i]=='/' || str[i]=='+' || str[i]=='-' ){

                    node *newNode = new node();

                    newNode->data=str[i];

                    newNode->left=s.top();
                    s.pop();

                    newNode->right=s.top();
                    s.pop();

                    s.push(newNode);
                }
            }

            top=s.top();
            s.pop();
        }

        void del (node *node){
            if(node==NULL){
                return;
            }

            del(node->left);
            del(node->right);

            cout<<"Deleting node "<<node->data<<endl;
            free(node);
        }

        void Delete(){
            del(top);
        }

};
int main(){

    expression a("+--a*bc/def");
    a.express();
    a.postOrder_nonRecursive();
    a.Delete();
    return 0;
}
#include<iostream>

using namespace std;

struct node
{
    int data;
    string name;
    node *child[10];
};

class general{
    public :
    node *root = new node();

    general(){

    }

    void create(){
        cout<<"\nEnter name of subject : ";
        cin>>root->name;
        cout<<"Enter number of chapters: ";
        cin>>root->data;

        // creating chapters
        for(int i=0 ;i<root->data ;i++){
            root->child[i]=new node();
            cout<<"\n\tEnter name of chapter : ";
            cin>>root->child[i]->name;
            cout<<"\tEnter number of Sections : ";
            cin>>root->child[i]->data;

            // creating sections
            for(int j=0 ;j<root->child[i]->data ;j++){
                root->child[i]->child[j]=new node();
                cout<<"\n\t\tEnter name of Section : ";
                cin>>root->child[i]->child[j]->name;
                cout<<"\t\tEnter number of Sub-Sections : ";
                cin>>root->child[i]->child[j]->data;

                // creating subSection

                for(int k=0 ;k<root->child[i]->child[j]->data ;k++){
                    root->child[i]->child[j]->child[k]=new node();
                    cout<<"\n\t\t\tEnter name of Sub-Section : ";
                    cin>>root->child[i]->child[j]->child[k]->name;
                }
            }
        }
    }

    void display(){
        cout<<"\n\t-----------------Displaying------------------\n";
        cout<<"Subject name : "<<root->name;
        for(int i=0 ;i<root->data ;i++){
            cout<<"\nChapter "<<i+1<<": "<<root->child[i]->name;

            for(int j=0; j< root->child[i]->data ;j++){
                cout<<"\n\tSection "<<j+1<<": "<<root->child[i]->child[j]->name;

                for(int k=0 ;k<root->child[i]->child[j]->data ;k++){
                    cout<<"\n\t\tSub-Section "<<k+1<<": "<<root->child[i]->child[j]->child[k]->name;
                }
            }

        }
    }
};

int main(){

    general book;
    book.create();
    book.display();
}
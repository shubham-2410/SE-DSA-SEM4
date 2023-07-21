#include<iostream>
using namespace std;

const int mx=10;

class Data{
    public:
    string name;
    int pr;
    Data(){}

    Data(string str , int n){
        name=str;
        pr=n;
    }
};

class prQueue{
    Data q[mx];
    int f,r;
    public:

        prQueue(){
            f=-1;
            r=-1;
        }

        void Sort(){
            for(int i=f ;i<r ;i++){
                for(int j=f ; j<r-i ;j++){
                    if(q[j].pr>q[j+1].pr){
                        Data temp=q[j];
                        q[j]=q[j+1];
                        q[j+1]=temp;
                    }
                }
            }
        }

        void display(){
            cout<<"-------------Displaying-------------------\n";
            if(isEmpty()){
                cout<<"No patient is there !!!\n";
                return;
            }
            for(int i=f ;i<=r ;i++){
                cout<<q[i].name<<" - "<<q[i].pr<<" ";
            }
            cout<<endl;
        }

        void enqueue(string str , int n){
            if(isEmpty()){
                f=r=0;
                Data d(str,n);
                q[r]=d;
            }
            else{
                r=r+1;
                Data d(str,n);
                q[r]=d;
            }

            cout<<"Patient "<<str<<" added to queue!!\n";
            Sort();

            display();
            
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty !!\n";
                return;
            }
            
            cout<<q[f].name<<" is send for treatment!!!\n";
            f=f+1;

            if(f>r){
                f=-1;
                r=-1;
            }

            display();
        
        }

        bool isEmpty(){
            if(f==-1 && r==-1){
                return true;
            }

            return false;
        }

        bool isFull(){
            if(r==mx-1){
                return true;
            }

            return false;
        }
};


int main(){

    prQueue p;

    while (true)
    {
        cout<<"1.Add patient\n2.Send patient for treatment\n3.Display\n4.Exit";
        int c;
        cout<<"\nEnter your choice: ";
        cin>>c;

        switch(c){
            case 1:
                while (true)
                {
                    string str;
                    int n;
                    cout<<"Enter Name : ";
                    cin>>str;
                    cout<<"\nChoice Priority\n1.Critical\n2.Medium\n3.Routine checkup\n";
                    cin>>n;

                    p.enqueue(str,n);
                    int k;
                    cout<<"Do you want add more patient (1/0) : ";
                    cin>>k;
                    if(k==0){
                        break;
                    }
                }
                break;
            case 2:
                p.dequeue();
                break;
            case 3:
                p.display();
                break;
            case 4:
                return 0;                

        }
    }
    return 0;
}
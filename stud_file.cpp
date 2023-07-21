#include<iostream>
#include<fstream>

using namespace std;

struct stud{
    int roll;
    string name;
    string address;
    char div;
};

class sequenceFile{

    public:

    void add(){
        stud s1;
        cout<<"Enter name: ";
        cin>>s1.name;
        cout<<"Enter roll no : ";
        cin>>s1.roll;
        cout<<"Enter div : ";
        cin>>s1.div;
        cout<<"Enter address : ";
        cin>>s1.address;
        
        fstream out;
        out.open("studData.txt" ,ios::app | ios::out | ios::binary);

        out.write((char*)&s1 , sizeof(s1));

        out.close();
    }

    void display(){
        stud s;

        fstream file;
        file.open("studData.txt" , ios::in | ios::binary);

        cout<<"\nName\tRollNo\tDiv\tAddress\n";

        while (file.read((char*)&s , sizeof(s)))
        {
            cout<<s.name<<"\t"<<s.roll<<"\t"<<s.div<<"\t"<<s.address<<endl;
        }
        file.close();
    }

    void search(int r){
        fstream file;
        file.open("studData.txt" , ios::in | ios::binary);
        stud s;
        int i=-1;
        while (file.read((char *)&s , sizeof(s)))
        {   i++;
            if(s.roll==r){
                cout<<s.roll<<"\t"<<s.name<<"\t"<<s.div<<"\t"<<s.address<<endl;
                file.close();
                return;
            }
        }
         file.close();
        cout<<"No Such Student !!\n";   
        
    }

    int Delete(int r){
            fstream file;
            file.open("studData.txt" , ios::in | ios::binary);
            
            fstream file2;
            file2.open("new.txt" ,  ios::out | ios::binary);

            stud s;
            bool found=false;

            while (file.read((char *)&s , sizeof(s)))
            {
                if(s.roll!=r){
                    file2.write((char *)&s , sizeof(s));
                }
                else{
                    found=true;
                }
            }
            if (!found)
            {
                cout << "\nStudent not found, so can't delete";
            }

            file2.close();
            file.close();

            remove("studData.txt");
            rename("new.txt", "studData.txt"); 
        }
    
};

int main(){

    sequenceFile f1;
    f1.add();
    f1.add();
    f1.add();
    f1.add();
    f1.display();
    f1.search(15);
    f1.search(10);

    cout<<f1.Delete(6);
    cout<<f1.Delete(10);
    f1.display();
    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

struct emp
{
    int id;
    string name;
    int salary;
    string designation;
};

struct index
{
    int id;
    int idx;
};

class indexSequential
{
    static int ind;

public:
    void add()
    {
        emp e;
        cout << "Enter employee name : ";
        cin >> e.name;
        cout << "Enter employee id : ";
        cin >> e.id;
        cout << "Enter employee designation : ";
        cin >> e.designation;
        cout << "Enter employee salary : ";
        cin >> e.salary;

        index i;
        i.id = e.id;
        ind++;
        i.idx = ind;

        fstream employeeFile, indexFile;

        employeeFile.open("employeeFile.txt", ios::out | ios::app | ios::binary);
        indexFile.open("indexFile.txt", ios::out | ios::app | ios::binary);

        employeeFile.write((char *)&e, sizeof(e));
        indexFile.write((char *)&i, sizeof(i));

        employeeFile.close();
        indexFile.close();
    }

    void displayIndexFile()
    {
        index i;
        cout << "Current status of Index file is :\n";
        cout << "Index\tid\n";
        fstream indexfile;
        indexfile.open("indexFile.txt", ios::in | ios::binary);
        while (indexfile.read((char *)&i, sizeof(i)))
        {
            cout << i.idx << " \t " << i.id << endl;
        }

        indexfile.close();
    }

    void displayEmployeeFile()
    {
        emp e;
        cout << "Current status of Employee file is :\n";
        cout << "Name\tid\tDeignation\tSalary\n";
        fstream employeeFile;
        employeeFile.open("employeeFile.txt", ios::in | ios::binary);
        while (employeeFile.read((char *)&e, sizeof(e)))
        {
            cout << e.name << "\t " << e.id << "  \t  " << e.designation << "\t" << e.salary << endl;
        }

        employeeFile.close();
    }

    void Search(int id)
    {
        bool found = false;
        index i;
        fstream indexFile;
        indexFile.open("indexFile.txt", ios::in | ios::binary);
        int k = -1;
        while (indexFile.read((char *)&i, sizeof(i)))
        {
            k++;
            if (i.id == id)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            cout << "\nEmployee Found \n";
            emp e;
            int offset = k * sizeof(e);
            fstream employeeFile;
            employeeFile.open("employeeFile.txt", ios::in | ios::binary);

            employeeFile.seekg(offset);
            employeeFile.read((char *)&e, sizeof(e));
            cout << e.name << "\t" << e.id << "\t" << e.designation << "\t" << e.salary << endl;

            employeeFile.close();
            return;
        }
        else
        {
            cout << "Employee Not Found !! \n";
        }
    }

    void Delete(int id)
    {
        index i;

        fstream indexFile;
        indexFile.open("indexFile.txt", ios::in | ios::binary);
        int k = -1;
        bool found = false;
        while (indexFile.read((char *)&i, sizeof(i)))
        {
            k++;
            if (i.id == id)
            {
                found = true;
                break;
            }
        }
        indexFile.close();
        if (found)
        {
            index j;
            emp e;
            fstream indexfile, indexFile1;
            fstream employeeFile, employeeFile1;

            indexFile.open("indexFile.txt", ios::in | ios::binary);
            indexFile1.open("tempIndexFile.txt", ios::out | ios::binary); // Use a different filename
            employeeFile.open("employeeFile.txt", ios::in | ios::binary);
            employeeFile1.open("tempEmployeeFile.txt", ios::out | ios::binary);

            while (indexFile.read((char *)&j, sizeof(j)))
            {
                if (id != j.id)
                {
                    indexFile1.write((char *)&j, sizeof(j));
                }
            }

            while (employeeFile.read((char *)&e, sizeof(e)))
            {
                if (id != e.id)
                {
                    employeeFile1.write((char *)&e, sizeof(e));
                }
            }

            indexFile.close();
            indexFile1.close();

            employeeFile.close();
            employeeFile1.close();

            remove("indexFile.txt");
            rename("tempIndexFile.txt", "indexFile.txt");

            remove("employeeFile.txt");
            rename("tempEmployeeFile.txt", "employeeFile.txt");
            cout << "Employee deleted with id : " << id << endl;
        }
        else
        {
            cout << "No employee with id : " << id << endl;
        }
    }
};

int indexSequential::ind = 0;

int main()
{
    indexSequential f;

    f.add();
    f.add();
    f.add();

    f.Search(16);
    f.Search(10);
    cout << endl;

    f.displayEmployeeFile();
    cout << endl;

    f.displayIndexFile();
    cout << endl;

    f.Delete(16);
    f.Delete(10);

    f.displayEmployeeFile();
    cout << "\nAfter deletion:\n";
    f.displayIndexFile();

    return 0;
}

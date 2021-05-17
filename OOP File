//assignment 4
//Write a C++ program that creates an output file,writes information to it, closes the file
//and open it again as an input file and read the information from the file.

#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
    char Name[20];
    int ID;
    double salary;
    public:
        void accept()
        {   
            cout<<"Name :: ";
            cin>>Name;
            cout<<"ID :: ";
            cin>>ID;
            cout<<"Salary :: ";
            cin>>salary;
        }
        void display()
        {
            cout<<"\nName :: "<<Name;
            cout<<"\nId :: "<<ID;
            cout<<"\nSalary :: "<<salary<<endl;
        }
};
       
int main()
{
    Employee o[5];
    fstream f;
    int i,n;
   
    f.open("emp_info.txt");
    cout<<"\nHow many employee information do you need to store ? - ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter information of "<<i+1<<" Employee :- \n";
        o[i].accept();
        f.write((char*)&o[i],sizeof o[i]);
    }
   
    f.close();
   
    f.open("emp_info.txt",ios::in);
    cout<<"\nInformation of Employees is as follows :-\n";
    for(i=0;i<n;i++)
    {
        f.write((char*)&o[i],sizeof o[i]);
        o[i].display();
    }
    f.close();
   
    return 0;
}

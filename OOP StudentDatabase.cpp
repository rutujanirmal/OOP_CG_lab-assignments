//practical 1:Students database
#include<iostream>
using namespace std;

class per_info{
        string dob,lic,bloodgrp;
    public:
        per_info();
        per_info(per_info &);
        ~per_info(){
            cout<<"\nDestructor called!"<<"\nRecord deleted successfully";
        }
        friend class student;
};
//constructor
per_info::per_info(){
    dob="24/09/2001";
    lic="X2Y65z";
    bloodgrp="AB+";
}
//copy contructor
per_info::per_info(per_info &obj){
    dob=obj.dob;
    lic=obj.lic;
    bloodgrp=obj.bloodgrp;
}

class student{
    private:
        string name;
        int rollNo;
        string cls;
        char div;
        long phone;
        string address;  
        static int count; 
    public:
        
        
        void getData(per_info &);
        void printData(per_info &);
        inline static void int_count(){
            count++;
        }
        inline static void show_count(){
            cout<<"\nTotal no of Records : "<<count;
        }
        student ();
        student(student &);
        ~student(){
            cout<<"\nDestructor called\nRecord deleted sucessfully";
        }
};
//constructor
int student::count;
student::student(){
    name="Rutuja";
    rollNo=45;
    cls="SE";
    div='A';
    phone=888858;
    address="Pune";
}
//copy contructor
student::student(student &obj){
    this->name=obj.name;
    this->rollNo=obj.rollNo;
    this->cls=obj.cls;
    this->div=obj.div;
    this->phone=obj.phone;
    this->address=obj.address;
}
//Fuction to input data
void student::getData(per_info &obj){
    cout<<"\n\nEnter data here\n";
    cout<<"Name :: ";
    cin>>name;
    cout<<"Rollno::";
    cin>>rollNo;
    cout<<"DOB(DD/MM/YYYY) :: ";
    cin>>obj.dob;
    cout<<"Class :: ";
    cin>>cls;
    cout<<"Division :: ";
    cin>>div;
    cout<<"Blood Group :: ";
    cin>>obj.bloodgrp;
    cout<<"Telephone no :: ";
    cin>>phone;
    cout<<"Address :: ";
    cin>>address;
    cout<<"Driving license number :: ";
    cin>>obj.lic;
    }

//Function to output data
void student::printData(per_info &obj){
    cout<<"\nSTUDENT DETAILS\n";
    cout<<"******"<<endl
        <<"Name :: "<<name<<endl
        <<"Roll no ::"<<rollNo<<endl
        <<"Date of Birth ::"<<obj.dob<<endl
        <<"Class ::"<<cls<<endl
        <<"Division ::"<<div<<endl
        <<"Blood group ::"<<obj.bloodgrp<<endl
        <<"Phone no ::"<<phone<<endl
        <<"Address ::"<<address<<endl
        <<"Enter the Driving license number ::"<<obj.lic<<endl
        <<"******"<<endl;
    }  

//main function
int main(){
    int n;
    int ch;
    char ans;
    cout<<"\nEnter the number of students : ";
    cin>>n;
    cout<<"------------------------------------";
    student *sobj=new student[n];
    per_info *pobj=new per_info[n];
    do{
        cout<<"\nMenu"
            <<"\n1.Create database"
            <<"\n2.Display database"
            <<"\n3.Copy constructor"
            <<"\n4.Default constructor"
            <<"\n5.Delete(Destructor)"
            <<"\nEnter choice :: ";
        cin>>ch;
        switch (ch)
        {
        case 1://create database
        {
            for(int i=0;i<n;i++){
                sobj[i].getData(pobj[i]);
                sobj[i].int_count();
            }
            break;
        }
            
        case 2://Display database
        {
            sobj[0].show_count();
            for(int i=0;i<n;i++){
                sobj[i].printData(pobj[i]);
            }
            break;
        }
            
        case 3://copy constructor
        {
            student s1;
            per_info p1;
            s1.getData(p1);
            student s2(s1);
            per_info p2(p1);

            cout<<"\nCopy contructor called";
            s2.printData(p2);
            break;
        }
            
        case 4://Default contructor
        {
            student s1;
            per_info p1;
            cout<<"Default constructor called";
            s1.printData(p1);
            break;
        }
            
        case 5://Destructor
        {
            delete[] sobj;
            delete[] pobj;
            break;
        }
        default:{
            cout<<"You Entered Something wrong";
            break;
        }
        }
        cout<<"\nWant to continue(y/n) :: ";
        cin>>ans;
        

    }while(ans=='y' || ans=='Y');
    
    return 0;
}
//end

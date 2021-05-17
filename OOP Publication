//Imagine a publishing company which does marketing for book and audio cassette versions.
//Create a class publication that stores the title (a string) and price (type float) of publications.
//From this class derive two classes:
//book which adds a page count (type int) and tape which adds a playing time in minutes (type float).
//Write a program that instantiates the book and tape class, allows user to enter data and displays the data members
//If an exception is caught, replace all the data member values with zero values.
#include<iostream>
using namespace std;

class publication
{
    string title;
    float price;

    public:
        void add()
        {
            cout<<"\n Enter Publication Information: ";
            cout<<"\n Enter Title of Publication: ";
            cin.ignore();
            getline(cin,title);
            cout<<" Enter Price of Publication :: ";
            cin>>price;

        }
        
        void display()
        {
            cout<<"\n -------------------------------------------";
            cout<<"\n Title of publication            :: "<<title;
            cout<<"\n Publication Price               :: "<<price;    
        }
};

class book : public publication
{
    private:
        int page_count;

    public:
        void add_book()
        {
            try
            {
                add();
                cout<<" Enter page count of book  ::  ";
                cin>>page_count;
                if(page_count <=0)
                throw page_count;
            }catch(int page_count)
            {
                cout<<"Invalid page count";
                page_count=0;
            }
        }

        void display_book()
        {
            display();
            cout<<"\n Page count                      :: "<<page_count;
            cout<<"\n -------------------------------------------";
        }

};

class tape : public publication
{
    private:
        float play_time;
    public:
        void add_tape()
        {
            try
            {
                add();
                cout<<" Enter Play duration of Tape :: ";
                cin>>play_time;
                if(play_time<= 0)
                throw play_time;
            }catch(int pay_time)
            {
                cout<<"\nInvalid play time";
                play_time=0;

            }
        }

        void display_tape()
        {
            display();
            cout<<"\n Play Time                      : "<<play_time<<"min";
            cout<<"\n -------------------------------------------";
        }
};

int main(){
    book b1[10];
    tape t1[10];
    int ch=0,b_count=0,t_count=0;

    do
    {
        cout<<"\n\n-------Publication Information System-------";
        cout<<"\n             -------Menu---------";
        cout<<"\n 1. Add Information to Books ";
        cout<<"\n 2. Add Information to Tapes ";
        cout<<"\n 3. Display Information of Books ";
        cout<<"\n 4. Display Information of Tapes ";
        cout<<"\n 5. Exit ";
        cout<<"\n Enter choice :: ";

        cin>>ch;

        switch(ch)
        {
            case 1:
                b1[b_count].add_book();
                b_count++;
                break;
            
            case 2:
                t1[t_count].add_tape();
                t_count++;
                break;
            
            case 3:
                cout<<"\n----------Publication Information System (Books)---------";
                for(int j=0; j<b_count;j++)
                {
                    b1[j].display_book();
                }
                break;

                            
            case 4:
                cout<<"\n----------- Publication Information System (Tapes)--------";
                for(int j=0; j<t_count;j++)
                {
                    t1[j].display_tape();
                }
                break;
        }
    }while (ch != 5);

    return 0;
}

// OOP Practical 1
//Operation overloading 
//Implement a class complex which represents the complex number data type
//Implement the following:
//1. Constructor (including a default constructor which creates complex number 0+0i)
//2. Overload operator + to add two complex number
//3. Overload operator * to multiply two complex number
//4. Overload operators << and >> to print and read complex number

#include<iostream>
using namespace std;
class complex
{
    private:
        float x;
        float y;
    public:
    complex()
        {
            x=0;
            y=0;
        }
    complex operator+(complex);
    complex operator*(complex);
    friend istream &operator >>(istream &input,complex &t)
        {
            cout<<"Enter the real part :: ";
            input>>t.x;
            cout<<"Enter the imaginary part :: ";
            input>>t.y;
            return input;
        }
    friend ostream &operator <<(ostream &output,complex &t)
        {
            output<<t.x<<"+"<<t.y<<"i\n";
            return output;
        }
};

complex complex::operator+(complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return(temp);
}

complex complex::operator*(complex c)
{
    complex temp2;
    temp2.x=(x*c.x)-(y*c.y);
    temp2.y=(y*c.x)+(x*c.y);
    return (temp2);
}

int main()
{
    complex c1,c2,c3,c4;
    cout<<"Default constructor value=";
    cout<<c1;
    cout<<"\nEnter the 1st number\n";
    cin>>c1;
    cout<<"\nEnter the 2nd number\n";
    cin>>c2;
    c3=c1+c2;
    c4=c1*c2;
    cout<<"\nThe first number is ::  "<<c1<<endl;
    cout<<"\nThe second number is :: "<<c2<<endl;
    cout<<"\nThe addition is :: "<<c3<<endl;
    cout<<"\nThe multiplication is :: "<<c4<<endl;
    return 0;
}

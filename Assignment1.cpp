#include<iostream>
using namespace std;
class Complex{
    int x , y;
    public:
        Complex(){
            x = y = 0;
        }
    Complex operator+(Complex &obj){
        Complex temp;
        temp.x = this->x + obj.x;
        temp.y = this->y + obj.y;
        return temp;
    }
    Complex operator*(Complex &obj){
        Complex temp;
        temp.x = (this->x*obj.x) - (this->y *obj.y);
        temp.y = (this->x*obj.y) + (this->y * obj.x);
        return temp;
    }

    friend istream & operator >>(istream &input , Complex &c){
        cout<<"Enter Real Number: "<<endl;
        input>>c.x;
        cout<<"Enter Imaginary Number: "<<endl;
        input>>c.y;

    }
    friend ostream & operator<<(ostream &output , Complex &c){
        output<<c.x<<" + "<<c.y<<"i"<<endl;
    }
};
int main(){
    int ch;
    Complex c1,c2,c3,c4;
    do
    {
        cout << "______________MENU_________________" << endl;
        cout << "1. Default Constructor" << endl;
        cout << "2. Add Complex numbers" << endl;
        cout << "3. Display Complex number" << endl;
        cout << "4. Addition of Complex numbers" << endl;
        cout << "5. Multiplication of Complex numbers" << endl;
        cout << "6. Exit" << endl;
        
        cout<<"Enter Choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Default Constructor: "<<endl;
            break;
        case 2:
            cout<<"\nEnter first number : "<<endl;
			cin>>c1;
			cout<<"\nEnter second number : "<<endl;
			cin>>c2;
            break;
        case 3:
            cout<<"1st Complex Number : "<<endl;
			cout<<c1;
			cout<<"2nd Complex Number : "<<endl;
			cout<<c2;
            break;
        case 4:
            c3=c1+c2;
			cout<<"Addition of Complex number : "<<endl;
			cout<<c3;
			break;
        case 5:
			
			c4=c1*c2;
			cout<<"Multiplication of Complex number : "<<endl;
			cout<<c4;
			break;
        case 6:
            exit(0);
        }   
    } while (ch!=6);
    
    return 0;
}
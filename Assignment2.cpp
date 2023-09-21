#include<iostream>
#include<string>

using namespace std;
class student{
    public:
    string name,myClass,dob,bg,addr,license; 
	int *rn,div,mob;
    public:
        friend class teacher;
        student(){
            rn = new int;
            name ,myClass,dob , bg , addr, license = "";
            *rn , div, mob = 0;
        } 

        student(student &obj){
            this->name = obj.name;
            this->myClass = obj.myClass;
            this->dob = obj.dob;
            this->bg = obj.bg;
            this->addr = obj.addr;
            this->license = obj.license;
            this->rn = obj.rn;
            this->div = obj.div;
            this->mob = obj.mob;
        }

        ~student(){
            delete rn;
        }


        inline static void header(){
            cout<<"\n ----------------------------Student Data----------------------------";
		    cout<<"\n name \t\t rollno \t division \t class \t\t dateofbirth \t mobile \t blood group \t address \t license numbr";
        }

        void get(){
            cout<<"\n Enter rollno : ";
            cin>>*rn;
            cout<<"\n Enter name : ";
            cin>>name;
            cout<<"\n Enter division : ";
            cin>>div;
            cout<<"\n Enter class : ";
            cin>>myClass;
            cout<<"\n Enter date of birth : ";
            cin>>dob;
            cout<<"\n Enter Blood Group : ";
            cin>>bg;
            cout<<"\n Enter your address : ";
            cin>>addr;
            cout<<"\n Enter License Number : ";
            cin>>license;
            cout<<"\n Enter your Mobile no : "<<endl;
            cin>>mob;
        }

        void display(){
            cout<<"\n"<<name<<"\t"<<*rn<<"\t"<<div<<"\t"<<myClass<<"\t"<<dob<<"\t"<<mob<<"\t"<<bg<<"\t"<<addr<<"\t"<<license;
        }
};

class teacher{
    public:

        void display_t(student &obj ,int t_div){
            try
            {
                if(obj.div == t_div){
                    student::header();
                    obj.display();
                }
                else{
                    throw(obj.div);
                }
            }
            catch (int x) {
                cout << "Student & teacher division cannot be matched";
            }
            
            
        }
};
int main(){

    student s[5];
    student s1,s2;
    int ch , count=0;
    do
    {
        cout << "\n --------------------- Student information system ----------------------";
        cout << "\n -------------------- Menu------------------------";
        cout << "\n 1. Add student record";
        cout << "\n 2. Display student record";
        cout << "\n 3. Copy constructor";
        cout << "\n 4. Division wise information";
        cout << "\n 5. Exit";
        cout << "\n Enter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            s[count].get();
            count++;   
            break;
        case 2:
            student::header();
            for(int i = 0;i<count;i++){
                s[i].display();
            }
            break;
        case 3:
           
            s1.get();
            s2=s1;
            student::header();
            s2.display();
            break;
        case 4:
            int t_div;
            cout << "\n Enter division ";
            cin >> t_div;
            for (int i = 0; i < count; i++) {
                if (s[i].div == t_div) {
                    teacher t;
                    t.display_t(s[i], t_div);
                }
            }
            break;
        case 5:
            exit(0);
        }
    } while (ch != 5);
    
    return 0;
}
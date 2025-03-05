#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class user{
string email;
string name;
string pass;
int userId;

public:
    static int index;
    user(){
        userId=index;
        index++;
    }
    string getemail(){return email;}
    string getname(){return name;}
    string getpass(){return pass;}
    
    void setemail(string n){email=n;}
    void setemail(){
        cin>>email;
    }

    void setname(string n){name=n;}
    void setname(){
        cin>>name;
    }

    void setpass(string n){pass=n;}
    void setpass(){
        cin>>pass;
    }
    void disp(){
        cout<<"Acces Granted \nWelcome "<<name<<"\n";
    }

    
};
int user::index=0;

void SsaveToFile(vector<user>& Suser) {
    ofstream file("Suser.txt"); // Open file for writing
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    for (user& u : Suser) {
        file << u.getname() << " " << u.getemail() << " " << u.getpass() << endl;
    }
    file.close();
    cout << "User data saved successfully!" << endl;
}
void TsaveToFile(vector<user>& Tuser) {
    ofstream file("Tuser.txt"); // Open file for writing
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    for (user& u : Tuser) {
        file << u.getname() << " " << u.getemail() << " " << u.getpass() << endl;
    }
    file.close();
    cout << "User data saved successfully!" << endl;
}

void SloadFromFile(vector<user>& Suser) {
    ifstream file("Suser.txt"); // Open file for reading
    if (!file) {
        cout << "No previous data found." << endl;
        return;
    }
    string name, email, pass;
    while (file >> name >> email >> pass) {
        user newUser;
        newUser.setname(name);
        newUser.setemail(email);
        newUser.setpass(pass);
        Suser.push_back(newUser);
    }
    file.close();
    cout << "User data loaded successfully!" << endl;
}
void TloadFromFile(vector<user>& Tuser) {
    ifstream file("Tuser.txt"); // Open file for reading
    if (!file) {
        cout << "No previous data found." << endl;
        return;
    }
    string name, email, pass;
    while (file >> name >> email >> pass) {
        user newUser;
        newUser.setname(name);
        newUser.setemail(email);
        newUser.setpass(pass);
        Tuser.push_back(newUser);
    }
    file.close();
    cout << "User data loaded successfully!" << endl;
}
int main(){
    bool sflag;
    vector<user> Suser;
    vector<user> Tuser;
    string temp;
    int choice;
    int fchoice;
    SloadFromFile(Suser);
    TloadFromFile(Tuser);
    cout<<"Enter the respective key\n1.Student\n2.Teacher"<<endl;
    cin>>fchoice;

    while(true){
        switch (fchoice)
        {
        case 1://student
        {
            choice=0;
            cout<<"students Enter the respective key\n1.Create Account\n2.Sign in"<<endl;
            cin>>choice;
            cout<<"\n"<<user::index;
            system("cls");

                switch (choice)
            {
                case 1:
                Suser.push_back(user());
                cout<<"Enter your Name;"<<endl;
                Suser[Suser.size()-1].setname();
                cout<<"Enter your Email;"<<endl;
                Suser[Suser.size()-1].setemail();
                cout<<"Create your Password;"<<endl;
                Suser[Suser.size()-1].setpass();
                SsaveToFile(Suser);

                break; 

                case 2:
                cout<<"Enter your Email: ";
                cin>>temp;
                int cmpp;
                int cmp;
                for(int i=0; i<Suser.size(); i++){
                    cmp = temp.compare(Suser[i].getemail());
                    if(cmp==0){
                        cout<<"Enter your Password: ";
                        cin>>temp;
                        cmpp = temp.compare(Suser[i].getpass());
                        if(cmpp==0){
                            Suser[i].disp();
                            sflag=true;
                            break;
                        }
                    
                    }
                }
                if(sflag==false){
                    cout<<"sorry Wrong password or email";
                }
                break;
            }
        }   
        break;
        case 2://teachers
        {
            choice=0;
            cout<<"Enter the respective key\n1.Create Account\n2.Sign in"<<endl;
            cin>>choice;
            cout<<"\n"<<user::index;
            system("cls");

            switch (choice)
            {
                case 1:
                Tuser.push_back(user());
                cout<<"Enter your Name;"<<endl;
                Tuser[Tuser.size()-1].setname();
                cout<<"Enter your Email;"<<endl;
                Tuser[Tuser.size()-1].setemail();
                cout<<"Create your Password;"<<endl;
                Tuser[Tuser.size()-1].setpass();
                TsaveToFile(Tuser);

                break; 

                case 2:
                cout<<"Enter your Email: ";
                cin>>temp;
                int cmpp;
                int cmp;
                for(int i=0; i<Tuser.size(); i++){
                    cmp = temp.compare(Tuser[i].getemail());
                    if(cmp==0){
                        cout<<"Enter your Password: ";
                        cin>>temp;
                        cmpp = temp.compare(Tuser[i].getpass());
                        if(cmpp==0){
                            Tuser[i].disp();
                            sflag=true;
                            break;
                        }
                    
                    }
                }
                if(sflag==false){
                    cout<<"sorry Wrong password or email";
                }
                break;
            }
        }
        break;
        }
    
   
    }
}
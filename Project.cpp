#include<iostream>
#include<string.h>
#include <fstream>
#include <conio.h>
using namespace std;
class Admin{
protected:
    string userName;
    string password;
    string userMail;
    string userType;
public:
    virtual int logUser(){

    }
};
class AdminUser : public Admin{
private:
    string c_code="";
    string c_name="";
    string c_description="";
    string password="";
    string userN;
    string passW;
public:
//create courses to courses.txt
    int logUser(){
        //start here
        int trigger=0;
        ifstream myfile("adminstaff.txt");
        if(myfile.is_open()){
            //int trigger=0;
            while(trigger==0){
                //check the user name and password.
                cout<<"Enter user name :";
                cin>>userN;
                cout<<"Enter password :";
                cin>>passW;
                string s;
                string delimiter = ";";
                size_t pos = 0;
                string token;
                string usna,pass;
                while(getline(myfile,s)){
                    int co = 0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        token = s.substr(0, pos);
                        co++;
                        if(co==1){
                            usna = token;
                        }else if(co==2){
                            pass = token;
                        }
                        s.erase(0, pos + delimiter.length());
                    }
            if(usna==userN&&pass==passW){
                cout<<"Entered correct password...!"<<endl;
                trigger = 1;
                break;
            }
            else{
                trigger = 0;
            }
        }
        if(trigger==0){
            cout<<"Password not correct...!!!"<<endl;
            break;
        }
        }//first while
        }else{
            cout<<"File won't opened";
            }
    return trigger;
    }
    void createCourse(){

    ofstream mfile("courses.txt",ios::app);
    cout<<"Enter Course Code :";
    cin.ignore();
    getline(cin,c_code);
    cout<<"\nEnter Course Name :";
    getline(cin,c_name);
    cout<<"\nEnter Course description : ";
    getline(cin,c_description);
    cin.ignore();
    if(mfile.is_open()){
        mfile<<c_code<<";"<<c_name<<";"<<c_description<<";\n";
        cout<<"\n\tCourse added successfully...\n";
        mfile.close();
    }else{
        cout<<"Can't create file courses.txt";
    }
}
//create accounts as admin
    void createAccount(){
        string accName="";
        string accID="";
        string accMail="";
        char accType;
        int registered;
        int check=0;
        while(check == 0){
            cout<<"Enter name :";
            cin.ignore();
            getline(cin,accName);
            cout<<"Enter registration no :";
            cin>>accID;
            cout<<"Enter account Type (Student - s/S,Management Staff-m/M,System admin- A/a,Academic Staff-L/l):";
            cin>>accType;
            cout<<"Enter email :";
            cin>>accMail;
            cout<<"Enter password for user :";
            cin>>password;
            if((accType=='s'||accType=='S')||(accType=='m'||accType=='M')||(accType=='A'||accType=='a')||(accType=='l'||accType=='L')){
                check =1;
                //create student text
                if(accType=='s'||accType == 'S'){
                     //check here whether accID is there or not
                     ifstream myfile("student.txt");
                     string s;
                     if (myfile.is_open())//openning the file
                      {
                        while ( getline (myfile,s) )//reading the file created
                        {//start while
                            std::string delimiter = ";";
                            size_t pos = 0;
                            string token;
                            string username;
                            int co = 0;
                            registered=0;
                            while ((pos = s.find(delimiter)) != std::string::npos) {
                                token = s.substr(0, pos);
                                co++;
                                if(co==1){
                                    username = token;
                                }
                                s.erase(0, pos + delimiter.length());
                            }
                            if(username==accID){
                                    cout<<"Already Registered...!!!\n";
                                    registered=1;
                                    break;
                                }
                        }//end while
                        myfile.close();//closing the file
                      }
                       else
                        cout << "Unable to open file"<<endl;
                    //end here accID check
                    if(registered!=1){
                        cout<<"creating file\n";
                        ofstream afile("student.txt",ios::app);
                        if(afile.is_open()){
                            afile<<accID<<";"<<password<<";"<<accName<<";"<<accType<<";"<<accMail<<";\n";
                            system("cls");
                            cout<<"Student added successfully\n";
                            afile.close();
                    }
                    }else{
                        cout<<"Unable to create account file.";
                        break;
                    }
                }//s S if end
                else if(accType=='m'||accType == 'M'){
                    ofstream afile("manage.txt",ios::app);
                    if(afile.is_open()){
                        afile<<accID<<";"<<password<<";"<<accName<<";"<<accType<<";"<<accMail<<";\n";
                        system("cls");
                        cout<<"Management Staff member added successfully\n";
                        afile.close();
                    }else{
                        cout<<"Unable to create account file.";
                        break;
                    }
                }//else if m M end
                else if(accType=='a'||accType == 'A'){
                    ofstream afile("adminstaff.txt",ios::app);
                    if(afile.is_open()){
                        afile<<accID<<";"<<password<<";"<<accName<<";"<<accType<<";"<<accMail<<";\n";
                        system("cls");
                        cout<<"Admin staff member added successfully\n";
                        afile.close();
                    }else{
                        cout<<"Unable to create account file.";
                        break;
                    }
                }// admin a A end if
                else if(accType=='l'||accType == 'L'){
                    ofstream afile("lectures.txt",ios::app);
                    if(afile.is_open()){
                        afile<<accID<<";"<<password<<";"<<accName<<";"<<accType<<";"<<accMail<<";\n";
                        system("cls");
                        cout<<"Academic staff member added successfully\n";
                        afile.close();
                    }else{
                        cout<<"Unable to create account file.";
                        break;
                    }
                }//academic l L end if
            }
            else{
                check =0;
                char c;
                system("cls");
                cout<<"Invalid Account type...!!!"<<endl;
                cout<<"Do you want to enter again?(Y/y/N/n)";
                cin>>c;
                if(c=='y'||c=='Y'){
                    check =0;
                }else if(c=='n'||c=='N'){
                    check = 1;
                }else{
                    cout<<"Invalid input...!!!";
                    break;
                }
            }
        }
    }
};
class Course{

public:
    void showCourses(){
        cout<<"Displaying all Courses : \n";
        ifstream myfile ("courses.txt");//creating the file
        if(myfile.is_open()){
            std::string delimiter = ";";
            string s;
            size_t pos = 0;
            std::string token;
            int co = 0;
            //int a=0;
            cout<<"Number\t\tCourse ID \t\tCourse Name \t\tCourse Description"<<endl;
            cout<<"------------------------------------------------------------------------------------------"<<endl;
            while(getline (myfile,s)){
                co++;
                cout<<co;
                while ((pos = s.find(delimiter)) != std::string::npos) {
                    token = s.substr(0, pos);
                    std::cout << "\t\t"<<token ;
                    s.erase(0, pos + delimiter.length());
                }
                cout<<endl;
            }//endwhile

        }else{
            cout<<"Unable to open courses file.,!!\n"<<endl;
        }
    }
};
class Student:public Admin,public Course
{
private:
string userN="admin";
string passW="root";
string courseID;
string tempID;
string StPresent ;
public:
    string checkStudent(){
        cout<<"Enter student id : ";
        cin>>tempID;
        string s;
        string delimiter = ";";
        size_t pos = 0;
        string token;
        string username;

      ifstream myfile ("student.txt");//creating the file
      if (myfile.is_open())//openning the file
      {
        while ( getline (myfile,s) )//reading the file created
        {
          int co = 0;
            while ((pos = s.find(delimiter)) != std::string::npos) {
                token = s.substr(0, pos);
                co++;
                if(co==1){
                    username = token;
                }
                s.erase(0, pos + delimiter.length());
            }
            if(username==tempID){
                StPresent=username;
                break;
            }else
                StPresent ="NULL";
        }
        myfile.close();//closing the file
      }
      else cout << "Unable to open file";

        return StPresent;
    }
    int logUser(){
    //start here
        int trigger=0;
        ifstream myfile("student.txt");
        if(myfile.is_open()){
            //int trigger=0;
            while(trigger==0){
                //check the user name and password.
                cout<<"Enter user name :";
                cin>>userN;
                cout<<"Enter password :";
                cin>>passW;
                string s;
                string delimiter = ";";
                size_t pos = 0;
                string token;
                string usna,pass;
                while(getline(myfile,s)){
                    int co = 0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        token = s.substr(0, pos);
                        co++;
                        if(co==1){
                            usna = token;
                        }else if(co==2){
                            pass = token;
                        }
                        s.erase(0, pos + delimiter.length());
                    }
            if(usna==userN&&pass==passW){
                cout<<"Entered correct password...!"<<endl;
                trigger = 1;
                tempID=userN;
                break;
            }
            else{
                trigger = 0;
            }
        }
        if(trigger==0){
            cout<<"Password not correct...!!!\n"<<endl;
            break;
        }
        }//first while
        }else{
            cout<<"File won't opened\n";
            }
        //end here
    return trigger;
    //logUser function end here
    }
    void logSystem(){
        ifstream myfile("student.txt");
        if(myfile.is_open()){
            cout<<"No prob\n";
            int trigger=0;
            while(trigger==0){
                //check the user name and password.
                cout<<"Enter user name :";
                cin>>userN;
                cout<<"Enter password :";
                cin>>passW;
                string s;
                string delimiter = ";";
                size_t pos = 0;
                string token;
                string usna,pass;
                while(getline(myfile,s)){
                    int co = 0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        token = s.substr(0, pos);
                        co++;
                        if(co==1){
                            usna = token;
                        }else if(co==2){
                            pass = token;
                        }
                        s.erase(0, pos + delimiter.length());
                    }

            if(usna==userN&&pass==passW){
                cout<<"Entered correct password...!"<<endl;
                trigger = 1;
            }
            else{
                trigger = 0;
            }
        }
        }//first while
        }else{
            cout<<"File won't opened";
            }
    }
// show courses from course.txt then create courseStudent.txt which include st_id, course id
    void registerCourse(string a){
        string st_id=a;
        showCourses();
        cout<<"Select Course ID to register : ";
        cin>>courseID;
        ifstream myfile ("courses.txt");//creating the file
        if(myfile.is_open()){
            std::string delimiter = ";";
            string s;
            size_t pos = 0;
            std::string token;
            int co = 0;
            char choice;
            string c_id="";
            int found=0;
            while(found ==0){
                //while found
                while(getline (myfile,s)){
                    co=0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        co++;
                        token = s.substr(0, pos);
                        s.erase(0, pos + delimiter.length());

                        if(co==1){
                            c_id=token;
                            if(c_id==courseID){
                                cout<<"course found"<<endl;
                                //create courses_student text file.
                                ofstream myfile("courses_student.txt",ios::app);
                                 if (myfile.is_open())
                                  {
                                    myfile <<st_id <<";"<<c_id<<";"<<endl;
                                    myfile.close();
                                  }
                                  else cout << "Unable to open the file";

                                found=1;
                                break;
                            }else
                                continue;
                        }
                    }
                }

            if(found==0){
            cout<<"no such a course " <<endl;
            break;
            }
  //end found while
            }
            //endwhile

        }else{
            cout<<"Unable to open courses file..!!\n"<<endl;
        }
    }//end register course
    string getStuID(){
        return tempID;
    }
};
class AcademicStaff:public Admin{
protected:
string st_id;
string userN;
string passW;
public:
    //start here log
    int logUser(){
    //start here
        int trigger=0;
        ifstream myfile("lectures.txt");
        if(myfile.is_open()){
            while(trigger==0){
                //check the user name and password.
                cout<<"Enter user name :";
                cin>>userN;
                cout<<"Enter password :";
                cin>>passW;
                string s;
                string delimiter = ";";
                size_t pos = 0;
                string token;
                string usna,pass;
                while(getline(myfile,s)){
                    int co = 0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        token = s.substr(0, pos);
                        co++;
                        if(co==1){
                            usna = token;


                        }else if(co==2){
                            pass = token;
                        }
                        s.erase(0, pos + delimiter.length());
                    }
            if(usna==userN&&pass==passW){
                cout<<"Entered correct password...!"<<endl;
                trigger = 1;
                break;
            }
            else{
                trigger = 0;
            }
        }
        if(trigger==0){
            cout<<"Password not correct...!!!"<<endl;
            break;
        }
        }//first while
        }else{
            cout<<"File won't opened";
            }
        //end here
    return trigger;
    //logUser function end here
    }
    //end here log
//show courses.txt and after selecting course show all the students who registered to that course.
    void viewRegisteredCourses(string s){
        //check student here
        st_id = s;
        //cout<<st_id;
        //copy
        ifstream myfile ("courses_student.txt");//creating the file
        if(myfile.is_open()){
            string temp;
            std::string delimiter = ";";
            string s;
            size_t pos = 0;
            std::string token;
            int co = 0;
            char choice;
            int p =0;
            int found=0;
            int counter=1;
            cout<<"Number\t\t"<<"Course\n";
            cout<<"-------------------------\n";
                while(getline (myfile,s)){
                    co=0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        co++;
                        token = s.substr(0, pos);
                        s.erase(0, pos + delimiter.length());

                        if(co==1){
                            temp=token;
                            if(temp==st_id){
                                p=1;
                                continue;

                            }else
                                p=2;
                                continue;
                            }
                            if(co==2&&p==1){

                                cout<<counter<<"\t\t";
                                cout<<token<<endl;
                                counter++;
                        }
                    }
                }
        }else{
            cout<<"Unable to open courses file..!!\n"<<endl;
        }
        //end copy
    }//end viewCourses

};
class ManagementStaff : public AcademicStaff{
private:
    string st_id;
public:
     int logUser(){
    //start here
        int trigger=0;
        ifstream myfile("manage.txt");
        if(myfile.is_open()){
            while(trigger==0){
                //check the user name and password.
                cout<<"Enter user name :";
                cin>>userN;
                cout<<"Enter password :";
                cin>>passW;
                string s;
                string delimiter = ";";
                size_t pos = 0;
                string token;
                string usna,pass;
                while(getline(myfile,s)){
                    int co = 0;
                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        token = s.substr(0, pos);
                        co++;
                        if(co==1){
                            usna = token;
                        }else if(co==2){
                            pass = token;
                        }
                        s.erase(0, pos + delimiter.length());
                    }

            if(usna==userN&&pass==passW){
                cout<<"Entered correct password...!"<<endl;
                trigger = 1;
                break;
            }
            else{
                trigger = 0;
            }
        }
        if(trigger==0){
            cout<<"Password not correct...!!!"<<endl;
            break;
        }
        }//first while

        }else{
            cout<<"File won't opened";
            }
        //end here
    return trigger;
    //logUser function end here
    }
    //view reg student
    void viewRegisteredCourses(string s){
        //check student here
        st_id = s;

        //copy
        ifstream myfile ("courses_student.txt");//creating the file
        if(myfile.is_open()){
            string temp;
            std::string delimiter = ";";
            string s;
            size_t pos = 0;
            std::string token;
            int co = 0;
            char choice;
            int p =0;
            int found=0;
            int counter=1;
            cout<<"Number\t\t"<<"Course\n";
            cout<<"-------------------------\n";
                while(getline (myfile,s)){
                    co=0;

                    while ((pos = s.find(delimiter)) != std::string::npos) {
                        co++;
                        token = s.substr(0, pos);
                        s.erase(0, pos + delimiter.length());

                        if(co==1){

                            temp=token;
                            if(temp==st_id){
                                p=1;
                                continue;

                            }else
                                p=2;
                                continue;
                            }

                            if(co==2&&p==1){

                                cout<<counter<<"\t\t";
                                cout<<token<<endl;
                                counter++;
                        }
                    }
                }
        }else{
            cout<<"Unable to open courses file..!!\n"<<endl;
        }
        //end copy
    }//end viewCourses
};
void logScreen(){
    string u,p;
    cout<<"\n___________________________________________\n";
    cout<<"\t\tWelcome\t\t\n";
    cout<<"-------------------------------------------\n";
    cout<<"\t\tSystem Login\t\t";
    cout<<"\n-------------------------------------------\n";
    cout<<"\n";

}
void menu(){
    cout<<"\t1.Login as System Admin\t\n";
    cout<<"\t2.Login as Student\t\n";
    cout<<"\t3.Login as Academic Staff\t\n";
    cout<<"\t4.Login as Management Staff\t\n";
    cout<<"\t5.Exit\t\n";

}
void adminUserMenu(){
    cout<<"\tAdmin User Menu\n";
    cout<<"\n\t1. Create Account\n";
    cout<<"\t2. Create Course\n";
    cout<<"\t3. Back\n";
    cout<<"Enter choice :";
}
void studentUserMenu(){
    cout<<"\Student User Menu\n";
    cout<<"\t1. Register a Course\n";
    cout<<"\t2. Back\n";
    cout<<"Enter choice : ";
}
void academicUserMenu(){
    cout<<"\Academic Staff User Menu\n";
    cout<<"\t1. View Registered course \n";
    //cout<<"\t2. View Students\n";
    cout<<"\t2. Exit\n";
    cout<<"Enter choice : ";
}
void managementUserMenu(){
    cout<<"\tManagement Staff User Menu\n";
    cout<<"\t1. View Registered course \n";
    cout<<"\t2. Exit\n";
    cout<<"Enter choice : ";
}
int main(){
    AdminUser ad;
    Student st;
    AcademicStaff as;
    ManagementStaff mg;
    int choice;
    //menu();
    while(1){
        logScreen();
        menu();
        cout<<"Enter Choice : ";
        cin>>choice;
        //while(!cin){}
        switch(choice){
        case 1:
            {
                system("cls");
                int a=0;

                a=ad.logUser();
                if(a==1){//if start
                    int c;
                    adminUserMenu();
                    cin>>c;
                    if(c==1){
                        ad.createAccount();

                    }
                    else if(c==2){
                        ad.createCourse();
                        system("cls");
                    }else if(c==3){
                        break;
                    }else{
                        cout<<"Invalid Choice...\n";
                        //break;
                    }
                }//if end

                break;
            }
        case 2:
            {
                system("cls");
                int ab=0;
                ab=st.logUser();
                system("cls");
                if(ab==1){
                    int st_choice;
                    studentUserMenu();
                    cin>>st_choice;

                    if(st_choice==1){
                        st.registerCourse(st.getStuID());
                        system("cls");
                        cout<<"Course registered successfully..."<<endl;
                    }else if(st_choice==2){
                        break;
                    }else
                        cout<<"Invalid Choice...!!!\n";

                }else{
                    cout<<"Username or Password is incorrect...!!\n";
                }
                //after log
                //end after log


                break;

            }
        case 3:
            {
                system("cls");
                int ab=0;
                ab=as.logUser();
                system("cls");
                string temp;
                if(ab==1){
                    int as_choice;
                    academicUserMenu();
                    cin>>as_choice;
                    if(as_choice==1){
                        //check whether student is there or not
                        temp=st.checkStudent();

                        if(!(temp=="NULL")){
                            as.viewRegisteredCourses(temp);
                            getch();
                            system("cls");
                        }else
                            cout<<"No such a student...\n";
                    }else if(as_choice==2){
                        break;
                    }
                }else{
                    cout<<"Wrong password or username.\n"<<endl;
                }
                break;
            }
        case 4:
            {
            system("cls");
            int mng=0;
            mng=mg.logUser();
            system("cls");
            string temp;
            if(mng==1){
                int mg_choice;
                managementUserMenu();
                cin>>mg_choice;
                if(mg_choice==1){
                    temp=st.checkStudent();
                if(!(temp=="NULL")){
                    as.viewRegisteredCourses(temp);
                    getch();
                     system("cls");
                    }else
                        cout<<"No such a student...\n";
                    //mg.viewRegisteredCourses();
                }else if(mg_choice==2){
                    system("cls");
                    break;
                }
            }else{
                cout<<"Wrong password or username.\n"<<endl;
            }
            break;
            }
        default:{
            system("cls");
            cout<<"\n\tInvalid Choice...\n";
            break;
        }
        }//end switch
        if(choice==5){
            system("cls");
            cout<<"\t_________________________\n";
            cout<<"\t\tBye...!!!\t\t\n";
            cout<<"\tHave a nice day...!\n";
            cout<<"\t_________________________\n";
            break;
        }
        if(!cin){//check string
            cout << "\n ERROR, enter an integer...!\n" ;
            cin.clear();
            cin.ignore(256,'\n');
        }//end check string
    }

    return 0;
}
//ICT/19/20/022
//S.P.D.M.V.Dharmasinghe
//4963

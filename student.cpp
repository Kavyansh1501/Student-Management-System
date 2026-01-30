  #include<iostream>
 #include<fstream>
 using namespace std;

 class temp{
    string rollno,name,fname,address,search;
    fstream file;
    public:
    void addstudent();
    void viewstudent();
    void searchstudent();
 }obj;
 int main(){
    char choice;
    cout<<"1- add students records"<<endl;
    cout<<"2- view all students records"<<endl;
    cout<<"3- search students records"<<endl;
    cout<<"4- exit"<<endl;
    cout<<"enter your choice ::";
    cin>>choice;

    switch(choice){
        case '1':
        cin.ignore();
        obj.addstudent();

        break;
        case '2':
        obj.viewstudent();

        break;
        case '3':
        obj.searchstudent();

        break;
        case '4':
        return 0;
        
        break;

        default:
            cout<<"invalid choice";

    }
 }
 void temp::addstudent(){
    cout<<"enter student roll number ::";
    getline(cin,rollno);
    cout<<"enter student name ::";
    getline(cin,name);
    cout<<"enter student fathers name ::";
    getline(cin,fname);
    cout<<"enter student addres";
    getline(cin,address);

    file.open("student.txt",ios::out | ios::app);
    file<<rollno<<"*"<<name<<"*"<<fname<<"*"<<address<<endl;
    file.close();
 }
  
 void temp::viewstudent(){
    file.open("student.txt",ios::in);
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*'); 
    getline(file,address,'\n');
    while(!file.eof()){
        cout<<"student roll number ::"<<rollno<<endl;
        cout<<"student name ::"<<name<<endl;
        cout<<"student fathers name ::"<<fname<<endl;
        cout<<"student address ::"<<address<<endl;
        cout<<"-------------------------------"<<endl;

        getline(file,rollno,'*');
        getline(file,name,'*');
        getline(file,fname,'*'); 
        getline(file,address,'\n');
    }
    file.close();
 }

 void temp::searchstudent(){
    cout<<"enter student roll no";
    getline(cin,search);
    file.open("student.txt",ios::in);
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    while(!file.eof()){
        if(rollno == search){
            cout<<"student roll number ::"<<rollno<<endl;
            cout<<"student name ::"<<name<<endl;
            cout<<"student fathers name ::"<<fname<<endl;
            cout<<"student address ::"<<address<<endl;
            cout<<"-------------------------------"<<endl;
    }
        getline(file,rollno,'*');
        getline(file,name,'*');
        getline(file,fname,'*'); 
        getline(file,address,'\n');
    }

 }
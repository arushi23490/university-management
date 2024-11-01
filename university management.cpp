#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

class University{
private:
	string RollNo, Name, Subject, Address;
public:
University():RollNo(""), Name(""), Subject(""), Address(""){}

setRollNo(string rollNo){
RollNo = rollNo;
}

setName(string name){
 Name = name;
}

setSubject(string subject){
 Subject = subject;
}

setAddress(string address){
 Address = address;
}

string getRollNo(){
return RollNo;
}

string getName(){
 return Name;
}

string getSubject(){
 return Subject;
}

string getAddress(){
 return Address;
}
};

add(University student){
string rollNo, name, subject, address;

cout<<"\tEnter RollNo Of Student: ";
cin>>rollNo;
student.setRollNo(rollNo);

cout<<"\tEnter Name Of Student: ";
cin>>name;
student.setName(name);

cout<<"\tEnter Subject Of Student: ";
cin>>subject;
student.setSubject(subject);

cout<<"\tEnter Address Of Student: ";
cin>>address;
student.setAddress(address);

ofstream out("D:/university.txt", ios::app);
if(!out){
cout<<"\tError: File Can't Open!"<<endl;
}

else{
out<<"\t"<<student.getRollNo()<<" : "<<student.getName()<<" : "<<student.getSubject()
<<" : "<<student.getAddress()<<endl<<endl;
}
out.close();
cout<<"\tStudent Added Successfuly!"<<endl;
}

search(){
	string rollNo;
cout<<"\tEnter RollNo Of Student: ";
cin>>rollNo;

ifstream in("D:/university.txt");
if(!in){
cout<<"\tError: File Can't Open!"<<endl;
}
string line;
bool found = false;
while(getline(in, line)){
int data = line.find(rollNo);
if(data != string::npos){

cout<<"\t"<<line<<endl;
found = true;
	break;
}

}
	if(!found){
cout<<"\tStudent Not Found!"<<endl;
}
in.close();

}

update(University student){
string rollNo;
cout<<"\tEnter RollNo Of Student: ";
cin>>rollNo;

ofstream outfile("D:/university.txt");

if( !outfile){
	cout<<"\tError: File Can't Opne!"<<endl;
}

string line;
bool found = false;
while(getline(outfile, line)){
int pos = line.find(rollNo);
if(pos != string::npos){
	found = true;
string address;
cout<<"\tEnter New Address: ";
cin>>address;
student.setAddress(address);

int newPos = line.find_last_of(':');
line.replace(newPos + 2, string::npos, student.getAddress());
	break;
}


}
if(!found){
cout<<"\tStudent Not Found!"<<endl;
}
outfile.close();


cout<<"\tData Updated!"<<endl;
}

int main(){
University student;

bool exit = false;
while(!exit){
	system("cls");
int val;
cout<<"\tWelcome To University Management System"<<endl;
cout<<"\t***************************************"<<endl;
cout<<"\t1.Add Student."<<endl;
cout<<"\t2.Search Student."<<endl;
cout<<"\t3.Update Data Of Student."<<endl;
cout<<"\t4.Exit."<<endl;
cout<<"\tEnter Your Choice: ";
cin>>val;

if(val==1){
system("cls");
add(student);
Sleep(6000);
}

else if(val==2){
system("cls");
search();
Sleep(6000);
}

else if(val==3){
system("cls");
update(student);
Sleep(6000);
}

else if(val==4){
system("cls");
exit = true;
cout<<"\tGood Luck!"<<endl;
Sleep(3000);
}	
}
}

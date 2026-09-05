#include<iostream>
#include<string>
using namespace std;

class patient{
	 int patientId;
	 string name;
	 int age;
	 string ward;
	 const string bloodgroup;

public:
	 patient():patientId(0),name("unkown"),age(0),ward("general"),bloodgroup("o+"){
		 cout<<"[constructor] Default patient registered."<<endl;}
		 patient(int id,const string& name):patientId(id),name(name){
			 cout<<"[constructor] Emergency admission: "<<name<<endl;}
		 patient(int id,const string& name , int age ,const string& ward ,const string& bg):
			 patientId(id),name(name),age(age),ward(ward),bloodgroup(bg){
			 cout<<"[constructor] Full admission: "<<name<<endl;}

		 void displayDetails()const{
			 cout<<"===Patient Record==="<<endl;
			 cout<<"ID: "<<patientId<<endl;
			 cout<<"Name: "<<name<<endl;
			 cout<<"Age: "<<age<<endl;
			 cout<<"Ward: "<<ward<<endl;
			 cout<<"Blood grp: "<<bloodgroup<<endl;
		 }

		 void transferWard(const string& newWard){
			 ward = newWard;
			 cout<<"ward transfer: "<<name<<"->"<<ward<<endl;}

		 ~patient(){
			 cout<<"[Destructor] Patient "<< name <<" discharged"<<endl;		 }
};

int main2(){
	patient p1(1001,"Meera Joshi",34,"Cardiology","B+");
	patient p2(1002,"Raj Patel");
	patient p3;
	cout<<endl;

	p1.displayDetails();
	cout<<endl;


	int sz = 4;
	patient* ptr = new patient[sz];

	cout << endl;

	for(int i = 0; i < sz; i++){
		ptr[i].displayDetails();
		cout << endl;
	}

		p2.transferWard("ICU");
		cout<<endl;


		delete[] ptr;
		return 0;

}

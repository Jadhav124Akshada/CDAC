#include<iostream>
using namespace std;

int main14(int argc,char* argv[]){

	if(argc<4){
		cout<<"Arguments are missing"<<endl;
		return 1;
	}
	int warn_threshold=stoi(argv[1]);
	int critical_threshold=stoi(argv[2]);
	int num_reading=stoi(argv[3]);

	if(warn_threshold>critical_threshold){
		cout<<"warning threshold must be less than critical threshold"<<endl;
		return 1;
	}

	if(num_reading>=1 && num_reading<=500){

	}
	else{
		cout<<"give reading between 1& 500"<<endl;
		return 1;
	}
	cout<<"warn"<<warn_threshold<<"critical"<<critical_threshold<<"readings"<<num_reading<<endl;

	int normalcount=0;
	int warningcount=0;
	int criticalcount=0;
	int shutdowncount=0;

	for(int i=0; i<num_reading;i++){
		int num=rand()%70;

		if(num>0 && num<=29){
			normalcount++;
		}else if(num>=30 && num<=num){
			warningcount++;
		}else if (num>=45 && num<=59){
			criticalcount++;
		}else{
			shutdowncount++;
		}
	}
	cout<<"Results"<<"Normal"<<normalcount<<"Warning"<<warningcount<<"Critical"<<criticalcount<<"Shutdown"<<shutdowncount<<endl;
	return 0;
}

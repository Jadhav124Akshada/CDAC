#include <iostream>
using namespace std;

int main1() {
	 double c;
	 int statuscode;
	 string statuslable;

	 cout<<"Enter sensor Reading(°C):";
	 if (!(cin>>c)){
		 cout<<"Invalid input"<<endl;
		 return 1;
	 }

	 double f =(c*9/5)+32;


	 if(c<0){
		   statuscode=-1;
		   statuslable="sensor_error";
	   }else if (c>=0 && c<=29){
		   statuscode=0;
		   statuslable="normal";
	   }else if (c>=30 && c<=44){
		   statuscode=1;
		   statuslable="warning";
	   }else if (c>=45 && c<=59){
		   statuscode=2;
		   statuslable="critical";
	   }else{
		   statuscode=3;
		   statuslable="shutdown";
	   }
    cout<<"Temperature:"<<c<<"°C/"<<f<<"°F"<<endl;
    cout<<"Status:"<<statuslable<<endl;

    cout<<"Action:";
    switch (statuscode){
    case -1:
    	cout<<"sensor fauilt-check wiring";
    	break;
    case 0:
    	cout<<"no action required";
    	break;
    case 1:
    	cout<<"alert sent to supervisor";
    	break;
    case 2:
    	cout<<"cooling system triggered";
    	break;
    case 3:
    	cout<<"emergency shutdown initiated ";
    	break;
    }
    cout<<endl;

    string evalaution =(c >= 25.0) ? "Above Average" : "Below Average";
    cout<<"Reading :"<<evalaution<<endl;

	return 0;
}

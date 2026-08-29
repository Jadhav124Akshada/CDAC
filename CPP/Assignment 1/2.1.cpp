#include<iostream>
#include<cmath>
using namespace std;

void resetSensorPairV1(int reading1,int reading2){
	  int temp = reading1;
	  reading1 = reading2;
	  reading2 = temp;


}
void resetSensorPairV2(int &reading1,int &reading2){
	  int temp = reading1;
	  reading1 = reading2;
	  reading2 = temp;
}
	  void resetSensorPairV3(int *reading1,int *reading2){
	  	  int temp = *reading1;
	  	  *reading1 = *reading2;
	  	  *reading2 = temp;
	  }

int main21(){
	  int reading1 = 55;
	  int reading2 = 12;

	   cout<<"--- V1: Call by Value ---"<<endl;
	   cout<<"before:"<<"A="<<reading1<<" "<<"b="<<reading2<<endl;
	   resetSensorPairV1(reading1,reading2);
	  cout<<"After:"<<"A="<<reading1<<" " <<"b="<<reading2<<endl<<endl;

	  cout<<"--- V2: Call by Reference ---"<<endl;
	  cout<<"before:"<<"A="<<reading1<<" "<<"b="<<reading2<<endl;
	  resetSensorPairV2(reading1,reading2);
	  cout<<"After:"<<"A="<<reading1<<" " <<"b="<<reading2<<endl<<endl;

      /*1. Version 1 fails because it implements 'Call by Value', which copies raw data into isolated local memory stack frames.
	    2. The temporary inner variables 'reading1' and 'reading2' are successfully swapped internally inside the function.
	    3. However, since the function only modifies local replicas, the parent variables 'a' and 'b' remain untouched.*/

	  cout<<"--- V3: Call by Pointer ---"<<endl;
	  cout<<"before:"<<"A="<<reading1<<" "<<"b="<<reading2<<endl;
	  resetSensorPairV3(&reading1,&reading2);
	  cout <<"After:"<<"A="<<reading1<<" "<<"b="<<reading2<<endl;

	  return 0;
}

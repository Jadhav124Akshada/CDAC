#include<iostream>
using namespace std;

int printReadings(double arr[] , int &num){

    int count = 0;
    cout<<"Valid readings : ";
    for(int i = 0;i<num;i++){
        if(arr[i] < 0){
            count++;
            continue;
        }else{
            cout<<arr[i]<<" ";
        }
    }
    cout << endl;
    return count;

}

void scanReadings(double arr[] , int &num){

    for(int i = 0;i<num;i++){
        if(arr[i] >= 45){
            cout<< "First CRITICAL : Index " << i << " -> " <<arr[i] << " C" << endl;
            break;
        }
    }

}

void minMaxAvg(double arr[] , int &num){
    double min = arr[0];
    double max = arr[0];
    double avg;
    double sum = 0;
    int count = 0;

    for(int i = 0;i<num;i++){
        if(arr[i] > 0){
            if(min > arr[i]){
                min = arr[i];
            }
            if(max < arr[i]){
                max = arr[i];
            }
            sum += arr[i];
            count++;
        }
    }

    avg = sum / count;

    cout << "Min : " << min << " C" << " \t Max : "<< max << " C" <<" \t Avg : " << avg <<" C"<< endl;
}

void readingType(double arr[], int &num){
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;
    for(int i = 0;i<num;i++){
         if(arr[i] >= 0 && arr[i] <= 29){
            normal++;
        }else if(arr[i] >= 30 && arr[i] <= 44){
            warning++;
        }else if(arr[i] >= 45 && arr[i] <= 59){
            critical++;
        }else if(arr[i] >= 60){
            shutdown++;
        }
    }

    cout<< "Normal : "<<normal << "\t Warning : " << warning << "\tCritical : "<<critical << "\t Shutdown : " << shutdown<< endl;
}

int main12(){
    int num;
    cout<< "Enter the number of reading's: ";
    cin>>num;

    double arr[num];
    cout<<"Enter all the readings: ";
    for(int i = 0;i<num;i++){
        cin>>arr[i];
    }

    int skipped = printReadings(arr,num);

    cout<< "Skipped (errors) : " << skipped << endl;

    scanReadings(arr,num);
    minMaxAvg(arr,num);
    readingType(arr,num);
}

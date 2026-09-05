#include<iostream>
using namespace std;


class LogBuffer{
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

    public:

    // GETTER
    char* getBuffer() const{
        return buffer;
    }

    int getCapacity() const{
        return capacity;
    }

    int getSize() const{
        return size;
    }

    static int getInstanceCount(){
        return instanceCount;
    }


    LogBuffer(int capacity): capacity(capacity) , size(0) , buffer(new char[capacity]){
        instanceCount++;
        cout<< "Construtor with 1 argument called"<< endl;
    }
    // Deep Copy
    LogBuffer(const LogBuffer& other)  : capacity(other.capacity) , size(other.size) , buffer(new char[other.capacity]){
        cout<< "Deep Copy Constructor" << endl;
        for(int i = 0;i<size;i++){
            buffer[i] = other.buffer[i];
        }
    }

    // Copy Assignment Operator — must handle self-assignment, release old memory, deep copy
    LogBuffer& operator=(const LogBuffer& other){

        cout<< "Copy Assignment operator" << endl;
        if(this != &other){
            delete buffer;

            size = other.size;
            capacity = other.capacity;

            for(int i = 0;i<other.size;i++){
                buffer[i] = other.buffer[i];
            }
        }

        return *this;
    }

    // Destructor — frees the buffer, decrements instanceCount
    ~LogBuffer(){
        instanceCount--;
        cout<< "Destructor Called "<< endl;
    }

    void append(const char* msg){
        // Appends msg to buffer (up to capacity)

        int length = 0;
        //Find Lenght of msg
        while(msg[length] != '\0'){
            length++;
        }

        for(int i = 0;i<length && size < capacity ; i++){
            buffer[size] = msg[i];
            size++;
        }

        // End the string
        buffer[size] = '\0';

    }
    void print() const{
        // Prints current buffer contents
        int size = getSize();

        for(int i = 0 ; i<size ; i++){
            cout<< buffer[i] << " " ;
        }
    }
    void clear(){
        // Resets size to 0
        buffer[0] = '\0';
        size = 0;
    }

};

int LogBuffer::instanceCount = 0;

int main(){

    // Objective 1 : Basic usage
    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    cout<< endl;
    log1.append(" | Request received from 192.168.1.10");
    cout<< endl;
    log1.print();
    cout<< endl;

    // Objective 2 : Deep copy via copy constructor
    LogBuffer log2 = log1; // copy constructor
    cout << endl;
    log2.append(" | Cached response sent");
    cout << endl;

    cout << "log1 : " ;  log1.print() ; // must NOT contain log2's append
    cout<< endl;
    cout << "log2 : " ;  log2.print();
    cout<< endl;

    // Objective 3 : Copy Assignment operator
    LogBuffer log3(128);
    log3 = log1;
    log3.print();
    cout<< endl;

    // Objective 4 : Self-assignment guard
    log1 = log1;
    log1.print();
    cout<< endl;

    // Objective 5 : static member
    cout<< "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;

    return 0;

    // All 3 objects destroyed here - destructors must print and decrement count

}

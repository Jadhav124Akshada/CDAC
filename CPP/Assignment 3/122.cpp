#include<iostream>
#include<memory>
using namespace std;

class AudioClip{
    string name;
    double radius;

    public:


    string getName(){
        return this->name;
    }

    double getRadius(){
        return this->radius;
    }


    void setName(string name){
        this->name = name;
    }

    void setRadius(double radius){
        this->radius = radius;
    }

    AudioClip(string name , double radius) : name(name) , radius(radius){
        cout<< "Audio compiled !" << endl;
    }

    ~AudioClip(){
        cout<< "Audio released !" << endl;
    }
};

int main122(){
    shared_ptr<AudioClip> audio = make_shared<AudioClip>("Explosion",3.5);

    cout<< "Use Count : " << audio.use_count() << endl;
    weak_ptr<AudioClip> observer = audio;

    if(auto clip = observer.lock()){
        cout<< "Clip Alive : " << clip->getName() << endl;
    }
    audio.reset();

    if(observer.expired()){
        cout<<"Observer Expired" << endl;
    }

}

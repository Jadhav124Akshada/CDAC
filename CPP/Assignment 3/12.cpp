#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Texture{

	string name;
	int width;
	int height;

public:

	Texture(string name,int width, int height):name(name),width(width),height(height){
		cout<<"Texture loaded"<<endl;
	}
	~Texture(){
		cout<<"Texture release"<<endl;
	}
	void display(){
		cout<<"Texture name:"<<name<<endl;
		cout<<"Texture width:"<<width<<endl;
		cout<<"Texture height:"<<height<<endl;
	}
};
	int main125(){
	auto text1=make_unique<Texture>("player_sprite",512,512);
	text1->display();
	unique_ptr<Texture>text2=move(text1);
	cout<<"text1 is null:"<<(text1==nullptr ? "yes":"no")<<endl;

    return 0;
}



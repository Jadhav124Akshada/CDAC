#include<iostream>
#include<memory>
using namespace std;

class Shared{
	string name;
	string type;
public:

	Shared(string name,string type):name(name),type(type){
		cout<<"shared loaded"<<endl;
	}
	~Shared(){
		cout<<"shared release"<<endl;
	}
};
int main124(){
	auto shader = make_shared<Shared>("main_vert", "vertex");
	    cout << "Ref count: " << shader.use_count() << endl;

	    {
	        auto rendererRef = shader;
	        cout << "Ref count: " << shader.use_count() << endl;

	        auto editorRef = shader;
	        cout << "Ref count: " << shader.use_count() << endl;
	    }

	    cout << "Ref count: " << shader.use_count() << endl;
	 return 0;
}

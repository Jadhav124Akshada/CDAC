#include<iostream>
using namespace std;

class entity{
	string name;
	int health;
	int level;
	string type;
public:
	entity() {

		}

	entity(string name,int health,int level,string type){
		this->name=name;
		this->health=health;
		this->level=level;
		this->type=type;
	}

	string getName()const{
		return name;
	}
	int getHealth()const{
		return health;
	}
	int getLevel()const{
		return level;
	}
	string getType()const{
		return type;
	}
	entity& setName(const string& name){
		this->name=name;
		return*this;
	}
	entity& setHealth(int health){
		this->health=health;
		return*this;
	}
	entity& setLevel(int level){
			this->level=level;
			return*this;
		}
	entity& setType(const string& type){
			this->type=type;
			return*this;
		}
	void displayInfo()const{
		cout<<"Name:"<<name<<endl;
		cout<<"Health:"<<health<<endl;
		cout<<"Level:"<<level<<endl;
		cout<<"Type:"<<type<<endl;

	}
};
int level = 1;

namespace Physics {
    double clamp(double val, double min, double max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }

    double lerp(double a, double b, double t) {
        return a + t * (b - a);
    }
}

namespace GameMath {
    int clamp(int val, int min, int max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }

    double lerp(double a, double b, double t) {
        return a + t * (b - a);
    }
}

namespace Engine {
    namespace Audio {
        void playSound(string name) {
            cout << "Playing: " << name << endl;
        }
    }
}
	int main(){
		entity player, enemy, item;
		player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
		enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
		item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

	player.displayInfo();
	enemy.displayInfo();
	item.displayInfo();
	int level = 10;
	    cout << "=== Scope Resolution Bonus ===" << endl;
	    cout << "Global Game Difficulty Level: " << ::level << endl;
	    cout << "Local Player Level: " << level << endl;

	    Engine::Audio::playSound("sword_clash");
	    cout << endl;

	    cout << "=== Part B: Namespaces ===" << endl;
	    cout << "Physics clamp (double): " << Physics::clamp(15.5, 0.0, 10.0) << endl;
	    cout << "GameMath clamp (int): " << GameMath::clamp(155, 0, 100) << endl;
	    cout << "Physics lerp: " << Physics::lerp(0.0, 100.0, 0.5) << endl;

	    {
	        using namespace GameMath;
	        cout << "Inside limited block scope (GameMath lerp): " << lerp(10.0, 20.0, 0.2) << endl;
	    }
	    cout << endl;

	    cout << "=== Part C: Dynamic 2D Game Map ===" << endl;
	    int R, C;
	    cout << "Enter rows (R): ";
	    cin >> R;
	    cout << "Enter columns (C): ";
	    cin >> C;

	    int** map = new int*[R];
	    for (int i = 0; i < R; i++) {
	        map[i] = new int[C];
	    }

	    srand(time(0));

	    int grass = 0, water = 0, mountain = 0, forest = 0, dungeon = 0;
	    for (int i = 0; i < R; i++) {
	        for (int j = 0; j < C; j++) {
	            map[i][j] = rand() % 5;

	            switch (map[i][j]) {
	                case 0: grass++; break;
	                case 1: water++; break;
	                case 2: mountain++; break;
	                case 3: forest++; break;
	                case 4: dungeon++; break;
	            }
	        }
	    }

	    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====" << endl;
	    for (int i = 0; i < R; i++) {
	        for (int j = 0; j < C; j++) {
	            cout << " " << map[i][j];
	        }
	        cout << endl<<endl;
	    }

	    cout << "Legend: 0=Grass 1=Water 2=Mountain 3=Forest 4=Dungeon" << endl;

	    cout << "\nTile Count:" << endl;
	    cout << " Grass : " << grass << endl;
	    cout << " Water : " << water << endl;
	    cout << " Mountain : " << mountain << endl;
	    cout << " Forest : " << forest << endl;
	    cout << " Dungeon : " << dungeon << endl;

	    for (int i = 0; i < R; i++) {
	        delete[] map[i];
	    }
	    delete[] map;
	    return 0;
	}


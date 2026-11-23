// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Enemy {
protected:
	std::string name;
	int hp;

public:
	Enemy(const std::string& name, int hp) : name(name), hp(hp){}

	virtual ~Enemy(){
		std::cout << name << " nestaje" << std::endl;
	}

	virtual void take_damage(int d) {
		hp -= d;
		if (hp < 0) hp = 0;
	}

	void print() {
		std::cout << name << " " << hp << std::endl;
	}

	bool is_dead() {
		return hp <= 0;
	}
};

class Goblin : public Enemy {
	public: 
		Goblin() : Enemy("Goblin", 20) {}
};

class Bat : public Enemy {
private:
	int udarac = 0;

public: 
	Bat() : Enemy("Bat", 15) {}

	void take_damage(int d) {
		if (udarac % 2 == 1) {
			udarac++;
			std::cout << "Izbjegnut udarac\n" << std::endl;
		}
		else {
			udarac++;
			Enemy::take_damage(d);
		}

	}
};

class Ghost: public Enemy {
public: 
	Ghost() : Enemy("Ghost", 30) {}

	void take_damage(int d) {
		Enemy::take_damage(d/2);
	}
};

class Level {
private:
	std::vector<Enemy*> enemies;

public:
	Level() = default;


	~Level() {
		for (Enemy* e : enemies) {
			delete e;
		}
		enemies.clear();
	}


	void add(Enemy* e) {
		if (e != nullptr) {
			enemies.push_back(e);
		}
	}

	size_t size() const {
		return enemies.size();
	}
	
	void explode(int d) {
		for (Enemy* e : enemies) {
			e->take_damage(d);
		}
	}

	void print() {
		for (Enemy* e : enemies) {
			e->print();
		}
	}

	void remove_dead() {
		
		auto mrtav = [](Enemy* e) {return e->is_dead(); };
		enemies.erase(remove_if(enemies.begin(), enemies.end(), mrtav));
	}

};



int main()
{
	Level cave;
	cave.add(new Goblin);            // od sada je cave vlasnik neprijatelja
	cave.add(new Bat);
	cave.add(new Ghost);
	cave.add(new Goblin);
	std::cout << cave.size() << '\n';

	cave.explode(10);                // bomba pogodi sve neprijatelje
	cave.print();
	std::cout << "---\n";
	cave.explode(10);
	cave.print();
	std::cout << "---\n";
	cave.remove_dead();
	std::cout << cave.size() << '\n';
	std::cout << "--- kraj ---\n";
	return 0;                        // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

	4
	Goblin 10
	Bat 5
	Ghost 25
	Goblin 10
	---
	Bat izbjegne udarac
	Goblin 0
	Bat 5
	Ghost 20
	Goblin 0
	---
	Goblin nestaje
	Goblin nestaje
	2
	--- kraj ---
	Bat nestaje
	Ghost nestaje
*/

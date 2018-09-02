#pragma once

enum PetType { Dog, Cat };

class Pet {

private:
	PetType type;
	std::string name;
	int age;

public:
	Pet();
	Pet(PetType t, std::string n, int a) {
		type = t;
		name = n;
		age = a;
	}
	~Pet() {}

	PetType GetType() { return type; }
	std::string GetName() { return name; }
	int GetAge() { return age; }

};
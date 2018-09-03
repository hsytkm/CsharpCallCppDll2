#pragma once

class Pet {
public:
	enum Type { Dog, Cat };

private:
	Type type;
	std::string name;
	int age;

public:
	Pet();
	Pet(Type t, std::string n, int a) {
		type = t;
		name = n;
		age = a;
	}
	~Pet() {}

	Type GetType() { return type; }
	std::string GetName() { return name; }
	int GetAge() { return age; }

};
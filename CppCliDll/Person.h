#pragma once

namespace CppCliDll {
	public ref class Person
	{
	private:
		System::String^ name;
		int age;

	public:
		Person(System::String^ name, int age)
		{
			this->name = name;
			this->age = age;
		}

		~Person() {}
		!Person() {}

		System::String^ GetName() { return name; }
		int GetAge() { return age; }

	};
}

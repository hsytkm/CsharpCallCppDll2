#pragma once

class NativeCppClass {

private:
	int param;

public:
	NativeCppClass() { param = 1; }
	NativeCppClass(int x);
	~NativeCppClass() {}

	int GetParam() const { return param * 10; }
	std::string GetString() const;
};
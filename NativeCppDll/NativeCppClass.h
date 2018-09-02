#pragma once

class NativeCppClass {

private:
	int param;

public:
	NativeCppClass() { param = 1; }
	NativeCppClass(int x);
	~NativeCppClass() {}

	void SetParam(int);
	int GetParam() const { return param * 10; }
	std::string GetString(std::string) const;
};
#pragma once
#include <string>

class ResourceManager final														
{
public:
	static ResourceManager* initInstance(void* hInstance);
	static ResourceManager* getInstance();
	void setInstance(void* hInstance);
	std::wstring loadString(unsigned int ID) const;
private:
	ResourceManager();
	ResourceManager(void* hInstance) : hInstance(hInstance) {}
	void* hInstance;
};


#include "ResourceManager.h"
#include <memory>
#include <Windows.h>

namespace {
	ResourceManager* instance = nullptr;
}

ResourceManager* ResourceManager::initInstance(void* hInstance)
{
	if (instance) {
		delete instance;
	}
	instance = new ResourceManager(hInstance);
	return instance;
}

ResourceManager* ResourceManager::getInstance()
{
	return instance;
}

void ResourceManager::setInstance(void* hInstance)
{
	this->hInstance = hInstance;
}

std::wstring ResourceManager::loadString(unsigned int ID) const
{
	int length = LoadStringW((HINSTANCE)hInstance, ID, nullptr, 0);
	if (length == 0) {
		return std::move(std::wstring());
	}
	std::unique_ptr<wchar_t> buffer(new wchar_t[(size_t)length + 1], std::default_delete<wchar_t>());
	length = LoadStringW((HINSTANCE)hInstance, ID, buffer.get(), length + 1);
	if (length == 0) {
		return std::move(std::wstring());
	}
	std::wstring res(buffer.get());
	return std::move(res);
}

ResourceManager::ResourceManager()
{
	this->hInstance = GetModuleHandleW(NULL);
}



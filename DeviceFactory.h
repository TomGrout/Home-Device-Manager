#pragma once
#include "Device.h"

using namespace std;

class DeviceFactory
{
public:
	static Device* createProduct(const string& type, const string& name);
};


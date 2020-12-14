#include "ds18b20.h"

DS18B20::DS18B20(std::string address)
{
    std::cout << "address: " << address << std::endl;
}

DS18B20::DS18B20()
{
    std::cout << "Find DS18B20 sensor ..." << std::endl;
}

DS18B20::~DS18B20() {}

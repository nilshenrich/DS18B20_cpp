#include "ds18b20.h"

DS18B20::DS18B20(std::string address): address("/sys/bus/w1/devices/" + address + "/w1_slave")
{
    std::cout << "Set address to " << address << std::endl;
}

DS18B20::DS18B20()
{
    std::cout << "Find DS18B20 sensor ..." << std::endl;
}

DS18B20::~DS18B20() {}

float DS18B20::readTemp()
{
    // Open file descriptor to read from one-Wire
    // std::unique_ptr<FILE, int(*)(FILE*)> reader{fopen(address.c_str(), "r"), fclose};
    std::unique_ptr<FILE, int(*)(FILE*)> reader {fopen(address.c_str(), "r"), fclose};

    // Check if file descriptor could be opened properly
    if (!reader.get() || ferror(reader.get()))
    {
        std::cerr << "Error while opening \"" << address << "\"" << std::endl;

        return std::numeric_limits<float>::min();
    }

    // Read current temperature from file descriptor
    char buffer[256] {0};
    std::cout << "Read: " << fread(buffer, 1, 256, reader.get()) << ": " << std::string(buffer) << std::endl;

    return 0.0;
}

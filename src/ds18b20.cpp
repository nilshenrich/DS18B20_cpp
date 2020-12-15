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
    // Open one-Wire reader as file stream and read
    std::ifstream reader {address};

    // Check if read was good
    if (!reader.good())
    {
        std::cerr << "Read from DS18B20 failed!" << std::endl;

        return std::numeric_limits<float>::min();
    }

    // Read first and second lines from message
    // Format of message:
    // 64 01 55 05 7f a5 81 66 7c : crc=7c YES
    // 64 01 55 05 7f a5 81 66 7c t=22250
    std::string firstLine, secondLine;
    getline(reader, firstLine);
    getline(reader, secondLine);

    // Get status from message (Last word of first line)
    std::string status{firstLine.substr(firstLine.find_last_of(" ") + 1)};

    // Check if temperature was read properly
    if ("YES" != status)
    {
        std::cerr << "Temperature was not measured properly!" << std::endl;

        return std::numeric_limits<float>::min();
    }

    // Get temperature from message (Number after "t=")
    int tempInt{std::stoi(secondLine.substr(secondLine.find("t=") + 2))};

    // Return temperature divided by 1000
    return (float)tempInt / 1000;
}

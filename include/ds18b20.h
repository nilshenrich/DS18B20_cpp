#ifndef DS18B20_H
#define DS18B20_H

#include <string>
#include <regex>
#include <limits>
#include <fstream>
#include <filesystem>
#include <iostream>

class DS18B20
{
public:

    /**
     * Empty constructor
     * Sensor address is searched automatically
     * (Only ONE sensor must be connected to raspberry pi)
     */
     DS18B20();

     /**
      * Constructor with fix sensor address
      */
     DS18B20(std::string address);

     /**
      * Empty destructor
      */
     virtual ~DS18B20();

     /**
      * Read temperature in degrees celsius
      * @return float
      */
     float readTemp();

private:

    // Root folder of all one-Wire devices
    static const std::string oneWireRootFolder;

    // File name of one-Wire device
    static const std::string oneWireFile;

    // Address of DS18B20 sensor (Calculated in Constructor)
    std::string address;
};

#endif // DS18B20_H

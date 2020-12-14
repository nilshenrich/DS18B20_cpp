#ifndef DS18B20_H
#define DS18B20_H

#include <string>
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
};

#endif // DS18B20_H

#include "ds18b20.h"

#include <iostream>

using namespace std;

int main()
{
    DS18B20 ds18b20{};

    ds18b20.readTemp();

    return 0;
}

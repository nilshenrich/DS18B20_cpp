#include "ds18b20.h"

#include <bcm2835.h>
#include <iostream>

using namespace std;

int main()
{
    // Initialize bcm2835 library
    if (!bcm2835_init())
    {
        cerr << "Initialize BCM2835 failed!" << endl;

        return -1;
    }

    // Set GPIO 4 to input with pullup
    bcm2835_gpio_fsel(4, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(4, BCM2835_GPIO_PUD_UP);

    DS18B20 ds18b20 {"28-3c01d6076edb"};

    cout << "Temperature = " << ds18b20.readTemp() << " degrees Celsius" << endl;

    return 0;
}

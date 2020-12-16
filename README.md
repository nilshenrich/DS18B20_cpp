# DS18B20_cpp

This is small installable c++ library for raspverry pi (or other single board computers) to communicate with a DS18B20 temperature sensor.

## Usage

```cpp
void test()
{
    // Set GPIO connected to sensors one-Wire interface to input with PullUp resistor
    // In this example, the bcm2835 library is used, but all other libraries are also good
    bcm2835_gpio_fsel(4, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(4, BCM2835_GPIO_PUD_UP);

    // Connect to sensor by creating a new DS18B20 object
    // Give the sensors HW address as parameter in the constructor
    // You can get the HW address of connected one-Wire devices via folder names in /sys/bus/w1/devices/
    DS18B20 ds18b20 {"28-3c01d6076edb"}

    // Alternatively you can tell the system to search for a connected sensor
    // Please notice that this method can only find ONE sensor,
    // if you want to connect multible DS18B20 sensors, please specify the HW addresses as shown above
    DS18B20 ds18b20_alt;

    // Read the current temperature with one simple method call
    // The temperature unit is degrees Celsius and the datatype is float
    float currentTemp = ds18b20.readTemp();
}
```

## Installation

This library can be installed this way:

1. Clone git repository
1. Create Makefile to compile code
1. Compile code locally
1. Install library by copying the code to library folder

```console
<go to your favourite folder to clone into>
git clone https://github.com/nilshenrich/DS18B20_cpp.git DS18B20_cpp
cd DS18B20_cpp
mkdir build
cd build/
cmake ..
make
sudo make install
```

To run test programm, go to repositorys root folder and run compileTest.sh:
```console
./compileTest.sh
```

After compiling has finished successfully, a binary file has been created in build folder you can execute:
```console
cd build/
./DS18B20
```

Now the include file ds18b20.h lies in /usr/local/include\
and the lib files lie in /usr/local/lib

### Error help

If you get a compiler error because not found include files in you project that uses this DS18B20 library, adding the compiler search path "/usr/local/include" may fix it.\
If you get a linker error, adding the linker search path "/usr/local/lib" and the linker flag "-lds18b20" may fix it.

If you get a runtime error like this:
```
error while loading shared libraries: libds18b20.so.1: cannot open shared object file: No such file or directory
```
runnig this command can solve it:
```console
sudo /sbin/ldconfig -v
```

[See link](https://itsfoss.com/solve-open-shared-object-file-quick-tip/)

## Needed packages

To run the installation process properly, some packages must be preinstalled on your system.\
This installation guide is for debian based distributions. If you run another operating system, please see specific documentation for package installation on the internet.

1. build-essential (Contains the needed C/C++ compiler)
1. cmake

```console
sudo apt install build-essential
sudo apt install cmake
```

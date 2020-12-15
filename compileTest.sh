#!/bin/bash

g++ -std=c++17 -c ds18b20_test.cpp -I./include/ -o build/ds18b20_test.o
g++ -o build/DS18B20 build/ds18b20_test.o -L./build -lds18b20 -lbcm2835 -lstdc++fs

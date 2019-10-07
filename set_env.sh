#!/bin/bash

export PATH=$PATH:~/esp/xtensa-lx106-elf/bin
export IDF_PATH=~/esp/ESP8266_RTOS_SDK/
python -m pip install --user -r $IDF_PATH/requirements.txt
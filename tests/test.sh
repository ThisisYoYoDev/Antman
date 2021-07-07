#!/usr/bin/env bash

git clone https://github.com/ThisisYoYoDev/Mouli_Antman.git
make && make clean
cp antman/antman Mouli_Antman/.
cp giantman/giantman Mouli_Antman/.
cd Mouli_Antman/
./yoyoli.sh
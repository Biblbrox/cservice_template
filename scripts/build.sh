#!/bin/bash

scripts/update_submodules.sh

if [ -d "build" ]; 
then
	rm -rf build/*
else
        mkdir -p build
fi

sed -i 's/add_definitions( -DTRACE )/#add_definitions( -DTRACE )/g' CMakeLists.txt

cd build

cmake ..

make -j $(($(nproc) - 1))

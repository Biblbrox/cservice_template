#!/bin/bash

scripts/update_submodules.sh

if [ -d "build" ]; 
then
	rm -rf build/*
else
        mkdir -p build
fi

sed -i 's/#add_definitions( -DGUI )/add_definitions( -DGUI )/g' CMakeLists.txt

cd build

cmake ..

make -j $(($(nproc) - 1))

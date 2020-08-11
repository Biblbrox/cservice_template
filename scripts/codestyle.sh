#!/bin/bash

if [ -d "build" ]; 
then
	rm -rf build/*
else
        mkdir -p build
fi

cd build
cmake -DGUI=OFF .. &>/dev/null

main=$(find ../src/ -name main.cpp)

include_args="$(cat ./compile_commands.json | grep command | sed "s/-I/\n-I/g" | grep -v command | awk '{print $1}' | sed "s/-I/-I /g")"

checks=$(cat ../external/cpp_codestyle/codestyle.cfg)

clang-tidy -config="$checks" $main -p=. --header-filter="src/*" -- $include_args -std=c++17 2>/dev/null
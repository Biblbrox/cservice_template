#!/bin/bash

if [ -d "build" ]; 
then
	rm -rf build/*
else
    mkdir -p build
fi

cd build
cmake -DGUI=OFF .. &>/dev/null

main=$(find ../src/ -type d -name '*plot*' -prune -o -name '*.cpp' -o -name '*.h' )

include_args="$(cat ./compile_commands.json | grep command | sed "s/-I/\n-I/g" | grep -v command | awk '{print $1}' | sed "s/-I/-I /g")"

checks=$(cat ../cfg/sanalyzer.cfg)

clang-tidy -config="$checks" $main -p=. --header-filter="src/*" -- $include_args -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -pthread -std=c++11 -fexception -fPIC -std=gnu++17 2>/dev/null


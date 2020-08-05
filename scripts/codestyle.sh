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

checks=$(cat ../cfg/codestyle.cfg)

#clang-tidy -config="$checks" $main -p=. --header-filter="src/*" --quiet -- $include_args -std=c++17

format=$(cat ../cfg/code_format.cfg)
file_list=$(find ../src/ -not -path "*/plot/*" -regextype posix-egrep -regex ".*\.(h|cpp)$")

for fname in $file_list; do
	echo $fname
	clang-format --dry-run --style="{IndentWidth: 4, ColumnLimit: 100}" $fname
done
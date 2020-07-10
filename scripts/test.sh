#!/bin/bash

if [ -d "test/build_test" ];
then
        rm -rf test/build_test/*
else
        mkdir -p test/build_test
fi

cd test/build_test

cmake ..

make -j $(($(nproc) - 1))

shopt -s extglob
rm -rf !("test_door_detector")

./test_door_detector

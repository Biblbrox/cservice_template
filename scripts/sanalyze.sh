#!/bin/bash

files=$(find -name "*.h" -or -name "*.cpp")
clang-tidy $files -- -std=c++17

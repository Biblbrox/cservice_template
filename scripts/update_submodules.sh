#!/bin/bash
git submodule update --init --recursive
cd external/zcm_types && ./zcm_gen.sh

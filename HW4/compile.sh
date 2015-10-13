#!/bin/bash

rm a.out
rm results.txt
g++ -ansi -pedantic -Wall -Wextra -Wconversion -Wno-unused-parameter -Wno-unused-but-set-variable -Wunused-variable -std=c++11 closepair_test.cpp closepair.cpp  >results.txt 2>&1
cat results.txt | grep error


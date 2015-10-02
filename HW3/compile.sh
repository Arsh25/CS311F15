#!/bin/bash

rm results.txt
g++ -ansi -pedantic -Wall -Wextra -Wconversion -Wno-unused-parameter -Wno-unused-but-set-variable -Wunused-variable -std=c++11 da3_test.cpp da3.cpp  >results.txt 2>&1

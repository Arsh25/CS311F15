#bin/bash

rm results.txt
g++ -ansi -pedantic -Wall -Wextra -Wconversion -Wno-unused-parameter -Wno-unused-but-set-variable -std=c++11 ssarray_test.cpp  >results.txt 2>&1

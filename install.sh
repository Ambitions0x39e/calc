#!/bin/zsh
xcode-select --install
cd Probability\ Distribution
g++ probability_calculator_fraction.cpp -o probability_calculator_fraction -O2
g++ probability_calculator_float.cpp -o probability_calculator_float -O2
echo "C++ files successfully compiled!"
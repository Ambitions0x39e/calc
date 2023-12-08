#!/bin/zsh

echo "Checking Xcode command line tools..." >&2
sleep 5
if ! command -v clang >/dev/null 2>&1; then
  echo "Xcode command line tools not installed. Installing..." >&2
  xcode-select --install
  exit 1
fi
echo "Xcode command line tool is successfully installed." >&2
echo "Compiling C++ files..." >&2
sleep 5
mkdir exes
cd Probability\ Distribution
g++ probability_calculator_fraction.cpp -o ../exes/probability_calculator_fraction -O2 -lm
g++ probability_calculator_float.cpp -o ../exes/probability_calculator_float -O2 -lm
cd ../exes
chmod +x ./probability_calculator_float ./probability_calculator_fraction
cd ../
echo "C++ files successfully compiled!" >&2

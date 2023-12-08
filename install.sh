#!/bin/zsh
echo "Checking Xcode command line tools..." >&2
sleep 5
if ! command -v clang >/dev/null 2>&1; then
  echo "Xcode command line tools not installed. Installing..." >&2
  xcode-select --install
  exit 1
fi
echo "Xcode command line tool is successfully installed. Compiling..." >&2
sleep 5
cd Probability\ Distribution
g++ probability_calculator_fraction.cpp -o ../exes/probability_calculator_fraction -O2
g++ probability_calculator_float.cpp -o ../exes/probability_calculator_float -O2
chmod +x probability_calculator_fraction probability_calculator_float
echo "C++ files successfully compiled!" >&2

#!/bin/zsh
# Get system name
environment_name=`uname`
echo "Starting checking informations" >&2
sleep 2
echo "System name: `uname`" >&2
sleep 2
echo "Checking Environment Dependencies" >&2
# Check dependencies under Darwin & Linux 
  if test $environment_name = "Darwin"; then
    sleep 5
    if ! command -v clang >/dev/null 2>&1; then
      echo "Xcode Command Line Tools not installed. Installing..." >&2
      xcode-select --install
    fi 
    echo "Xcode command line tool is successfully installed." >&2
  fi
  if test $environment_name = "Linux"; then
    if ! command -v g++ >/dev/null 2>&1; then
      echo "G++ not installed. Installing..." >&2
      sudo apt-get install g++
    fi
  fi
sleep 3
echo "Compiling C++ files..." >&2
sleep 5
if test -d exes; then 
  rm -rf exes
fi
mkdir exes
# Compile Files about Probability Distribution
echo "Compile: Probability Distribution" >&2
sleep 2
cd Probability\ Distribution
  g++ probability_calculator_fraction.cpp -o ../exes/probability_calculator_fraction -O2 -lm -w
  g++ probability_calculator_float.cpp -o ../exes/probability_calculator_float -O2 -lm -w
  cd ../exes
   chmod +x ./probability_calculator_float ./probability_calculator_fraction
  cd ../
# Compile Files about Variance & SD
echo "Compile: Variance & Standard Deviation" >&2
sleep 2
cd Variance\ and\ SD
  g++ variance.cpp -o ../exes/variance -O2 -lm -w
  cd ../exes
    chmod +x ./variance
  cd ../
# Compile special features
echo "Compile: features" >&2
sleep 2
cd features
  g++ sort-files.cpp -o ../exes/sort-files -O2 -lm -w
  g++ combination.cpp -o ../exes/combination -O2 -lm -w
  g++ permutation.cpp -o ../exes/permutation -O2 -lm -w
  cd ../exes
    chmod +x ./sort-files
    chmod +x ./combination
    chmod +x ./permutation
  cd ../
# Compile Main
echo "Compile: Main C++ File" >&2
sleep 1
g++ main.cpp -o main -O2 -lm -w
echo "C++ files successfully compiled!" >&2
echo "Now, putting the executable file in to path" >&2
echo "In this process it might require computer password, ">&2
echo "Please input your password, the terminal won't show the password you typed in." >&2
sleep 1
cp main acalc
sudo cp acalc /usr/local/bin
echo "Successfully installed!" >&2
echo "You can use acalc in your terminal to execute. " >&2
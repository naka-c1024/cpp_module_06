#!/bin/zsh
./convert ""
printf "\n"
./convert "ab"
printf "\n"
./convert 4.2.1
printf "\n"

./convert ' '
printf "\n"
./convert a
printf "\n"
./convert 90
printf "\n"
./convert 0
printf "\n"

./convert inf
printf "\n"
./convert +inf
printf "\n"
./convert -inf
printf "\n"
./convert nan
printf "\n"
./convert +nan
printf "\n"
./convert -nan
printf "\n"
./convert inff
printf "\n"
./convert +inff
printf "\n"
./convert -inff
printf "\n"
./convert nanf
printf "\n"
./convert +nanf
printf "\n"
./convert -nanf
printf "\n"

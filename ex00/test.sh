#!/bin/zsh
printf '""\n'
./convert ""
printf "\nab\n"
./convert "ab"
printf "\n4.2.1\n"
./convert 4.2.1
printf '\n" "\n'

./convert ' '
printf "\na\n"
./convert a
printf "\n90\n"
./convert 90
printf "\n0\n"
./convert 0
printf "\ninf\n"

./convert inf
printf "\n+inf\n"
./convert +inf
printf "\n-inf\n"
./convert -inf
printf "\nnan\n"
./convert nan
printf "\n+nan\n"
./convert +nan
printf "\n-nan\n"
./convert -nan
printf "\ninff\n"
./convert inff
printf "\n+inff\n"
./convert +inff
printf "\n-inff\n"
./convert -inff
printf "\nnanf\n"
./convert nanf
printf "\n+nanf\n"
./convert +nanf
printf "\n-nanf\n"
./convert -nanf
printf "\n"

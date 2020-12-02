#!/bin/bash

echo -e "\e[96mMAKE:\e[0m"
make
echo
echo -e "\e[95mTESTS:\e[0m"
fichier="./tests/all_test"

nb_test=0
nb_crash=0
nb_yes=0
nb_no=0

echo -e "\e[95mCOMMAND TEST:\e[0m"

cat $fichier | (while read ligne ; do
    echo $ligne | ./42sh > tests/test1
    echo $ligne | tcsh > tests/test2
    diff tests/test1 tests/test2
    if [ $? -eq 0 ]; then
        let nb_yes=nb_yes+1
        echo -e "   \e[32m$ligne\e[0m"
    else
        let nb_no=nb_no+1
        echo -e "       \e[31m$ligne\e[0m"
    fi
    let nb_test=nb_test+1
done
echo
echo -e "\e[95mBILAN:\e[0m"
echo -e "NUMBER TEST =      $nb_test"
echo -e "\e[32mNUMBER SUCCESS =    $nb_yes\e[0m"
echo -e "\e[31mNUMBER ERROR =     $nb_no\e[0m"
echo -e "\e[33mNUMBER CRASH =     $nb_crash\e[0m"
)
rm -rf tests/test1 tests/test2

echo
echo -e "\e[96mMAKE FCLEAN:\e[0m"
make fclean

#!/bin/bash

gcd () # a, b
{
    if [[ $1 -eq 0 || $2 -eq 0 ]]
    then
        if [[ $1 -ge $2 ]]
        then
            echo "$1"
        else
            echo "$2"
        fi
    else
        let "new = $1 % $2"
        gcd $2 $new
    fi
}

while [[ true ]]
do
    read a b

    if [[ $a -eq "" || $b -eq "" ]]
    then
        echo "bye"
        exit
    fi

    result=`gcd $a $b`

    echo "GCD is $result"
done

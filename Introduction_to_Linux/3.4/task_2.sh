#!/bin/bash

while [[ true ]]
do
	read a exp b

	if [[ "$a" == "exit" ]]
	then
		echo "bye"
		exit
	fi

	if [[ $exp == "+" || $exp == "-" || $exp == "*" || $exp == "/" || $exp == "%" || $exp == "**" ]]
	then
		let "result=$a $exp $b"
		echo "$result"
	else
		echo "error"
		exit	
	fi
done

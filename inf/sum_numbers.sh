#!/bin/bash
if [ "$#" != "0" ]; then
	a=$1
	b=$2
	echo $((a+b))
else
	echo "Пожалуйста, укажите два числа"
fi

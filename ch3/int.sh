#!/bin/bash

N1=$1
N2=$2

echo -n "POSIX :: N1 "
if [ $N1 -eq $N2 ]; then
	echo -n "=="
elif [ $N1 -gt $N2 ]; then
	echo -n ">"
else
	echo -n "<"
fi
echo " N2"

echo -n "BASH :: N1 "
if (( $N1 == $N2 )); then
	echo -n "=="
elif (( $N1 > $N2 )); then
	echo -n ">"
else
	echo -n "<"
fi
echo " N2"

echo ""

echo -n "POSIX :: N1 "
if [ $N1 -ne $N2 ]; then
	echo -n "!="
else
	echo -n "=="
fi
echo " N2"

echo -n "BASH :: N1 "
if (( $N1 != $N2 )); then
	echo -n "!="
else
	echo -n "=="
fi
echo " N2"

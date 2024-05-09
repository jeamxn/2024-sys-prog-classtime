#!/bin/bash

if [ "$1" == "$2" ]; then
	echo "equal"
fi

if [ "$1" != "$2" ]; then
	echo "not equal"
fi

if [ "$1" \< "$2" ]; then
	echo "less than"
fi

if [ "$1" \> "$2" ]; then
	echo "greater than"
fi

if [[ "$1" == "$2" ]]; then
	echo "equal"
fi

if [[ "$1" != "$2" ]]; then
	echo "not equal"
fi

if [[ "$1" < "$2" ]]; then
	echo "less than"
fi

if [[ "$1" > "$2" ]]; then
	echo "greater than"
fi

if [ -z "$1" ]; then
	echo "null"
fi

if [ -n "$1" ]; then
	echo "not null"
fi

#!/bin/bash

if [ $# -ne 1 ]; then 
  echo "usage: $0 <year>"
  exit 1
fi

YEAR=$1

if [ $((YEAR % 400)) -eq 0 ]; then
  echo "$YEAR is a leap year"
elif [ $((YEAR % 100)) -eq 0 ]; then
  echo "$YEAR is not a leap year"
elif [ $((YEAR % 4)) -eq 0 ]; then
  echo "$YEAR is a leap year"
else
  echo "$YEAR is not a leap year"
fi

if [ $((YEAR % 4)) -eq 0 -a $((YEAR % 100)) -ne 0 -o $((YEAR % 400)) -eq 0 ]; then
  echo "$YEAR is a leap year"
else
  echo "$YEAR is not a leap year"
fi
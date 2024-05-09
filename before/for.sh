#!/bin/bash

# FOR
# fortest

if [ $# -eq 0 ]; then 
  echo "usage: $0 <arg1> <arg2> ... <argN>"
  exit 1
fi

echo "$@"
for arg in "$@"
do
  echo "$arg"
done

echo "$*"
#!/bin/bash

i=0

while [ $i -lt 10 ]
do
  echo "$i"
  ((i++))
  if [ $i -eq 5 ]; then
    break
  fi
done

i=0
until [ $i -eq 10 ]
do
  ((++i))
  if [ $i -eq 5 ]; then
    continue
  fi
  echo "$i"
done
#!/bin/bash

case $1 in
  apple | banana)
    echo "fruit";;
  tomato | cucumber)
    echo "vegetable";;
  *)
    echo "unknown";;
esac
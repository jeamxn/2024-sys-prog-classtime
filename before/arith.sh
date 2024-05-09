#!/bin/bash

A=5
echo "A is $A"

((A += 5))
echo "Now A is $A"

A=$((A += 5))
echo "Now A is $A"
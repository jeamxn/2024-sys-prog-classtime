#!/bin/bash

if [ -z $1 ]; then 
  echo "no input"; 
  exit 1;
fi

if [ -e $1 ]; then
  echo "file exists"
fi

if [ -f $1 ]; then
  echo "regular file"
fi

if [ -d $1 ]; then
  echo "directory"
fi

if [ -r $1 ]; then
  echo "readable"
fi

if [ -w $1 ]; then
  echo "writable"
fi

if [ -x $1 ]; then
  echo "executable"
fi

if [ -s $1 ]; then
  echo "size greater than zero"
fi

if [ -h $1 ]; then
  echo "symbolic link"
fi

if [ -p $1 ]; then
  echo "named pipe"
fi

if [ -S $1 ]; then
  echo "socket"
fi

if [ -L $1 ]; then
  echo "symbolic link"
fi

if [ -b $1 ]; then
  echo "block special file"
fi

if [ -c $1 ]; then
  echo "character special file"
fi

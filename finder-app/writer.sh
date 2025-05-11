#!/bin/bash


if [ $# -lt 2 ]; then
   echo "not enough arguments"
   exit 1
fi

mkdir -p "$(dirname "$1")" && touch "$1"
echo $2 > $1
 


#!/bin/bash


if [ $# -lt 2 ]; then
   echo "not enough arguments"
   exit 1
fi

if ! [[ -d $1 ]]; then
   echo "not a folder"
   exit 1
fi   
  
res=$(grep $2 -r --count --no-filename $1)
#echo $res

count=0
match_count=0
for item in $res
do
  if [ $item != "0" ]; then
      count=$((count+1))
      match_count=$((match_count+$item))
      #echo $count $match_count
  fi
done

echo "The number of files are $count and the number of matching lines are $match_count"




#!/bin/bash

SEARCH_STRING=$1
REPLACE_STRING=$2
PREVIEW_FLAG=$3

[[ -z $SEARCH_STRING ]] && echo -e "\e[44mEmpty arg SEARCH_STRING\e[0m" && exit 1
[[ -z $REPLACE_STRING ]] && echo -e "\e[44mEmpty arg REPLACE_STRING\e[0m" && exit 1

[[ $PREVIEW_FLAG != "preview" ]] && sed_arg="-i"


file_list=''

file_list=$(grep -RHIn --exclude-dir="external" --exclude-dir=".git" "$SEARCH_STRING" ./ | \
	grep -v "doxygen" | \
	grep -v ".git*" | \
	grep -v "CMakeLists.txt.user" | \
	awk '{print $1}' | \
	sed "s/:.*//g" | \
	uniq)

echo $file_list 

for file_name in $file_list; do
	echo -en "\e[43m$file_name\e[0m\n"
	sed $sed_arg "s/$SEARCH_STRING/$REPLACE_STRING/g" $file_name | grep $REPLACE_STRING
done

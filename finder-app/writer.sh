#!/bin/sh
# Writes a string to a file, creating the path if it does not exist.
# Usage: writer.sh <writefile> <writestr>
# Author: Sarkar22

if [ $# -lt 2 ]
then
	echo "Error: two arguments are required" >&2
	echo "Usage: $0 <writefile> <writestr>" >&2
	echo "	writefile: full path to a file (including filename)" >&2
	echo "	writestr:  text string to write to that file" >&2
	exit 1
fi

writefile=$1
writestr=$2
writedir=$(dirname "$writefile")

if ! mkdir -p "$writedir"
then
	echo "Error: could not create directory ${writedir}" >&2
	exit 1
fi

if ! echo "$writestr" > "$writefile"
then
	echo "Error: could not write to file ${writefile}" >&2
	exit 1
fi

exit 0

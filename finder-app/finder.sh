#!/bin/sh
# Counts files in a directory tree and lines within them matching a string.
# Usage: finder.sh <filesdir> <searchstr>
# Author: Sarkar22

if [ $# -lt 2 ]
then
	echo "Error: two arguments are required" >&2
	echo "Usage: $0 <filesdir> <searchstr>" >&2
	echo "	filesdir:  path to a directory on the filesystem" >&2
	echo "	searchstr: text string to search for within those files" >&2
	exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]
then
	echo "Error: ${filesdir} is not a directory on the filesystem" >&2
	exit 1
fi

numfiles=$(find "$filesdir" -type f | wc -l)
numlines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are ${numfiles} and the number of matching lines are ${numlines}"

exit 0

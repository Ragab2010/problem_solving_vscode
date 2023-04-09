#!/bin/bash

# Loop through all files in the current directory
for file in *
do
  # Check if the current file has no extension
  if [ "${file##*.}" != "cpp"  ] && [ "${file##*.}" != "sh"  ] &&&& [ "${file##*.}" != "json"  ]
  then
    # If it has no extension, remove it
    rm "$file"
    echo "Removed file: $file"
  fi
done

echo "Done."
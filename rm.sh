#!/bin/bash

shopt -s globstar
for file in **/*
do
  # Check if the current file has no extension
  if [ -f "$file" ] && [ "${file##*.}" != "cpp"  ] && [ "${file##*.}" != "c"  ]&& [ "${file##*.}" != "sh"  ] && [ "${file##*.}" != "json"  ]
  then
    # If it has no extension, remove it
    rm "$file"
    echo "Removed file: $file"
  fi
done

echo "Done."

#!/bin/bash
# Update the HTTP server directory (/var/cache/wbdehtml/)
# with new HTML files (../html/)
echo "NOTE: This will erase your old /var/cache/wbdehtml/ contents."
echo "Hit enter if you wish to proceed"
read
echo "Removing old HTML files..."
rm --recursive /var/cache/wbdehtml/*
echo "Copying new HTML files..."
mkdir /var/cache/wbdehtml
cp --recursive ./html/* /var/cache/wbdehtml/
echo "Finished."
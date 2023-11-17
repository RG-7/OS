#!/bin/bash
# This line specifies that the script should be interpreted using the Bash shell.

echo "Enter the filename: "
read file
# Prompt the user to enter the filename and read the input.

if [ -e "$file" ]; then
    # Check if the file exists.

    echo "File Information for $file:"
    echo "File Size: $(du -h "$file" | cut -f1)"
    echo "Permissions: $(ls -l "$file" | awk '{print $1}')"
    echo "Owner: $(ls -l "$file" | awk '{print $3}')"
    echo "Modification Time: $(stat -c "%y" "$file")"
else
    echo "File not found."
fi

# End of the script.
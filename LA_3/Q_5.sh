#!/bin/bash
# This line specifies that the script should be interpreted using the Bash shell.

echo "Enter the filename: "
read file
# Prompt the user to enter the filename and read the input.

if [ -f "$file" ]; then
    # Check if the file exists.

    echo "Contents of the file:"
    cat "$file"
    # Display the contents of the file.

    echo "Number of characters: $(wc -c < "$file")"
    echo "Number of words: $(wc -w < "$file")"
    echo "Number of lines: $(wc -l < "$file")"
    # Use the wc command to count characters, words, and lines in the file.
else
    echo "File not found."
fi

# End of the script.
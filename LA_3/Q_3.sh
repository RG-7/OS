#!/bin/bash
# This line specifies that the script should be interpreted using the Bash shell.

read n
# Read user input for the number of terms in the Fibonacci series.

a=0
b=1
# Initialize the first two terms of the Fibonacci series.

echo "The Fibonacci Series is "
echo "$a"
echo "$b"
# Print the first two terms of the series.

for (( i = 0; i < n; i++ )); do
    c=$(( $a + $b ))
    # Calculate the next term in the series.

    echo "$c"
    # Print the next term.

    a=$b
    b=$c
    # Update a and b for the next iteration.
done

# End of the script.
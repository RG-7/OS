#!/bin/bash
# This line specifies that the script should be interpreted using the Bash shell.

VAR1="Linuxize"
VAR2="Linuxize"
# Assign values "Linuxize" to variables VAR1 and VAR2.

if [ "$VAR1" = "$VAR2" ]; then
    # Check if VAR1 is equal to VAR2.
    echo "Strings are equal."
else
    echo "Strings are not equal."
fi

# End of the script.
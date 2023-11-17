#!/bin/bash
# This line specifies that the script should be interpreted using the Bash shell.

echo "Enter any character: "
read ch
# Prompt the user to enter a character and read the input.

case $ch in
    "a") echo "It is a vowel.";;
    "e") echo "It is a vowel.";;
    "i") echo "It is a vowel.";;
    "o") echo "It is a vowel.";;
    "u") echo "It is a vowel.";;
    *) echo "It is not a vowel.";;
esac
# Use a case statement to check the entered character against different cases (vowels).
# If the character matches a vowel, print "It is a vowel."
# If it doesn't match any vowel, print "It is not a vowel."

# End of the script.
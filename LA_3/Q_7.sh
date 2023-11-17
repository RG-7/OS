#!/bin/bash
# This line specifies that the script should be interpreted using the Bash shell.

# Display OS version
echo "OS Version:"
cat /etc/os-release

# Display CPU information
echo "CPU Information:"
lscpu

# Display memory information
echo "Memory Information:"
free -h

# Display disk usage
echo "Disk Usage:"
df -h

# Display network details
echo "Network Details:"
ip addr

# End of the script.
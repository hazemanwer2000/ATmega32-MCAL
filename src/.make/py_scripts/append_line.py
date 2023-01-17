#############################################################
# 
# Filename: append_line.py
# Description: Implemented as a command-line function, that appends
#               a line to a file
#                   
# Parameters [Implemented with flags]:
#   [1] -f DIR_PATH
#   [2] -l LINE
# Return:
#   [stdout]
#       None
#   [else] 
#       Appends a line to a file
# Author: Eng. Hazem Anwer
# Github: https://github.com/hazemanwer2000
# 
#############################################################

import sys
import os

# Get all arguments in a dictionary called 'args'
args = {}
for i in range(1, len(sys.argv), 2):
    args[sys.argv[i][1:]] = sys.argv[i+1]

# Append to file
with open(args['f'], 'a') as f:
    f.write(args['l'])
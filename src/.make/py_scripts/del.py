#############################################################
# 
# Filename: del.py
# Description: Implemented as a command-line function, that deletes
#                   each passed file
#                   
# Parameters:
#   [1] SPACE-SEPARATED LIST OF FILES
# Return:
#   [stdout]
#       None
#   [else] 
#       Deletes each passed file
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
for i in range(1, len(sys.argv)):
    if os.path.exists(sys.argv[i]):
        os.remove(sys.argv[i])
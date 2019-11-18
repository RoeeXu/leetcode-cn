#!/bin/bash
 
#####################################################
# Copyright (c) 2019 Roee Xu. All Rights Reserved
#####################################################
# File:    update.sh
# Author:  roeexu
# Date:    2019/11/14 11:13:35
# Brief:
#####################################################

git pull
TIME=`date +'%Y-%m-%d %H:%M:%S'`
git add *; git commit -m "$TIME"; git push

# vim: set expandtab ts=4 sw=4 sts=4 tw=100


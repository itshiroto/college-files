#!/bin/bash

rsync -auvh \
  --progress \
  --delete \
  --exclude='.git/' \
  --exclude='node_modules' \
  . /mnt/e/kuliah/Semester\ 2/Codes

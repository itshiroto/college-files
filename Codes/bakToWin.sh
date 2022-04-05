#!/bin/bash

rsync -auvh \
  --progress \
  --delete \
  --exclude='.git/' \
  . /mnt/e/kuliah/Semester\ 2/Codes

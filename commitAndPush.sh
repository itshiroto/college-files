#!/bin/bash

now=$(date +'%d/%m/%y')

git add .
git commit -m "Scripted backup on ${now}"
git push origin main

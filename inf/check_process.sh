#!/bin/bash
name=$1
pid=$(pgrep $name)
if [ -n "$pid" ]
then
echo "Процесс запущен"
else 
echo "Процесс не найден"
fi

#!/bin/bash
touch notes.txt
while read -r line;
echo "Введите exit на отдельной строке"
do

    # Разбиваем каждую строку на слова
    for word in $line; do
        if [ "$word" == "exit" ]; then
                break 2
        fi
    done
    echo $line >> notes.txt
done
cat notes.txt
rm notes.txt


#!/bin/bash
echo "creating subject folder..."
folder="submission"

mkdir -p "$folder"

if [ ! -d "philo/" ]; then
    echo "Error: Directory 'philo/' does not exist."
    exit 1
fi

if [ ! -d "philo_bonus/" ]; then
    echo "Error: Directory 'philo_bonus/' does not exist."
    exit 1
fi

cp -r philo/ "$folder"/ \
&& cp -r philo_bonus/ "$folder"/ \
&& cp Makefile "$folder"/

echo "done!"

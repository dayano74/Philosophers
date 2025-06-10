#!/bin/bash
echo "creating subject folder..."
folder="submission"

mkdir -p "$folder" \
&& cp -r philo/ "$folder"/ \
&& cp -r philo_bonus/ "$folder"/ \
&& cp Makefile "$folder"/

echo "done!"

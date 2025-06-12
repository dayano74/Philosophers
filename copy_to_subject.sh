#!/bin/bash
echo -n "Enter \"philo\": "
read input

mkdir -p $input \
&& cp -r src/ $input \
&& cp -r inc/ $input \
&& cp Makefile $input

echo "output done!"
#!/bin/bash

cd ../../../
docker rmi -f ereva/valgrind/string
docker build . -t ereva/valgrind/string -f materials/build/Valgrind/Dockerfile
docker run --rm ereva/valgrind/string

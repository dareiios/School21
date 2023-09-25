FROM ubuntu:22.04

RUN apt-get -y update; apt-get -y install valgrind; apt-get -y install check; apt-get -y install gcc; apt-get -y install make; mkdir -p /usr/src/

WORKDIR /usr/src/

COPY ./src /usr/src/
COPY ./materials/build/Valgrind/start.sh /usr/src

USER root

ENTRYPOINT ["/bin/bash", "start.sh"]


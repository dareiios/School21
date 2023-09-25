FROM nginx

USER root

WORKDIR /server/

COPY server.c /server/

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

RUN apt update && \
    apt-get install -y libfcgi-dev && \
    apt-get install -y spawn-fcgi && \
    apt-get install -y gcc 
    

ENTRYPOINT gcc server.c -lfcgi -o server && \
          spawn-fcgi -p 8080 ./server && \
             nginx -g 'daemon off;' 



# RUN nginx -s reload
# RUN -p 80:81 -d nginx

# docker run -d -p 80:81


#  docker build -t lala:4.0 .
# docker run -it -d -p  80:81 --name c1 lala:4.0 

# docker run -d -p 80:81 -v $(pwd) lll:2.0!!!!!!!!!!!!!!!!!!!!!!
# dockle lll:2.0     
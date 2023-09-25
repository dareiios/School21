FROM nginx

USER root

WORKDIR /server/

COPY server.c /server/

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf

RUN apt update && \
    apt-get install -y libfcgi-dev && \
    apt-get install -y spawn-fcgi && \
    apt-get install -y gcc && \
    gcc server.c -lfcgi -o server && \
    useradd Bob; \
    chown -R Bob:Bob /etc/nginx/nginx.conf; \
    chown -R Bob:Bob /var/cache/nginx; \
    chown -R Bob:Bob /home; \
    touch /var/run/nginx.pid; \
    chown -R Bob:Bob /var/run/nginx.pid; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /usr/bin/chfn; \
    chmod g-s /usr/bin/expiry; \
    chmod u-s /usr/bin/passwd; \
    chmod g-s /sbin/unix_chkpwd; \
    chmod g-s /usr/bin/chage; \
    chmod g-s /usr/bin/wall; \
    chmod u-s /bin/umount; \
    chmod u-s /bin/mount; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /bin/su; \
    chmod u-s /usr/bin/chsh; \
  rm -rf /var/lib/apt/lists 

USER Bob


HEALTHCHECK --interval=5m --timeout=3s \
  CMD curl -f http://localhost/ || exit 1 


ENTRYPOINT spawn-fcgi -p 8080 ./server && \
             nginx -g 'daemon off;' 



# RUN nginx -s reload
# RUN -p 80:81 -d nginx

# docker run -d -p 80:81


#  docker build -t lala:4.0 .
# docker run -it -d -p  80:81 --name c1 lala:4.0 

# docker run -d -p 80:81 -v $(pwd) lll:2.0!!!!!!!!!!!!!!!!!!!!!!
# dockle lll:2.0     
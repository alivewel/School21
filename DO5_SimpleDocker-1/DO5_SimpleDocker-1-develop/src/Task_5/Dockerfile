FROM nginx:latest
WORKDIR /home/
USER root
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./hello_world.c /home/hello_world.c
COPY ./run.sh /home/run.sh
RUN apt-get update; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    apt-get clean; \
    rm -rf /var/lib/apt/lists/*; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /var/cache/nginx; \
    chown -R nginx:nginx /home; \
    touch /var/run/nginx.pid; \
    chown -R nginx:nginx /var/run/nginx.pid; \
    chmod +x run.sh; \
    chmod u-s /usr/bin/passwd; \
    chmod u-s /usr/bin/newgrp; \
    chmod g-s /usr/bin/chage; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /bin/su; \
    chmod u-s /bin/mount; \
    chmod g-s /usr/bin/wall; \
    chmod u-s /usr/bin/chsh; \
    chmod g-s /usr/bin/expiry; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /bin/umount; \
    chmod g-s /sbin/unix_chkpwd;
USER nginx
HEALTHCHECK --interval=5m --timeout=3s CMD curl --fail http://localhost || exit 1
ENTRYPOINT ["sh", "./run.sh"]

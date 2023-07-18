FROM nginx:latest
WORKDIR /home/
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./hello_world.c /home/hello_world.c
COPY ./run.sh /home/run.sh
RUN apt-get update; \
    apt-get install -y gcc spawn-fcgi libfcgi-dev; \
    chmod +x run.sh
ENTRYPOINT ["./run.sh"]
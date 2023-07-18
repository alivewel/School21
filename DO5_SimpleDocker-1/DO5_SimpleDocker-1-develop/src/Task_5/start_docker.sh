#!/bin/bash
docker stop magicbox
docker rm magicbox
docker rmi box:fox

docker build . -t box:fox
docker run -d --name magicbox -p 80:81 -v /Users/alivewel/DO5_SimpleDocker-1/src/Task_5/nginx/nginx.conf/:/etc/nginx/nginx.conf/ box:fox
docker ps -a
docker logs magicbox
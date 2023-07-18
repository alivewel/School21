#!/bin/bash
gcc hello_world.c -lfcgi -o hello_world
spawn-fcgi -p 8080 ./hello_world
nginx -g "daemon off;"

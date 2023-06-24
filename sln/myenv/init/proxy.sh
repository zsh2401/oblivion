#!/usr/bin/env bash

PORT=7899
WIN_PORT=7890

export WINHOST=`grep nameserver /etc/resolv.conf | sed 's/nameserver //'`
echo 0.0.0.0 $PORT $WINHOST $WIN_PORT > /tmp/my_rinetd.conf
rinetd -c /tmp/my_rinetd.conf
export http_proxy="http://localhost:$PORT"
export https_proxy="https://localhost:$PORT"
export all_proxy="socks5://localhost:$PORT"

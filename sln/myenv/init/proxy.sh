#!/usr/bin/bash
URL=`grep nameserver /etc/resolv.conf | sed 's/nameserver //'`
export HTTP_PROXY="http://$URL:7890"
export HTTPS_PROXY="https://$URL:7890"
export all_proxy="socks5://$URL:7890"
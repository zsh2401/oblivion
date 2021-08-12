#!/usr/bin/bash
URL=`grep nameserver /etc/resolv.conf | sed 's/nameserver //'`
#export http_proxy="http://$URL:7890"
#export https_proxy="https://$URL:7890"
export all_proxy="socks5://$URL:7890"

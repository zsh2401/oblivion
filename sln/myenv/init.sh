#!/usr/bin/bash
#http://qiushao.net/2019/01/12/Linux/get-shell-script-dir/
BASE_PATH=$(dirname "$0")
INIT_DIR=$BASE_PATH/init

source $INIT_DIR/gui.sh
source $INIT_DIR/proxy.sh
source $INIT_DIR/alias.sh

source $INIT_DIR/hello.sh
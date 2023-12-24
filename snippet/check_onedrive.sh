#!/bin/bash

# 检查 OneDrive 进程是否存在
if ! pgrep -x "OneDrive" > /dev/null; then
    # 启动 OneDrive
    if [ $(pmset -g ps|sed -nE "s|.*'(.*) Power.*|\1|p") = "Battery" ]; then
        echo "电池电源，不尝试启动已死的OneDrive"
    else
        open -a "/Applications/OneDrive.app"
        echo "OneDrive is launched."
        echo ""
    fi
    
else
    echo "OneDrive 进程已经在运行"
fi


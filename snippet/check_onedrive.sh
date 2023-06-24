#!/bin/bash

# 检查 OneDrive 进程是否存在
if ! pgrep -x "OneDrive" > /dev/null; then
    # 启动 OneDrive
    open -a "/Applications/OneDrive.app"
    say "OneDrive is launched."
else
    echo "OneDrive 进程已经在运行"
fi


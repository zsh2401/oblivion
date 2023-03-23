import threading
import os
import time
import uuid
global a
a = 1


class MyTask(threading.Thread):
    def __init__(self, threadID, name, delay):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.delay = delay

    def run(self):
        # time.sleep(10)
        while(True):
            global a
            if(self.threadID is 0 and a > 1000):
                return
            a += 1
            # print(f"{self.threadID}, {a}")


cpu_count = os.cpu_count()

t: threading.Thread = None
for i in range(cpu_count):
    print("created")
    if t is None:
        t = MyTask(i, f"Thread-{i}", 1)
        t.start()
    else:
        MyTask(i, f"Thread-{i}", 1).start()

print("t1 join")
t.join()
print("t and main gone")
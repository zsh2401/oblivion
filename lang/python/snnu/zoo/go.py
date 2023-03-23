from time import sleep
from Scene import Scene
from Spirit import Spirit
from MasterChief import MasterChief


s = Scene()
for i in range(1000):
    s.addSpirit(MasterChief())

w = 1 / 128
while(s.tick()):
    sleep(w)
    pass
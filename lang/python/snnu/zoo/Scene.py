from math import floor
from time import time
from Spirit import Spirit


class Scene:
    __spirits: list[Spirit] = []
    __lastTick = -1

    def __init__(self) -> None:
        pass

    def __now(self) -> int:
        ms =  time() * 1_000
        return ms
    
    def tick(self) -> bool:
        now = self.__now()
        interval = floor(now - self.__lastTick if self.__lastTick is not -1 else 0)
        self.__lastTick = now
        for s in self.__spirits:
            s.tick(interval)
        return True

    def addSpirit(self, spirit: Spirit):
        print(spirit)
        self.__spirits.append(spirit)
        print(self.__spirits)
        pass

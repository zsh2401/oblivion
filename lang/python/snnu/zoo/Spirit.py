from abc import abstractmethod

class Spirit:
    def __init__(self) -> None:
        pass

    def tick(self, interval: int):
        raise NotImplementedError()

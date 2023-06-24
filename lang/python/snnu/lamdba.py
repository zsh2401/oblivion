from typing import Callable


def call(f: Callable[[list[any]], None], *args: list[any]):
    f(*args)
    pass


call(lambda *args: [print(i, "-", item)
     for i, item in enumerate(args)], "a", "q", "m")

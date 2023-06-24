# Di - 1 = 2 * (Di + 1)
def f(day: int, remain: int):
    today = remain
    total = remain
    for i in range(day, 0, -1):
        print(f"day {i} eat ${total}")
        yesterday = 2 * (today + 1)
        total += yesterday - today
        today = yesterday

    return total


print(f(10, 1))

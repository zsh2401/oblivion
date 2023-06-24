def f(type_a_price: int, type_b_price: int, type_c_price: int, balance: int):
    for i in range(0, balance // type_a_price + 1):
        a = balance - type_a_price * i
        for j in range(0, a // type_b_price + 1):
            b = a - type_a_price * j
            for k in range(0, b // type_c_price + 1):
                c = b - type_c_price * k
                # print(f"Checking ${i}/${j}/${k}")
                if c == 0:
                    print(f"Find a solution {i}/{j}/{k}")


# q = 10
# for i in range(q):
#     q -= 2
#     print(i)

f(5, 3, 1, 100)

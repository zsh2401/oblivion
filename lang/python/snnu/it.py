def q(n):
    for i in range(n):
        yield i

# q(100).
for i in q(100):
    if(i > 50):
        break
    print(i)

for i in q(30):
    print(i)

it = q(100)
while True:
    try:
        print(next(it))
    except StopIteration:
        print("done")
        break
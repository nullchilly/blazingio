import random

print("\n".join(
    "".join(random.choice("01") for _ in range(10000))
    for _ in range(5000)
))

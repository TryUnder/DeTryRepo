class vector:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __str__(self):
        return f"{self.a} {self.b}"

    def __neg__(self):
        self.a = -self.a
        self.b = -self.b

    def __add__(self, other):
        return vector(self.a + other.a, self.b + other.b)

    def __gt__(self, other):
        return self.a > other.a

v1 = vector(1, 2)
v2 = vector(3, 4)

#print(v1)

#v2 = -v1
#print(v1)

v3 = v1 + v2
print(v3)

v3 = v1 > v2
print(v3)
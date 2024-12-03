class Vector(object):

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def super_name(self):
        return super().__class__.__name__

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)
    
    def __repr__(self):
        return f'Vector({self.x}, {self.y})'
    
    def __mul__(self, other):
        return Vector(self.x * other.x, self.y * other.y)


v1 = Vector(1, 2)
v2 = Vector(2, 3)

v3 = v1 + v2
v4 = v1 - v2
v5 = v1 * v2
print(v3.x, v3.y)
print(v4.x, v4.y)
print(v5.x, v5.y)
print(v3)

print(v1.super_name())

# print(dir(v1))

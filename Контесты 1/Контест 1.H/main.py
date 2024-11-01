class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"{self.x} {self.y}"


my_list = []
amount = int(input())
for i in range(amount):
    input_coord = list(map(int, input().split()))
    my_list.append(Point(input_coord[0], input_coord[1]))
my_list = sorted(my_list, key=lambda point: (point.x ** 2 + point.y ** 2) ** 0.5)
for elem in my_list:
    print(elem)
import random


def quick_sort(arr, left, right):
    if left < right:
        l = left
        r = right
        val = arr[random.randint(left, right)]
        while l <= r:
            while arr[l] < val:
                l += 1
            while arr[r] > val:
                r -= 1
            if l <= r:
                arr[l], arr[r] = arr[r], arr[l]
                l += 1
                r -= 1
        if left < r:
            quick_sort(arr, left, r)
        if right > l:
            quick_sort(arr, l, right)


amount = int(input())
my_list = list(map(int, input().split()))
quick_sort(my_list, 0, len(my_list)-1)
for elem in my_list:
    print(elem, end=" ")
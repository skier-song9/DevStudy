from sys import stdin
input = stdin.readline
students = int(input())
classes = [input().split() for _ in range(students)]
class_num = [f'{i}' for i in range(1,10)]
same_std = [f'{i+1}' for i in range(students)]
for grade in range(5):
    cdict = dict(zip(class_num,[[] for _ in range(9)]))
    for std in range(students):
        cdict.get(classes[std][grade]).append(std+1)
    for cls in cdict:
        temp = cdict.get(cls)
        if len(temp)>1:
            for s in temp:
                for student in temp:
                    if str(student) not in same_std[s-1]:
                        same_std[s-1]+=str(student)
same_std.sort(key=lambda x:(-len(x),x[0]))
print(same_std[0][0])
# print(list(filter(lambda x:len(x) == max(same_std,key=len(same_std)),same_std))[0][0])
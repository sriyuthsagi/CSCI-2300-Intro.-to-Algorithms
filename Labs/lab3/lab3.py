

def mergesort(A):

    if (len(A) > 1):
        half = len(A)/2
        first = mergesort(A[0:half])
        second = mergesort(A[(len(A)/2)+1:len(A)-1])
        return merge(first, second)
    else:
        return A

def merge(A, B):
    if (len(A) == 0):
        return B;
    if (len(B) == 0):
        return A;

    if (A[0] <= B[0]):
        list = A[0]
        list.append(merge(A[1:len(A)-1], B))
        return list
    else:
        list = B[0]
        list.append(merge(B, B[1:len(B) - 1]))
        return list






A = [9, 14, 9, 5, 10, 6, 15, 6, 13, 9]

B = mergesort(A)

print(B)
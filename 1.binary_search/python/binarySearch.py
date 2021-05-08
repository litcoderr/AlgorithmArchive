def bs_(target, arr, i , j):
    if j <= i:
        if target == arr[i]:
            return i
        else:
            return -1
    else:
        mid = (i+j)//2
        
        if target == arr[mid]:
            return mid
        elif target < arr[mid]:
            return bs_(target, arr, i, mid-1)
        else:
            return bs_(target, arr, mid+1, j)

def bs(target, arr):
    index = bs_(target, arr, 0, len(arr)-1)

    return index
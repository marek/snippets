
# 
# most basic quick_sort.
# This example does not optimize memory. Lots of copies.
# 
def quick_sort(data):
  if not data: return data

  pivot = random.choice(data)
  front = quick_sort([item for item in data if item < pivot])
  back = quick_sort([item for item in data if item > pivot])
  match = [item for item in data if item == pivot]

  return front + match + back


# ----------------------------------------------------------------------------

def quicksort(array):
    qsort(array, 0, len(array)-1)

def qsort(A, lo, hi):
    if lo < hi:
        p = partition(A, lo, hi)
        qsort(A, lo, p)
        qsort(A, p + 1, hi)

def partition(A, lo, hi):
    pivot = A[lo]
    i, j = lo-1, hi+1
    while True:
      i += 1
      j -= 1
      while(A[i] < pivot): i+= 1
      while(A[j] > pivot ): j-= 1

      if i >= j: 
          return j

      A[i], A[j] = A[j], A[i]


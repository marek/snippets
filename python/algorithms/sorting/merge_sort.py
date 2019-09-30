
def split(data, start=None, end=None):
  if start is None:
    start = 0
  
  if end is None:
    end = len(data) - 1

  # always split down the middle
  index = start+(end-start)//2

  # return the two halves
  return data[start:index+1], data[index+1:end+1]


def merge_sort(data):
  if len(data) > 1:
    # recurse down into both halves at a pivot point
    # (this example assumes the middle)
    a, b = split(data)
    a, b = merge_sort(a), merge_sort(b)

    ita, itb = iter(a), iter(b)
    x, y = next(ita, None), next(itb, None)
    new_list = []

    while x != None or y != None:
      if x == None:
        # if x is null then append only items from y
        new_list.append(y)
        y = next(itb, None)
      elif y == None:
         # if y is null then append only items from x
        new_list.append(x)
        x = next(ita, None)
      elif x <= y:
        # if x is smaller than y append x
        new_list.append(x)
        x = next(ita, None)
      else:
        # if y is smaller than x append y
        new_list.append(y)
        y = next(itb, None)

    return new_list
  
  return data
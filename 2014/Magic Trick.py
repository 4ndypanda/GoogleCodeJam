def get_row():
  answer = int(raw_input())
  for i in xrange(1, 5):
    cur_row = raw_input();
    if i == answer:
      row = map(lambda x: int(x), cur_row.split())
  return row

def intersection(list_a, list_b):
  return set(list_a) & set(list_b)

def main():
  T = int(raw_input())
  for t in xrange(1, T + 1):
    first_row = get_row()
    second_row = get_row()
    common_cards = intersection(first_row, second_row)
    output = "Case #{0}: ".format(t)
    if len(common_cards) == 1:
      output += str(common_cards.pop())
    elif len(common_cards) == 0:
      output += "Volunteer cheated!"
    else:
      output += "Bad magician!"
    print output

if __name__ == "__main__":
  main()
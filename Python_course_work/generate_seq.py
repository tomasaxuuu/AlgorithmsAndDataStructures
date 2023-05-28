import random

def generate_nested_brackets_sequence(length):
    brackets = ['(', ')', '{', '}', '[', ']', '<', '>', '/', '\\']
    sequence = ''
    stack = []

    for _ in range(length):
        if not stack or random.choice([True, False]):
            opening_bracket = random.choice(brackets[::2])
            sequence += opening_bracket
            stack.append(opening_bracket)
        else:
            closing_bracket = brackets[brackets.index(stack[-1]) + 1]
            sequence += closing_bracket
            stack.pop()

    while stack:
        closing_bracket = brackets[brackets.index(stack[-1]) + 1]
        sequence += closing_bracket
        stack.pop()

    return sequence

def save_to_txt_file(sequence, filename):
    with open(filename, 'w') as f:
        f.write(sequence)

length = 45000
correct_nested_brackets_sequence = generate_nested_brackets_sequence(length)
print(correct_nested_brackets_sequence)

filename = "correct_nested_brackets_sequence.txt"
save_to_txt_file(correct_nested_brackets_sequence, filename)
print(f"Корректная последовательность скобок с вложенностью сохранена в файл {filename}")

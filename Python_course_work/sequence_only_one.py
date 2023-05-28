import time

def is_opening_bracket(c):
    return c in "({[</"


def is_closing_bracket(c):
    return c in ")}]>\\"


def is_matching_bracket(opening, closing):
    return (opening == '(' and closing == ')') or (opening == '{' and closing == '}') \
        or (opening == '[' and closing == ']') or (opening == '<' and closing == '>') \
        or (opening == '/' and closing == '\\')


def is_balanced(sequence):
    brackets = []
    bracket_type = '\0'
    for c in sequence:
        if is_opening_bracket(c):
            if bracket_type == '\0':
                bracket_type = c
            elif c != bracket_type:
                return False
            brackets.append(c)
        elif is_closing_bracket(c):
            if not brackets or not is_matching_bracket(brackets[-1], c):
                return False
            brackets.pop()

    return not brackets
def read_from_txt_file(filename):
    with open(filename, 'r') as f:
        return f.read()

if __name__ == "__main__":
    filename = "correct_nested_brackets_sequence.txt"
    sequence = read_from_txt_file(filename)
    print(f"Считанная последовательность: {sequence}")

    num_tests = 12

    for test in range(1, num_tests + 1):
        start_time = time.perf_counter()

        result = is_balanced(sequence)

        end_time = time.perf_counter()

        if result:
            print(f"Тест {test}: Последовательность корректна.")
        else:
            print(f"Тест {test}: Последовательность некорректна.")

        duration = (end_time - start_time) * 1_000_000  # миллисекунды

        print(f"Тест {test}: Время выполнения алгоритма: {duration} миллисекунд")

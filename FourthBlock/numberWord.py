dict = {}
with open('input.txt', 'r') as file:
	for words in file:
		for c in words.split():
			if c in dict:
				dict[c] += 1
			else:
				dict[c] = 0
			print(dict[c], end=' ')

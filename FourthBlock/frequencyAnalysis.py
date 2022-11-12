dict = {}
with open('input.txt', 'r') as file:

	for words in file:
		for c in words.split():
			if c in dict:
				dict[c] += 1
			else:
				dict[c] = 0

	for word in sorted(dict.items(), key=lambda item: (-item[1], item[0])):
		print(word[0], sep='\n')
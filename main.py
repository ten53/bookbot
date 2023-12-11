file = "books/frankenstein.txt"
with open(f"{file}") as f:
	file_contents = f.read()


def num_of_words(text):
	return f"{len(text.split())} words found in documents"


def num_of_char_in_word(text):
	char_count = {}
	for s in text:
		if s.lower() in char_count:
			char_count[s.lower()] += 1
		else:
			char_count[s.lower()] = 1
	return char_count


def convert_and_sort_alpha(dict):
	for key, value in sorted(dict.items()):
		if key.isalpha():
			print(f"The '{key}' character was found {value} times")


def report(file_path, text):
	print(f"--- Begin report of {file_path} ---")
	print(num_of_words(text))
	print("\n")
	convert_and_sort_alpha(num_of_char_in_word(text))
	print("\n")
	print("--- End report ---")


report(file, file_contents)

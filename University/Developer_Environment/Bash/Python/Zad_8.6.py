import sys

def wordCount(file_path):
    word_dict = {}
    with open(file_path, 'r') as f:
        for line in f:
            words = line.strip().split()
            for word in words:
                if word in word_dict:
                    word_dict[word] += 1
                else:
                    word_dict[word] = 1
    for word, count in word_dict.items():
        print(word, count)

wordCount(sys.argv[1])

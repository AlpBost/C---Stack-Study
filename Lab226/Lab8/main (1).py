from abc import ABC, abstractmethod


class absMethod(ABC):
    def __init__(self,address):
        self.address = address

    @abstractmethod
    def calculateFreqs(self):
        pass

class ListCount (absMethod):
    def calculateFreqs(self):
        with open(self.address,"r") as file:
            result = file.read().replace(" ","")
            list_result = []
            for x in result:
                if x not in list_result:
                    list_result.append(x)
            for i in range(0,len(list_result)):
                list_result[i] = list_result[i],"->", result.count(list_result[i])
                print(list_result[i])


class DictCount(absMethod):
    def calculateFreqs(self):
        with open(self.address, 'r') as file:
            result = file.read()
            letters = [char for char in result if char.isalpha()]
            dict = {}
            for letter in letters:
                dict[letter] = dict.get(letter, 0) + 1
            for letter in dict.keys():
                print(letter,"->",dict[letter])


print ("SET")
list_counter = ListCount("wierdword.txt")
list_counter.calculateFreqs();

print ("DICT")
dict_counter = DictCount("wierdword.txt")
letter_frequencies = dict_counter.calculateFreqs()


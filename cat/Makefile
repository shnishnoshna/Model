SHELL := /bin/bash
FLAGS = -Wall -Wextra -Werror -std=c11
FILE1 = 1.txt
FILE2 = 2.txt
FILE3 = 3.txt
FILE3 = 4.txt

all: clean s21_cat

s21_grep: s21_cat.c
	gcc $(FLAGS) s21_cat.c s21_cat

clean:
	rm -f s21_cat

rebuild: tests

tests:
	-diff <(./s21_cat $(FILE1)) <(cat $(FILE1))
	-diff <(./s21_cat $(FILE3)) <(cat $(FILE3))
	-diff <(./s21_cat -b $(FILE1)) <(cat -b $(FILE1))
	-diff <(./s21_cat -e $(FILE2)) <(cat -e $(FILE2))
	-diff <(./s21_cat -n $(FILE3)) <(cat -n $(FILE3))
	-diff <(./s21_cat -n $(FILE2)) <(cat -n $(FILE2))
	-diff <(./s21_cat -s $(FILE2)) <(cat -s $(FILE2))
	-diff <(./s21_cat -t $(FILE2)) <(cat -t $(FILE2))
	-diff <(./s21_cat -n $(FILE3)) <(cat -n $(FILE3))
	-diff <(./s21_cat -v $(FILE1)) <(cat -v $(FILE1))
	-diff <(./s21_cat -v $(FILE3)) <(cat -v $(FILE3))
	-diff <(./s21_cat --number-nonblank $(FILE3)) <(cat -b $(FILE3))
	-diff <(./s21_cat --number $(FILE3)) <(cat -n $(FILE3))
	-diff <(./s21_cat --squeeze-blank $(FILE3)) <(cat -s $(FILE3))
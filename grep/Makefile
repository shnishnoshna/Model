SHELL := /bin/bash
FLAGS = -Wall -Wextra -Werror -std=c11
FILE1 = 1.txt
FILE2 = 2.txt
FILE3 = 3.txt
REG = ty
REG2 = tY

all: clean s21_grep

s21_grep: s21_grep.o
	gcc $(FLAGS) s21_grep.o -o s21_grep

s21_grep.o: s21_grep.c
	gcc $(FLAGS) -c s21_grep.c

clean:
	rm -rf *o s21_grep

rebuild: tests

tests:
	-diff <(./s21_grep -i $(REG) $(FILE1) $(FILE2) $(FILE3)) <(grep -i $(REG) $(FILE1) $(FILE2) $(FILE3))
	-diff <(./s21_grep -v $(REG) $(FILE1) $(FILE2)) <(grep -v $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -v ty $(FILE1)) <(grep -v ty $(FILE1))
	-diff <(./s21_grep -v $(REG) $(FILE1) $(FILE2)) <(grep -v $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -c $(REG) $(FILE1)) <(grep -c $(REG) $(FILE1))
	-diff <(./s21_grep -c $(REG) $(FILE1) $(FILE2)) <(grep -c $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -l $(REG) $(FILE1) $(FILE2)) <(grep -l $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -l $(REG) $(FILE1)) <(grep -l $(REG) $(FILE1))
	-diff <(./s21_grep -n $(REG) $(FILE1)) <(grep -n $(REG) $(FILE1))
	-diff <(./s21_grep -n $(REG) $(FILE1) $(FILE2)) <(grep -n $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -o $(REG) $(FILE1)) <(grep -o $(REG) $(FILE1))
	-diff <(./s21_grep -o $(REG) $(FILE1) $(FILE2)) <(grep -o $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -h $(REG) $(FILE1)) <(grep -h $(REG) $(FILE1))
	-diff <(./s21_grep -h $(REG) $(FILE1) $(FILE2)) <(grep -h $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -f $(FILE1) $(FILE2) $(FILE3)) <(grep -f $(FILE1) $(FILE2) $(FILE3))
	-diff <(./s21_grep -f $(FILE1) $(FILE2)) <(grep -f $(FILE1) $(FILE2))
	-diff <(./s21_grep -in $(REG) $(FILE1)) <(grep -in $(REG) $(FILE1))
	-diff <(./s21_grep -in $(REG) $(FILE1) $(FILE2)) <(grep -in $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -in $(REG) $(FILE1) $(FILE2) $(FILE3)) <(grep -in $(REG) $(FILE1) $(FILE2) $(FILE3))
	-diff <(./s21_grep -cv $(REG) $(FILE1)) <(grep -cv $(REG) $(FILE1))
	-diff <(./s21_grep -cv $(REG) $(FILE1) $(FILE2)) <(grep -cv $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -iv $(REG) $(FILE1)) <(grep -iv $(REG) $(FILE1))
	-diff <(./s21_grep -iv $(REG) $(FILE1) $(FILE2)) <(grep -iv $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -lv $(REG) $(FILE1)) <(grep -lv $(REG) $(FILE1))
	-diff <(./s21_grep -lv $(REG) $(FILE1) $(FILE2)) <(grep -lv $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -lv $(REG) $(FILE1) $(FILE2) $(FILE3)) <(grep -lv $(REG) $(FILE1) $(FILE2) $(FILE3))
	-diff <(./s21_grep -ho $(REG) $(FILE1)) <(grep -ho $(REG) $(FILE1))
	-diff <(./s21_grep -ho $(REG) $(FILE1) $(FILE2)) <(grep -ho $(REG) $(FILE1) $(FILE2))
	-diff <(./s21_grep -nf $(FILE1) $(FILE2) $(FILE3)) <(grep -nf $(FILE1) $(FILE2) $(FILE3))
	-diff <(./s21_grep -nf $(FILE1) $(FILE2)) <(grep -nf $(FILE1) $(FILE2))
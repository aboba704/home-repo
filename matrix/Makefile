CC = gcc
CFLAGS = -Wall -Wextra -std=c11

OBJ_DIR = obj/src
OBJ_TESTS_DIR = obj/tests
EXECTUTABLE = test

# Исходные файлы
SRC = $(wildcard *.c)
SRC_TEST=$(wildcard tests/*.c)

# Объектные файлы
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, *.c)
OBJ_TEST = $(patsubst tests/%.c, $(OBJ_TESTS_DIR)/%.o, tests/*.c)

OS = $(shell uname)
ifeq ($(OS), Darwin)
	LDFLAGS = -lcheck -lpthread -lm 
else
	LDFLAGS = -lcheck -lsubunit -lrt -lpthread -lm
endif

# Основная цель
all: test

# Правило для создания объектных файлов
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TESTS_DIR)/%.o: tests/%.c | $(OBJ_TESTS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@	

# Создание директорий
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_TESTS_DIR):
	mkdir -p $(OBJ_TESTS_DIR)

rebuild_test: clean test

# Создание статической библиотеки
s21_matrix.a: $(OBJ)
	/usr/bin/ar rc $@ $^
	ranlib $@

# Очистка промежуточных файлов
clean:
	rm -rf $(EXECTUTABLE) $(OBJ_DIR) $(REPORT_DIR) *.gcda *.gcno *.info *.a *.h.gch tests/*.gcno report 

# Запуск тестов
test: s21_matrix.a
	$(CC) $(CFLAGS) -o $(EXECTUTABLE) $(SRC_TEST) s21_matrix.a $(LDFLAGS)
	./$(EXECTUTABLE)

gcov_report: s21_matrix.a
	$(CC) $(CFLAGS) --coverage $(SRC) $@ -L. $(LDFLAGS) -o $(EXECTUTABLE)
	./$(EXECTUTABLE) || true
	lcov -t "Report" -o coverage.info -c -d . --no-external
	genhtml coverage.info --output-directory report/
	open report/index.html
	rm *.gcda *.gcno

style:
	clang-format -n -style=Google *.c test/*.c
	clang-format -n -style=Google *.h test/*.h

set_style:
	clang-format -i -style=Google *.c test/*.c
	clang-format -i -style=Google *.h test/*.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

leaks:	
	valgrind --tool=memcheck --leak-check=full  --leak-check=full --show-leak-kinds=all ./$(EXECTUTABLE)

leaks_mac:
	leaks -atExit -- ./$(EXECTUTABLE) | grep LEAK:

.PHONY: all clean run test
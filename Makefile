CC = gcc
CFLAGS = -I src -Wall -Wextra
CPPFLAGS = -MMD
LDFLAGS =
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBSTAT = obj/libgeometry/libgeometry.a
# Сборка основной программы
all: bin/main

bin/main: $(OBJS) $(LIBSTAT)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBSTAT): $(OBJS)
	ar rcs $@ $^
# Компиляция объектных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<


# Запуск программы
go:
	bin/main
# Очистка объектных файлов
clean:
	rm -rf $(OBJ_DIR)/*/*.o
	rm -rf $(OBJ_DIR)/*/*.d
	rm -rf bin/main
	rm -rf $(OBJ_DIR)/*/*.a
	
.PHONY: all clean go
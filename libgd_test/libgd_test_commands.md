# Сборка статической библиотеки libgd

## Требования

Для сборки необходимы:

- CMake;
- GCC;
- Clang;
- Intel ICX;
- Intel oneAPI;
- исходный код libgd;
- включённые зависимости libpng.

---

Команды необходимо выполнять из корневого каталога проекта libgd, где находится файл `CMakeLists.txt`.

## Инициализация Intel oneAPI

Перед использованием компилятора ICX необходимо загрузить окружение Intel oneAPI:

```bash
source /opt/intel/oneapi/setvars.sh
```

Проверить доступность компиляторов можно командами:

```bash
gcc --version
clang --version
icx --version
```

## Параметры сборки

Для каждой конфигурации создаётся отдельный каталог:

- `build-gcc-O0`;
- `build-gcc-O2`;
- `build-gcc-Os`;
- `build-clang-O0`;
- `build-clang-O2`;
- `build-clang-Os`;
- `build-icx-O0`;
- `build-icx-O2`;
- `build-icx-Os`.

Используемые уровни оптимизации:

- `-O0` — без оптимизации;
- `-O2` — оптимизация производительности;
- `-Os` — оптимизация размера исполняемого кода.

Дополнительно используется флаг `-g` для добавления отладочной информации.

## Сборка с помощью GCC

### GCC `-O0`

```bash
cmake \
    -S . \
    -B build-gcc-O0 \
    -DCMAKE_C_COMPILER=gcc \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-O0 -g"

cmake \
    --build build-gcc-O0 \
    --target gd_static \
    --parallel
```

### GCC `-O2`

```bash
cmake \
    -S . \
    -B build-gcc-O2 \
    -DCMAKE_C_COMPILER=gcc \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-O2 -g"

cmake \
    --build build-gcc-O2 \
    --target gd_static \
    --parallel
```

### GCC `-Os`

```bash
cmake \
    -S . \
    -B build-gcc-Os \
    -DCMAKE_C_COMPILER=gcc \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-Os -g"

cmake \
    --build build-gcc-Os \
    --target gd_static \
    --parallel
```

## Сборка с помощью Clang

### Clang `-O0`

```bash
cmake \
    -S . \
    -B build-clang-O0 \
    -DCMAKE_C_COMPILER=clang \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-O0 -g"

cmake \
    --build build-clang-O0 \
    --target gd_static \
    --parallel
```

### Clang `-O2`

```bash
cmake \
    -S . \
    -B build-clang-O2 \
    -DCMAKE_C_COMPILER=clang \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-O2 -g"

cmake \
    --build build-clang-O2 \
    --target gd_static \
    --parallel
```

### Clang `-Os`

```bash
cmake \
    -S . \
    -B build-clang-Os \
    -DCMAKE_C_COMPILER=clang \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-Os -g"

cmake \
    --build build-clang-Os \
    --target gd_static \
    --parallel
```

## Сборка с помощью Intel ICX

Перед сборкой необходимо загрузить окружение Intel oneAPI:

```bash
source /opt/intel/oneapi/setvars.sh
```

### ICX `-O0`

```bash
cmake \
    -S . \
    -B build-icx-O0 \
    -DCMAKE_C_COMPILER=icx \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-O0 -g"

cmake \
    --build build-icx-O0 \
    --target gd_static \
    --parallel
```

### ICX `-O2`

```bash
cmake \
    -S . \
    -B build-icx-O2 \
    -DCMAKE_C_COMPILER=icx \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-O2 -g"

cmake \
    --build build-icx-O2 \
    --target gd_static \
    --parallel
```

### ICX `-Os`

```bash
cmake \
    -S . \
    -B build-icx-Os \
    -DCMAKE_C_COMPILER=icx \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DENABLE_CPP=OFF \
    -DENABLE_PNG=ON \
    -DCMAKE_C_FLAGS="-Os -g"

cmake \
    --build build-icx-Os \
    --target gd_static \
    --parallel
```

---
---
---
---
---

# Сборка и дизассемблирование libgd

## Требования

Необходимы:

- `gcc`;
- `clang`;
- `icx`;
- `objdump`;
- исходный файл `libgd_test.c`;
- предварительно собранные версии `libgd.a`;
- библиотеки `libm` и `libpng`.

## Подготовка окружения

Для использования Intel ICX загрузите окружение oneAPI:

```bash
source /opt/intel/oneapi/setvars.sh
```

Задайте пути к исходному файлу и библиотеке:

```bash
SOURCE_FILE="libgd_test.c"
LIBGD_ROOT="{PATH_LIBGD_PROJECT}"
```

`{PATH_LIBGD_PROJECT}` - требуется заменить на путь к папке с проектом libgd

Статическая библиотека `libgd.a` должна находиться в соответствующем каталоге:

```text
../../libgd-2.3.3/build-<компилятор>-<оптимизация>/Bin/libgd.a
```

Например:

```text
../../libgd-2.3.3/build-gcc-O2/Bin/libgd.a
../../libgd-2.3.3/build-clang-O2/Bin/libgd.a
../../libgd-2.3.3/build-icx-O2/Bin/libgd.a
```

## GCC

### GCC с оптимизацией O0

```bash
# Компиляция исходного файла в объектный файл.
# Оптимизация отключена, добавлена отладочная информация.
gcc -O0 -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_gcc_O0.o

# Линковка объектного файла со статической библиотекой libgd.
gcc -O0 -g \
    libgd_test_gcc_O0.o \
    "$LIBGD_ROOT/build-gcc-O0/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-gcc-O0

# Получение дизассемблированного кода.
objdump -D program-gcc-O0 \
    > program-gcc-O0.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-gcc-O0 \
    > program-gcc-O0-S.s
```

### GCC с оптимизацией O2

```bash
# Компиляция исходного файла с оптимизацией O2.
gcc -O2 -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_gcc_O2.o

# Линковка со статической библиотекой libgd.
gcc -O2 -g \
    libgd_test_gcc_O2.o \
    "$LIBGD_ROOT/build-gcc-O2/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-gcc-O2

# Получение дизассемблированного кода.
objdump -D program-gcc-O2 \
    > program-gcc-O2.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-gcc-O2 \
    > program-gcc-O2-S.s
```

### GCC с оптимизацией Os

```bash
# Компиляция с оптимизацией размера исполняемого файла.
gcc -Os -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_gcc_Os.o

# Линковка со статической библиотекой libgd.
gcc -Os -g \
    libgd_test_gcc_Os.o \
    "$LIBGD_ROOT/build-gcc-Os/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-gcc-Os

# Получение дизассемблированного кода.
objdump -D program-gcc-Os \
    > program-gcc-Os.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-gcc-Os \
    > program-gcc-Os-S.s
```

## Clang

### Clang с оптимизацией O0

```bash
# Компиляция исходного файла без оптимизации.
clang -O0 -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_clang_O0.o

# Линковка со статической библиотекой libgd.
clang -O0 -g \
    libgd_test_clang_O0.o \
    "$LIBGD_ROOT/build-clang-O0/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-clang-O0

# Получение дизассемблированного кода.
objdump -D program-clang-O0 \
    > program-clang-O0.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-clang-O0 \
    > program-clang-O0-S.s
```

### Clang с оптимизацией O2

```bash
# Компиляция исходного файла с оптимизацией O2.
clang -O2 -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_clang_O2.o

# Линковка со статической библиотекой libgd.
clang -O2 -g \
    libgd_test_clang_O2.o \
    "$LIBGD_ROOT/build-clang-O2/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-clang-O2

# Получение дизассемблированного кода.
objdump -D program-clang-O2 \
    > program-clang-O2.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-clang-O2 \
    > program-clang-O2-S.s
```

### Clang с оптимизацией Os

```bash
# Компиляция с оптимизацией размера исполняемого файла.
clang -Os -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_clang_Os.o

# Линковка со статической библиотекой libgd.
clang -Os -g \
    libgd_test_clang_Os.o \
    "$LIBGD_ROOT/build-clang-Os/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-clang-Os

# Получение дизассемблированного кода.
objdump -D program-clang-Os \
    > program-clang-Os.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-clang-Os \
    > program-clang-Os-S.s
```

## Intel ICX

### ICX с оптимизацией O0

```bash
# Компиляция исходного файла без оптимизации.
icx -O0 -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_icx_O0.o

# Линковка со статической библиотекой libgd.
icx -O0 -g \
    libgd_test_icx_O0.o \
    "$LIBGD_ROOT/build-icx-O0/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-icx-O0

# Получение дизассемблированного кода.
objdump -D program-icx-O0 \
    > program-icx-O0.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-icx-O0 \
    > program-icx-O0-S.s
```

### ICX с оптимизацией O2

```bash
# Компиляция исходного файла с оптимизацией O2.
icx -O2 -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_icx_O2.o

# Линковка со статической библиотекой libgd.
icx -O2 -g \
    libgd_test_icx_O2.o \
    "$LIBGD_ROOT/build-icx-O2/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-icx-O2

# Получение дизассемблированного кода.
objdump -D program-icx-O2 \
    > program-icx-O2.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-icx-O2 \
    > program-icx-O2-S.s
```

### ICX с оптимизацией Os

```bash
# Компиляция с оптимизацией размера исполняемого файла.
icx -Os -g \
    -c "$SOURCE_FILE" \
    -o libgd_test_icx_Os.o

# Линковка со статической библиотекой libgd.
icx -Os -g \
    libgd_test_icx_Os.o \
    "$LIBGD_ROOT/build-icx-Os/Bin/libgd.a" \
    -lm \
    -lpng \
    -o program-icx-Os

# Получение дизассемблированного кода.
objdump -D program-icx-Os \
    > program-icx-Os.s

# Получение дизассемблированного кода
# с включёнными строками исходного кода.
objdump -S -D program-icx-Os \
    > program-icx-Os-S.s
```

## Результаты

После выполнения команд будут созданы:

- объектные файлы `libgd_test_*.o`;
- исполняемые файлы `program-*`;
- дизассемблированные файлы `program-*.s`;
- дизассемблированные файлы с исходным кодом `program-*-S.s`.

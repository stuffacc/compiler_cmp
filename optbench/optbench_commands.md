# Команды компиляции программ на C и замер их размера/времени выполнения

## Инструменты

GNU size (GNU Binutils for Ubuntu) 2.42

stat (GNU coreutils) 9.4

hyperfine 1.18.0

## Компиляция в ассемблерный код

### GCC

```bash
gcc -O0 -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o gccO0.s
gcc -O2 -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o gccO2.s
gcc -Os -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o gccOs.s
```

### Clang
```bash

clang -O0 -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o clangO0.s
clang -O2 -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o clangO2.s
clang -Os -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o clangOs.s
```

### ICX

```bash
icx -O0 -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o icxO0.s
icx -O2 -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o icxO2.s
icx -Os -S -DNO\_ZERO\_DIVIDE=1 optbench.c -o icxOs.s
```

## Компиляция в машинный код

### GCC

```bash
gcc -O0 -DNO\_ZERO\_DIVIDE=1 optbench.c -o gccO0
gcc -O2 -DNO\_ZERO\_DIVIDE=1 optbench.c -o gccO2
gcc -Os -DNO\_ZERO\_DIVIDE=1 optbench.c -o gccOs
```

### Clang

```bash
clang -O0 -DNO\_ZERO\_DIVIDE=1 optbench.c -o clangO0
clang -O2 -DNO\_ZERO\_DIVIDE=1 optbench.c -o clangO2
clang -Os -DNO\_ZERO\_DIVIDE=1 optbench.c -o clangOs
```

### ICX

```bash
icx -O0 -DNO\_ZERO\_DIVIDE=1 optbench.c -o icxO0
icx -O2 -DNO\_ZERO\_DIVIDE=1 optbench.c -o icxO2
icx -Os -DNO\_ZERO\_DIVIDE=1 optbench.c -o icxOs
```


## Замер размера исполняемого файла по секциям

```bash
size gccO0 gccO2 gccOs
size clangO0 clangO2 clangOs
size icxO0 icxO2 icxOs
```

## Замер размера исполняемого файла

```bash
stat -c %s gccO0 gccO2 gccOs
stat -c %s clangO0 clangO2 clangOs
stat -c %s icxO0 icxO2 icxOs
```

## Замер времени исполнения

```bash
hyperfine ./gccO0 --warmup=100 --runs=1000
hyperfine ./gccO2 --warmup=100 --runs=1000
hyperfine ./gccOs --warmup=100 --runs=1000
```

```bash
hyperfine ./clangO0 --warmup=100 --runs=1000
hyperfine ./clangO2 --warmup=100 --runs=1000
hyperfine ./clangOs --warmup=100 --runs=1000
```

```bash
hyperfine ./icxO0 --warmup=100 --runs=1000
hyperfine ./icxO2 --warmup=100 --runs=1000
hyperfine ./icxOs --warmup=100 --runs=1000
```
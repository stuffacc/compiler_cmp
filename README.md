# «Сравнение и анализ оптимизаций компиляторов»

Исследование посвящено сравнению оптимизаций, выполняемых компиляторами языка C:

- GCC 13.3.0;
- Clang 18.1.3;
- Intel ICX 2026.0.0.

В качестве тестов использовались программа `optbench.c` и программа обработки изображений `libgd_test.c`, использующая библиотеку libgd версии 2.3.3 и функцию `gdImageGaussianBlur`.

## Структура проекта

- [libgd_test/](libgd_test/)
  - [asm/](libgd_test/asm/) - ассемблерные файлы теста `libgd_test.c` для разных компиляторов
  - [src/](libgd_test/src/)
    - [libgd_test.c](libgd_test/src/libgd_test.c)
  - [tables/](libgd_test/tables/) - таблицы сравнения теста `libgd_test.c`
  - [libgd_test_commands.md](libgd_test/libgd_test_commands.md) - используемые команды для `libgd_test.c`

- [optbench/](optbench/)
  - [asm/](optbench/asm/) - ассемблерные файлы теста `optbench.c` для разных компиляторов
  - [src/](optbench/src/)
    - [optbench.c](optbench/src/optbench.c)
  - [tables/](optbench/tables/) - таблицы сравнения теста `optbench.c`
  - [optbench_commands.md](optbench/optbench_commands.md) - используемые команды для `optbench.c`

- [compilers.csv](compilers.csv) - таблица с версиями компиляторов
- [README.md](README.md)
- [report.pdf](report.pdf) - отчёт
- [system.csv](system.csv) - таблица с информацией о системе

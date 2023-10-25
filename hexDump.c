/*
**  HEXDUMP.C - Dump a file.
**  HEXDUMP.C - Дамп файла.
**
**  This Program Written By Paul Edwards w/ modifications by Bob Stout
**  Эта Программа Написана Полом Эдвардсом с модификациями Боба Стаута
**  Released to the public domain
**  Передано в общественное достояние
**
** 04 Oct 2016 : Norman Dunbar : Amended to allow larger offsets to be printed.
** 04 Октября 2016 : Норман Данбар: Внесены поправки, позволяющие печатать большие смещения.
** 07 Dec 2016 : Norman Dunbar : Amended to allow hex values for start and count.
** 07 Декабря 2016 : Норман Данбар: Внесены поправки, позволяющие использовать шестнадцатеричные значения
** для начала и подсчета.
**
**                               Don't duplicate last line if address exact multiple of 16.
**                               Не дублируйте последнюю строку, если адрес точно кратен 16.
**                               USe fseek() instead of manually skipping to "start".
**                               Используйте fseek() вместо того, чтобы вручную переходить к "пуску".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static void dodump(FILE *fp, long start, long count);

int main(int argc, char **argv)
{
    FILE *fp;
    long start, count;
    char *dummy;

    if (argc < 2)
    {
        // We need at least a file name to dump!
        // Нам нужно хотя бы имя файла для дампа!

        puts("Usage:\tHEXDUMP file_name [start] [length]");
        puts("\tStart & length can be:");
        puts("\tDecimal (nnn) eg 1024,");
        puts("\tOctal (0nnn) eg 0500,");
        puts("\tHex (0xnnn) eg 0xCOFFEE");
        return (EXIT_FAILURE);
    }

    // Start address ...
    if (argc > 2)
        start = strtol(*(argv + 2), &dummy, 0);
    else  start = 0L;

    // Length ...
    if (argc > 3)
        count = strtol(*(argv + 3), &dummy, 0);
    else  count = -1L;


    fp = fopen(*(argv + 1), "rb");
    if (fp == NULL)
    {
        printf("unable to open file %s for input\n", *(argv+1));
        return (EXIT_FAILURE);
    }

    // Why not fseek() instead?
    // Почему бы вместо этого не использовать функцию fseek()?
    if (start)
        fseek(fp, start, SEEK_SET);

    //skipb(fp, start);
    dodump(fp, start, count);
    return (EXIT_SUCCESS);
}

static void dodump(FILE *fp, long start, long count)
{
    int c, pos1, pos2;
    long x = 0L;
    char prtln[100];

    while (((c = fgetc(fp)) != EOF) && (x != count))
    {
        if (x%16 == 0)
        {
            memset(prtln,' ',sizeof prtln);
            sprintf(prtln,"%0.8lX   ", start + x);

            // Pos1 = Where the first decoded byte's hex starts, after the address.
            // Pos1 = Где начинается шестнадцатеричный код первого декодированного байта после адреса.
            pos1 = 10;

            // Pos2 = Where the first ASCII character, or dot, goes.
            // Pos2 = Куда идет первый символ ASCII или точка.
            pos2 = 47;
        }

        // Add the 2 hex digits.
        // Добавляется 2 шестнадцатеричные цифры.
        sprintf(prtln + pos1, "%0.2X", c);

        // Add the ASCII chracter, or dot.
        // Добавляется символ ASCII или точка.
        if (isprint(c))
            sprintf(prtln + pos2, "%c", c);
        else
            sprintf(prtln + pos2, ".");
        pos1 += 2;

        *(prtln+pos1) = ' ';
        pos2++;

        // Add a space every 4 (source) bytes.
        // Добавьте пробел через каждые 4 (исходных) байта.
        if (x % 4 == 3)
            *(prtln + pos1++) = ' ';

        // Print the full line.
        if (x % 16 == 15)
            printf("%s\n", prtln);

        x++;
    }

    // Print the remaining bytes if we don't have a full line.
    // Выведите оставшиеся байты, если у нас нет полной строки.
    if (x % 16)
        printf("%s\n", prtln);

    return;
}

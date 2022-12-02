#include "../mesinkata.h"

int main()
{
    boolean loaded;

    for (int i = 0; i < 26; i++)
    {
        printf("Clearing...\n");
    }

    clear();

    STARTWORD("./data/config.txt", &loaded);
    while (!EndWord)
    {
        printWord(currentWord);
        printf("\n");
        ADVWORD();
    }

    printf("STARTCMD(true) = Menerima Spasi!\n");
    STARTCMD(true);
    while (!EndWord)
    {
        printWord(currentCommand);
        ADVCMD(true);
    }

    printf("\nSTARTCMD(false) = Menolak Spasi!\n");
    STARTCMD(false);
    while (!EndWord)
    {
        printWord(currentCommand);
        ADVCMD(false);
    }
    printf("\n");

    char someString[] = "IniInput!";
    printf("toWord!\n");
    Word converted = toWord(someString);
    printf("someString -> converted: ");
    printWord(converted);
    printf("\n");

    printf("toString!\n");
    printf("converted -> someString: ");
    printf("%s\n", toString(converted));

    converted.Length = 2;
    converted.TabChar[0] = '9';
    converted.TabChar[1] = '0';
    printf("Changed converted into 9\n");
    printf("isNumber(converted) = %d\n", isNumber(converted));
    printf("toInt(converted) = %d\n", toInt(converted));
    printf("strLength(\"90\") = %d\n", strLength("90"));

    printf("compareWord(converted, \"90\") : %d\n", compareWord(converted, "90"));

    printf("Created converted2 with body: 90\n");
    Word converted2;
    converted2.Length = 2;
    converted2.TabChar[0] = '9';
    converted2.TabChar[1] = '0';

    printf("compare2Word(converted, converted2) : %d\n", compare2Word(converted, converted2));

    printf("Created converted3 with body: AkuMakan_NasiKotak\n");
    Word converted3 = toWord("AkuMakan_NasiKotak");
    UPPER(&converted3);
    printf("UPPER(&converted3) = ");
    printWord(converted3);
    printf("\n");

    printf("Created converted4 & converted5 with body: *empty*\n");
    Word converted4, converted5;
    printf("binSep(converted3, &converted4, &converted5, '_')\n");
    binSep(converted3, &converted4, &converted5, '_');
    printf("converted4 = ");
    printWord(converted4);
    printf("\n");
    printf("converted5 = ");
    printWord(converted5);
    printf("\n");

    printf("Changed converted into 'v'\n");
    converted.Length = 1;
    converted.TabChar[0] = 'v';
    printf("compareCharWord(converted, 'v') = %d\n", compareCharWord(converted, 'v'));

    printf("\nstrcompare(\"abc\", \"ABC\") = %d\n", strcompare("abc", "ABC"));

    printf("wordcopy!\nconverted5 -> converted: ");
    wordCopy(&converted, converted5);
    printWord(converted);
    printf("\n\n");

    return 0;
}

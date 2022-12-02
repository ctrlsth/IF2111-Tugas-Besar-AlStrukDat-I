#include <stdio.h>
#include "../map.h"

int main()
{
    Map sussy;
    printf("CreateEmptyMap(&sussy)!\n");
    CreateEmptyMap(&sussy);
    printf("Sussy Map Count: %d\n\n", sussy.Count);
    
    printf("Sussy Empty? %d\n", IsMapEmpty(sussy));
    printf("Sussy Full? %d\n\n", IsMapFull(sussy));

    keytype color;
    color.TabChar[0] = 'R';
    color.TabChar[1] = 'E';
    color.TabChar[2] = 'D';
    color.Length = 3;

    keytype tobe;
    tobe.TabChar[0] = 'I';
    tobe.TabChar[1] = 'S';
    tobe.Length = 2;

    keytype sus;
    sus.TabChar[0] = 'S';
    sus.TabChar[1] = 'U';
    sus.TabChar[2] = 'S';
    sus.Length = 3;

    printf("MapValIns:\n");
    MapValIns(&sussy, color, 1);
    MapValIns(&sussy, tobe, 2);
    MapValIns(&sussy, sus, 3);

    int i;
    for (i = 0; i < sussy.Count; i++)
    {
        printf("sussy.Elements[%d]: \n", i);
        printf("Key: ");
        printWord(sussy.Elements[i].Key);
        printf("\n");
        printf("Value: %d", Value(sussy, sussy.Elements[i].Key));
        printf("\n\n");
    }
    
    printf("MapValDel:");
    MapValDel(&sussy, tobe);
    for (i = 0; i < sussy.Count; i++)
    {
        printf("sussy.Elements[%d]: \n", i);
        printf("Key: ");
        printWord(sussy.Elements[i].Key);
        printf("\n");
        printf("Value: %d", Value(sussy, sussy.Elements[i].Key));
        printf("\n\n");
    }

    printf("IsMapMember:\n");
    printf("Red IsSussyMember? %d\n\n", IsMapMember(sussy, color));

    ListOfMap TheImpostors;
    printf("CreateEmptyMapList(&TheImpostors)!\n");
    CreateEmptyMapList(&TheImpostors);
    printf("TheImpostors Num: %d\n\n", TheImpostors.Num);

    Map TheSkeld;
    printf("copyMap Sussy to TheSkeld!\n");
    CreateEmptyMap(&TheSkeld);
    copyMap(sussy, &TheSkeld);

    for (i = 0; i < TheSkeld.Count; i++)
    {
        printf("TheSkeld.Elements[%d]: \n", i);
        printf("Key: ");
        printWord(TheSkeld.Elements[i].Key);
        printf("\n");
        printf("Value: %d", Value(TheSkeld, TheSkeld.Elements[i].Key));
        printf("\n\n");
    }
    
    printf("SortByVal TheSkeld!\n");
    SortByVal(&TheSkeld);
    for (i = 0; i < TheSkeld.Count; i++)
    {
        printf("TheSkeld.Elements[%d]: \n", i);
        printf("Key: ");
        printWord(TheSkeld.Elements[i].Key);
        printf("\n");
        printf("Value: %d", Value(TheSkeld, TheSkeld.Elements[i].Key));
        printf("\n\n");
    }

    printf("Done!");

    return 0;
}

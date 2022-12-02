#include <stdio.h>
#include "../set.h"

int main()
{
    Set sussy;
    printf("CreateEmptySet(&sussy)!\n");
    CreateEmptySet(&sussy);
    printf("Sussy Set Count: %d\n\n", sussy.Count);
    
    printf("Sussy Empty? %d\n", IsSetEmpty(sussy));
    printf("Sussy Full? %d\n\n", IsSetFull(sussy));

    setinfo color;
    color.TabChar[0] = 'R';
    color.TabChar[1] = 'E';
    color.TabChar[2] = 'D';
    color.Length = 3;

    setinfo tobe;
    tobe.TabChar[0] = 'I';
    tobe.TabChar[1] = 'S';
    tobe.Length = 2;

    setinfo sus;
    sus.TabChar[0] = 'S';
    sus.TabChar[1] = 'U';
    sus.TabChar[2] = 'S';
    sus.Length = 3;

    printf("InsertSetEl:\n");
    InsertSetEl(&sussy, color);
    InsertSetEl(&sussy, tobe);
    InsertSetEl(&sussy, sus);

    int i;
    for (i = 0; i < sussy.Count; i++)
    {
        printf("sussy.PlayerName[%d]: ", i);
        printWord(sussy.PlayerName[i]);
        printf("\n");
    }
    printf("\n");
    
    printf("DeleteSetEl:");
    DeleteSetEl(&sussy, tobe);
    for (i = 0; i < sussy.Count; i++)
    {
        printf("sussy.PlayerName[%d]: ", i);
        printWord(sussy.PlayerName[i]);
        printf("\n");
    }
    printf("\n");

    printf("IsSetMember:\n");
    printf("Red IsSussyMember? %d\n\n", IsSetMember(sussy, color));

    ListOfSet TheImpostors;
    printf("CreateEmptySetList(&TheImpostors)!\n");
    CreateEmptySetList(&TheImpostors);
    printf("TheImpostors Num: %d\n\n", TheImpostors.Num);

    Map TheSkeld;
    printf("SortSetByMap(&sussy, TheSkeld)!\n");
    CreateEmptyMap(&TheSkeld);
    MapValIns(&TheSkeld, sus, 1);
    MapValIns(&TheSkeld, tobe, 2);
    MapValIns(&TheSkeld, color, 1);
    InsertSetEl(&sussy, tobe);

    printf("Sorted!\n");
    SortSetByMap(&sussy, TheSkeld);
    for (i = 0; i < sussy.Count; i++)
    {
        printf("sussy.PlayerName[%d]: ", i);
        printWord(sussy.PlayerName[i]);
        printf("\n");
    }
    printf("\n");

    printf("Done!");

    return 0;
}

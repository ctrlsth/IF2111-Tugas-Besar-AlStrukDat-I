#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ADT MESIN KARAKTER/mesin_kar.h"
#include "ADT ARRAY/array.h"
#include "boolean.h"

void codegenerator(TabInt* ListKode){
    if (IsEmpty(*ListKode)){
        (*ListKode).Neff = 1;
        (*ListKode).TI[1] = 'M0'+(*ListKode).Neff;
    } else if ((*ListKode).Neff<10){
        (*ListKode).Neff ++;
        (*ListKode).TI[(*ListKode).Neff] = 'M0'+(*ListKode).Neff;
    } else{
        (*ListKode).Neff ++;
        (*ListKode).TI[(*ListKode).Neff] = 'M'+(*ListKode).Neff;
    }
}
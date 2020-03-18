#ifndef __LISTEMOT__
#define __LISTEMOT__

typedef struct lst {
    char *mot;
    int occurence;
    struct lst *suivant;
} CelluleMot, *ListeMots;

#endif

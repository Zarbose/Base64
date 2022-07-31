#define TAILLE_MAX 1000

struct Value
{
    int index;
    char binary[7];
    char caract;
};
typedef struct Value Value;

int readFile(Value *table);
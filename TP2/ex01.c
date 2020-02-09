#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ret;
    char *portion;
    char *portion_ar;

    ret = strcmp("jeandidier", "georges");
    printf("%d \n", ret);
    ret = strcmp("a", "georges");
    printf("%d\n", ret);
    ret = strcmp("jeandidier", "jeandidier");
    printf("%d\n", ret);
    ret = strcmp("jeandidier", "");
    printf("%d\n", ret);
    
    portion = strchr("jeandidier", 'n');
    portion_ar = strrchr("jeandidier", 'n');
    printf("%s %s\n", portion, portion_ar);
    portion = strchr("jeandidier", 'e');
    portion_ar = strrchr("jeandidier", 'e');
    printf("%s %s\n", portion, portion_ar);
    portion = strchr("jeandidier", 'd');
    portion_ar = strrchr("jeandidier", 'd');
    printf("%s %s\n", portion, portion_ar);
    portion = strchr("jeandidier", 'z');
    portion_ar = strrchr("jeandidier", 'z');
    printf("%s %s\n", portion, portion_ar);

    ret = atoi("jeandi54dier");
    printf("%d \n", ret);
    ret = atoi("4jeandidier");
    printf("%d\n", ret);
    ret = atoi("-45georges");
    printf("%d\n", ret);
    ret = atoi("+34er");
    printf("%d\n", ret);
    ret = atoi("35-2");
    printf("%d\n", ret);

    return 0;
}

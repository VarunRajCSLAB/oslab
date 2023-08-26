/* Write a C program to simulate paging technique of memory management. */
#include <stdio.h>
#include <conio.h>

int main() {
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s[10], fno[10][20];

    clrscr();

    printf("Enter the memory size -- ");
    scanf("%d", &ms);

    printf("Enter the page size -- ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("The no. of pages available in memory are -- %d\n", nop);

    printf("Enter number of processes -- ");
    scanf("%d", &np);
    rempages = nop;

    for (i = 1; i <= np; i++) {
        printf("Enter no. of pages required for p[%d] -- ", i);
        scanf("%d", &s[i]);

        if (s[i] > rempages) {
            printf("Memory is Full\n");
            break;
        }

        rempages = rempages - s[i];

        printf("Enter pagetable for p[%d] --- ", i);
        for (j = 0; j < s[i]; j++)
            scanf("%d", &fno[i][j]);
    }

    printf("Enter Logical Address to find Physical Address\n");
    printf("Enter process no. and pagenumber and offset -- ");
    scanf("%d %d %d", &x, &y, &offset);

    if (x > np || y >= s[i] || offset >= ps)
        printf("Invalid Process or Page Number or offset\n");
    else {
        pa = fno[x][y] * ps + offset;
        printf("The Physical Address is -- %d\n", pa);
    }
    getch();
    return 0;
}

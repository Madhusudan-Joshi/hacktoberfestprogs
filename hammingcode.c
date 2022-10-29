#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[10], i, count = 0, datarec[10];

    printf("Sending data length is 4 bits\n");
    printf("Enter data bits one bye one from msb\n:");

    scanf("%d%d%d%d", &data[0], &data[1], &data[2], &data[4]);

    data[6] = data[4] ^ data[2] ^ data[0];
    data[5] = data[4] ^ data[1] ^ data[0];
    data[3] = data[2] ^ data[1] ^ data[0];

    printf("Encoded data: ");
    for (i = 0; i < 7; i++)
    {
        printf("%d", data[i]);
    }
    printf("\n To find 2 bit error parity bit is requiered\n");

    for (i = 0; i < 7; i++)
    {
        if (data[i] == 1)
            count++;
    }
    data[7] = count % 2;
    printf("\n Encoded data with parity bit: ");
    for (i = 0; i < 8; i++)
    {
        printf("%d", data[i]);
    }

    count = 0;
    printf("\nData sent");
    printf("\nEnter received data bit by bit from msb:");
    for (i = 0; i < 8; i++)
    {
        scanf("%d", &datarec[i]);
        if (datarec[i] == 1)
            count++;
    }
    int p;
    p = count % 2;
    int c, c1, c2, c3;
    c1 = datarec[6] ^ datarec[4] ^ datarec[2] ^ datarec[0];
    c2 = datarec[5] ^ datarec[4] ^ datarec[1] ^ datarec[0];
    c3 = datarec[3] ^ datarec[2] ^ datarec[1] ^ datarec[0];

    c = c3 * 4 + c2 * 2 + c1 * 1;

    if (c == 0)
    {
        if (p == 0)
        {
            printf("\nNo error");
        }
        else
        {
            printf("\nError in parity bit");
        }
    }
    else
    {
        if (p == 1)
        {
            printf("\nError in position %d", c);
        }
        else
        {
            printf("\n2 bit error cannot be fixed");
            return 0;
        }

        printf("\nSent data: ");
        for (i = 0; i < 7; i++)
        {
            printf("%d", data[i]);
        }
        printf("\nReceived data:");
        for (i = 0; i < 7; i++)
        {
            printf("%d", datarec[i]);
        }
        if (datarec[7 - c] == 0)
            datarec[7 - c] = 1;
        else
            datarec[7 - c] = 0;
        printf("\nCorrected data: ");
        for (i = 0; i < 7; i++)
        {
            printf("%d", datarec[i]);
        }
    }
    return 0;
}

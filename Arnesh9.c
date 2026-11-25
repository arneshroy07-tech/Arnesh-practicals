#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *sourceFile, *destFile;
    char sourceName[100], destName[100];
    int ch;

    printf("Enter the source filename to read from: ");
    scanf("%99s", sourceName);

    sourceFile = fopen(sourceName, "r");

    if (sourceFile == NULL)
    {
        printf("Error: Cannot open source file %s\n", sourceName);
        return 1;
    }

    printf("Enter the destination filename to write into: ");
    scanf("%99s", destName);

    destFile = fopen(destName, "w");

    if (destFile == NULL)
    {
        printf("Error: Cannot open destination file %s\n", destName);
        fclose(sourceFile);
        return 1;
    }

    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destFile);
    }

    printf("\nFile contents copied successfully from %s to %s!\n",
           sourceName, destName);

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}

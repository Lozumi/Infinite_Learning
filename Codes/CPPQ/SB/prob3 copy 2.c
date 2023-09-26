#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[20];
    char content[114];
} HTMLTag;

void parseHTML(char *html)
{
    HTMLTag tags[114];
    int numTags = 0;
    char *tagStart = NULL;
    char *tagEnd = NULL;
    char *contentStart = NULL;
    char *contentEnd = NULL;

    // 查找标签
    tagStart = strchr(html, '<');
    while (tagStart != NULL)
    {
        tagEnd = strchr(tagStart + 1, '>');
        if (tagEnd == NULL)
        {
            printf("格式错误\n");
            return;
        }
        contentStart = tagEnd + 1;

        // 跳过反向标签！
        if (tagStart[1] == '/')
        {
            tagStart = strchr(contentStart, '<');
            continue;
        }

        strncpy(tags[numTags].name, tagStart + 1, tagEnd - tagStart - 1);
        tags[numTags].name[tagEnd - tagStart - 1] = '\0';

        contentEnd = strstr(contentStart, "</");
        if (contentEnd == NULL)
        {
            printf("Invalid syntax");
            return;
        }

        strncpy(tags[numTags].content, contentStart, contentEnd - contentStart);
        tags[numTags].content[contentEnd - contentStart] = '\0';

        numTags++;

        tagStart = strchr(contentEnd, '<');
    }

    for (int i = 0; i < numTags; i++)
    {
        printf("%s\n", tags[i].name);
        printf("%s\n", tags[i].content);
    }
}

int main()
{
    char html[1000];
    fgets(html, sizeof(html), stdin);
    parseHTML(html);

    return 0;
}
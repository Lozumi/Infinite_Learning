#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HTML标签结构体
typedef struct
{
    char name[20];    // 标签名
    char content[20]; // 内容
} HTMLTag;

// 解析HTML字符串
void parseHTML(char *html)
{
    HTMLTag tags[100];
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
            break;
        }
        contentStart = tagEnd + 1;

        // 判断是否为反标签
        if (tagStart[1] == '/')
        {
            tagStart = strchr(contentStart, '<');
            continue;
        }

        // 提取标签
        strncpy(tags[numTags].name, tagStart + 1, tagEnd - tagStart - 1);
        tags[numTags].name[tagEnd - tagStart - 1] = '\0';

        // 提取内容
        contentEnd = strstr(contentStart, "</");
        if (contentEnd == NULL)
        {
            break;
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
    char html[500];
    fgets(html, sizeof(html), stdin);
    html[strcspn(html, "\n")] = '\0';

    parseHTML(html);

    return 0;
}
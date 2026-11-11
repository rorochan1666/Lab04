#include <stdio.h>
#include <string.h>
#include "get_line.h"
#include "essay.h"

#define MAXLEN 1000

const char ESSAY[] = "Ah Love! could you and I with Fate conspire \
To grasp this sorry Scheme of Things entire, \
Would not we shatter it to bits -- and then \
Re-mould it nearer to the Heart's Desire!";

int strindex(const char source[], char pattern[])
{
    int i, j;
    int len_s = 0, len_p = 0;

    /* 先量出两串的长度，后面算起点上限要用 */
    while (source[len_s] != '\0')
        len_s++;
    while (pattern[len_p] != '\0')
        len_p++;

    /* 空 pattern 没意义；pattern 比正文还长也不可能匹配 */
    if (len_p == 0 || len_p > len_s)
        return -1;

    /* 从最后一个可能的起点往回想：i 最大时 i + len_p 正好到串尾 */
    for (i = len_s - len_p; i >= 0; i--) {
        for (j = 0; j < len_p; j++) {
            if (source[i + j] != pattern[j])
                break;              /* 这个起点对不上，直接换下一个 */
        }
        if (j == len_p)             /* j 走完了整个 pattern，说明完全匹配 */
            return i;               /* 从后往前扫，第一次命中就是最右匹配 */
    }

    return -1;                      /* 所有起点都试过，未找到匹配 */
}


// DO NOT change the code below
#ifndef ___TEST___
int main(void)
{
    char pattern[MAXLEN] = "";

    printEssay(ESSAY);
    read_pattern_from_stdio( pattern, MAXLEN);
    int pos = strindex(ESSAY, pattern);
    printResult(ESSAY, pos);

    return 0;
}
#endif
// DO NOT change the code above

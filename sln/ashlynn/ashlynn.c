/**
 * Ashlynn 沟通器
 * 通过命令对ASCII码进行加密与解密
 * 涉及90%以上的C语言知识点，以及基础的数据结构知识
 * */

#define HELLP_MESSAGE ("Ashlynn 0.4-alpha\
使用说明\n\
加密：\n\t命令行参数方式： \t./ashlynn encode \"ZXY\"\n\
\t标准输入方式：\t\t./ashlynn encode\n\
解密：\n\t命令行参数方式：\t./ashylnn decode \"90 88 89\"\n\
\t标准输入方式：\t\t./ashlynn decode\n\
")

//均为C语言标准库，确保程序的跨平台性
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//一些硬编码的约定
#define TARGET_DECODE_FROM_STDIN (0x1031)
#define TARGET_ENCODE_FROM_STDIN (0x1125)
#define TARGET_DECODE_FROM_ARG (2001)
#define TARGET_ENCODE_FROM_ARG (1999)
#define TARGET_DISPLAY_HELP_MESSAGE (0)

//=======字符串链表部分========

/**
 * 字符串链表结点
 * */
typedef struct _CharNode
{
    /**
     * 上一个字符节点
     * */
    struct _CharNode *prev;

    /**
     * 结点数据
     * */
    char data;

} CharNode;

/**
 * 字符串链表本体
 * */
typedef struct _CharSequence
{
    /**
     * 长度
     * */
    size_t len;

    /**
     * 最后一个字符，没错，这个链表是倒置的
     * */
    CharNode *last;

} * CharSequence;

/**
 * 创建一个新的字符串链表
 * */
CharSequence newChars()
{
    CharSequence charSeq = (CharSequence)malloc(sizeof(CharSequence));
    charSeq->len = 0;
    charSeq->last = NULL;
    return charSeq;
}

/**
 * 释放一个字符串链表
 * */
void freeCharSeq(CharSequence charSeq)
{
    CharNode *prev = charSeq->last->prev;
    while (prev != NULL)
    {
        CharNode *current = prev;
        prev = prev->prev;
        free(current);
    }
    free(charSeq);
}
/**
 * 追加一个字符到字符串链表中
 * */
void append(CharSequence charSeq, char value)
{
    CharNode *newNode = (CharNode *)malloc(sizeof(CharNode));
    newNode->data = value;
    newNode->prev = charSeq->last;
    charSeq->last = newNode;
    charSeq->len++;
}

/**
 * 向字符串链表追加字符串
 * */
void appendStr(CharSequence chars, char *value)
{
    for (int32_t i = 0; value[i] != '\0'; i++)
    {
        append(chars, value[i]);
    }
}

/**
 * 将字符串链表转换为C语言标准字符串（字符数组）
 * */
char *toString(CharSequence charSeq)
{
    size_t strLen = (charSeq->len + 1);
    char *str = (char *)malloc(strLen * sizeof(char));
    CharNode *current = charSeq->last;
    for (int32_t i = charSeq->len - 1; i >= 0; i--)
    {
        str[i] = current->data;
        current = current->prev;
    }
    str[strLen - 1] = '\0';
    return str;
}

//=======字符串链表部分========

typedef int32_t target_t;

/**
 * 帮解析用户的操作，确定执行方案
 * */
target_t parseTarget(int argc, char **argv)
{
    if (argc <= 1)
    {
        return TARGET_DISPLAY_HELP_MESSAGE;
    }
    else
    {
        if (strcmp(argv[1], "encode") == 0)
        {
            if (argc >= 3)
            {
                return TARGET_ENCODE_FROM_ARG;
            }
            else
            {
                return TARGET_ENCODE_FROM_STDIN;
            }
        }
        else if (strcmp(argv[1], "decode") == 0)
        {
            if (argc >= 3)
            {
                return TARGET_DECODE_FROM_ARG;
            }
            else
            {
                return TARGET_DECODE_FROM_STDIN;
            }
        }
        else
        {
            return TARGET_DISPLAY_HELP_MESSAGE;
        }
    }
}

/**
 * 将密文进行解密
 * */
char *decode(char *encrypt)
{
    CharSequence chars = newChars();
    char *token = strtok(encrypt, " ");
    char *charBuffer = malloc(sizeof(char));
    while (token != NULL)
    {
        sprintf(charBuffer, "%c", atoi(token));
        token = strtok(NULL, " ");
        appendStr(chars, charBuffer);
    }
    return toString(chars);
}

/**
 * 将明文进行加密
*/
char *encode(char *plainText)
{
    CharSequence charSeq = newChars();
    char *word = strtok(plainText, " ");
    char *tmpBuffer = (char *)malloc(sizeof(char) * 3);
    size_t p = 0;
    while (word != NULL)
    {
        size_t wordLength = strlen(word);
        for (size_t j = 0; j < wordLength; j++)
        {
            memset(tmpBuffer, 0, sizeof(char) * 3);
            sprintf(tmpBuffer, "%d", word[j]);

            appendStr(charSeq, tmpBuffer);
            append(charSeq, '\x20');
        }
        word = strtok(NULL, " ");
        if (word != NULL)
        {
            appendStr(charSeq, "95\x20");
        }
    }
    char *result = toString(charSeq);
    freeCharSeq(charSeq);
    return result;
}

/*
* 从stdin读取标准输入
* */
char *readline()
{
    size_t capacity = 2401; /* initial value */
    char ch;
    CharSequence charSeq = newChars();
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        append(charSeq, ch);
    }
    char *result = toString(charSeq);
    freeCharSeq(charSeq);
    return result;
}

/**
 * 主函数
 * */
int main(int argc, char **argv, char **env)
{
    int32_t statusCode = 0;

    //根据命令行参数确定执行方式
    target_t target = parseTarget(argc, argv);

    //定义输入变量
    char *input = NULL;
    //定义输出变量
    char *output = NULL;

    switch (target)
    {

        //如果从标准输入编码
    case TARGET_ENCODE_FROM_STDIN:

        //从标准输入获得明文
        input = readline("");
        //加密
        output = encode(input);
        break;
        
        //如果从参数进行编码
    case TARGET_ENCODE_FROM_ARG:

        //从命令行参数获取明文
        input = argv[2] ;
        //加密
        output = encode(input);
        break;

    /*
    * 与上面类似的设计，不同的是使用decode函数进行解码
    */
    case TARGET_DECODE_FROM_STDIN:
        input = readline("");
        output = decode(input);
        break;
    case TARGET_DECODE_FROM_ARG:
        input = argv[2] ;
        output = decode(input);
        break;

    //不匹配任何目标，或用户要求显示帮助信息
    case TARGET_DISPLAY_HELP_MESSAGE:
    default:
        output = HELLP_MESSAGE;
        statusCode = 0;
        break;
    }

    //唯一使用printf的地方，确保了程序的稳定性
    printf("%s\n", output);

    //释放使用的内存
    // free(output);
    // if (target == TARGET_DECODE_FROM_STDIN || target == TARGET_ENCODE_FROM_STDIN)
    // {
    //     free(input);
    // }

    //退出程序
    return statusCode;
}
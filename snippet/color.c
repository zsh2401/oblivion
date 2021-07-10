/*
 * Created on Sat Apr 10 2021
 *
 * Copyright (c) 2021 Xiaoyu Zhang
 */

#include <stdio.h>

#define ALPHA 24 //定义Alpha值需要位移几位
#define RED 16 //定义红值需要位移几位
#define GREEN 8 //定义绿值需要位移几位
#define BLUE 0 //蓝色在最右边，不需要位移

typedef unsigned int color_t;     // 32位色
typedef unsigned char color256_t; // 每个部分有8位
typedef int colorpart_t; //你只应当使用上面的宏定义 ALPHA RED GREEN BLUE

/**
 * 
 * 根据传入的alpah，red，green，blue值构建一个颜色值
 * 
 * */
color_t createColor(color256_t a, color256_t r, color256_t g, color256_t b)
{
    color_t result = 0; //0x 00 00 00 00

    //设置alpha值
    result = result | a << ALPHA;
    //设置red值
    result = result | r << RED;
    //设置green值
    result = result | g << GREEN;
    //设置blue值
    result = result | b << BLUE;

    return result;
}

/**
 * 获取指定部分颜色值,如red部分，blue部分等。
 * 
 * 调用示例： getColorPart(someColor,BLUE)
 * 
 * */
color256_t getColorPart(color_t color, colorpart_t part)
{
    //掩码，用于屏蔽其它部分数据
    color_t mask = 0xff << part; 
    
    //通过掩码的与运算，屏蔽其它部分数据，然后将留下的数据进行位移并返回
    return (color & mask) >> part; 
}

/**
 * 设置一个颜色中的特定部分
 * 
 * 调用示例： getColorPart(someColor, 0xce, BLUE)
 * 
 * */
color_t setColorPart(color_t color, color256_t value, colorpart_t part)
{
    //创建掩码，用于将指定部分全部置0
    color_t mask = ~(0xff << part);

    //将指定部分全部置0
    color_t result = color & mask;

    //类似createColor的代码，将传入的值设置到颜色中
    return result | (value << part);
}

/**
 * 主函数
 * */
int main(int argc, char **argv)
{
    color_t black = createColor(0xff, 0xff, 0xff, 0xff); 
    printf("color(pure black) 0x%x\n", black);      //Should be 0xffffff

    color_t purered = createColor(0xff, 0xff, 0, 0);
    printf("color (pure red) 0x%x\n", purered);           // Should be 0xffff0000
    printf("blue of purered is 0x%x\n", getColorPart(purered, BLUE)); //Should be zero

    color_t redblue = setColorPart(purered, 0xce, BLUE);
    printf("red + blue is 0x%x\n", redblue); // Should be 0xff ff 00 ce
    printf("blue of (red+blue) is 0x%x\n", getColorPart(redblue, BLUE));//Should be 0xce
    return 0;
}
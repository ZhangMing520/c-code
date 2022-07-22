/**
 * @file enum.cpp
 * @author your name (you@domain.com)
 * @brief   枚举值位于其 enum class 的作用域之内。class关键字指明了枚举是强类型
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */
enum class Color
{
    red,
    blue,
    green
};

enum class Traffic_light
{
    green,
    yellow,
    red,
};

Color col = Color::red;
Traffic_light light = Traffic_light::red;

Traffic_light &operator++(Traffic_light &t)
{
    switch (t)
    {
    case Traffic_light::green:
        return t = Traffic_light::yellow;
    case Traffic_light::yellow:
        return t = Traffic_light::red;
    case Traffic_light::red:
        return t = Traffic_light::green;
    }
}

Traffic_light next = ++light;

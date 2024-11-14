// 不使用临时变量交换两个数

// 1.使用加减法(有时可能会溢出)
void swap1(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

// 2.使用位运算（异或）
void swpa1(int &a, int &b) {
    a = a ^ b;
    b = a ^ b; // 主要使用到这条x^x=0, x^0=x
    a = a ^ b;
}
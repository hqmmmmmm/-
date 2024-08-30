### getline
cin会自动处理输入流中的空白字符（包括空格、制表符和换行符），所以两次cin之间不需要cin.ignore。  
cin会自动忽略掉任何前导空白符，直到遇到第一个非空白字符，然后开始读取数值。一旦读取到数值，cin会继续读取，直到遇到下一个空白符，这时它会停止读取并将该空白符留在缓冲区中。

getline读到换行符后会将其从缓冲区中拿出。

```cpp
int main() {
    int n;
    cin >> n;       // 这里末尾还有个换行符在缓冲区中。
    cin.ignore();  // 使用cin.ignore()或getchar()把这个换行符读掉，否则会被getline读到。
    for(int i = 0; i < n; ++i)
    {
        std::string s;
        getline(cin, s);
        cout << s << endl;
    }


    return 0;
}
```
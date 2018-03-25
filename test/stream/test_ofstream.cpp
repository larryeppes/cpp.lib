//
// Created by PC on 2017/11/29.
//
#include <iomanip>
#include <fstream>

int test_ofstream() {
    std::ofstream of("D:\\me.txt"); // 写文件
// std::ofstream of("D:\\me.txt", std::ios::in);
//    文件打开方式选项：
//    　　　　ios::in　　　　= 0x01,　//供读，文件不存在则创建(ifstream默认的打开方式)
//    　　　　ios::out　　　 = 0x02,　//供写，文件不存在则创建，若文件已存在则清空原内容(ofstream默认的打开方式)
//    　　　　ios::ate　　　 = 0x04,　//文件打开时，指针在文件最后。可改变指针的位置，常和in、out联合使用
//    　　　　ios::app　　　 = 0x08,　//供写，文件不存在则创建，若文件已存在则在原文件内容后写入新的内容，指针位置总在最后
//    　　　　ios::trunc　　 = 0x10,　//在读写前先将文件长度截断为0（默认）
//    　　　　ios::nocreate　= 0x20,　//文件不存在时产生错误，常和in或app联合使用
//    　　　　ios::noreplace = 0x40,　//文件存在时产生错误，常和out联合使用
//    　　　　ios::binary　　= 0x80　 //二进制格式文件
//    文件保护方式选择项：
//    　　　　filebuf::openprot;　　　//默认的兼容共享方式
//    　　　　filebuf::sh_none;　　　 //独占，不共享
//    　　　　filebuf::sh_read;　　　 //读共享
//    　　　　filebuf::sh_write;　　　//写共享
//    打开文件的方法
//    　　　　调用构造函数时指定文件名和打开模式
//    　　　　ifstream f("d:\\12.txt",ios::nocreate);　　　　　　　　 //默认以 ios::in 的方式打开文件，文件不存在时操作失败
//    　　　　ofstream f("d:\\12.txt");　　　　　　　　　　　　　　　 //默认以 ios::out的方式打开文件
//    　　　　fstream　f("d:\\12.dat",ios::in|ios::out|ios::binary);　//以读写方式打开二进制文件
//    　　　　使用Open成员函数
//    　　　　fstream f;
//    　　　　f.open("d:\\12.txt",ios::out);　　　　　　　　　　　　　//利用同一对象对多个文件进行操作时要用到open函数
//    检查是否成功打开
//    　　成功：
//    　　　　if(f){...}　　　　　　　//对ifstream、ofstream对象可用，fstream对象不可用。
//    　　　　if(f.good()){...}
//    　　失败：
//    　　　　if(!f){...}　　　　　　 // !运算符已经重载
//    　　　　if(f.fail()){...}
//    读写操作
//    　　使用<<，>>运算符
//    　　只能进行文本文件的读写操作，用于二进制文件可能会产生错误。
//    　　使用函数成员 get、put、read、write等
//    　　经常和read配合使用的函数是gcount()，用来获得实际读取的字节数。
//    读写二进制文件注意事项
//    　　打开方式中必须指定ios::binary，否则读写会出错
//    　　用read\write进行读写操作，而不能使用插入、提取运算符进行操作，否则会出错。
//    　　使用eof()函数检测文件是否读结束，使用gcount()获得实际读取的字节数
//    关闭文件
//    　　使用成员函数close，如：
//    　　f.close();　
//    　　利用析构函数
//    　　对象生命期结束时会检查文件是否关闭，对没有关闭的文件进行关闭操作。
//    随机读写文件
//    　　通过移动文件读写指针，可在文件指定位置进行读写。
//    　　seekg(绝对位置);　　　　　　//绝对移动，　　　　//输入流操作
//    　　seekg(相对位置,参照位置);　 //相对操作
//    　　tellg();　　　　　　　　　　//返回当前指针位置
//    　　seekp(绝对位置);　　　　　　//绝对移动，　　　　//输出流操作
//    　　seekp(相对位置,参照位置);　 //相对操作　　　
//    　　tellp();　　　　　　　　　　//返回当前指针位置
//    　　参照位置：
//    　　ios::beg　　= 0　　　　　　 //相对于文件头
//    　　ios::cur　　= 1　　　　　　 //相对于当前位置
//    　　ios::end　　= 2　　　　　　 //相对于文件尾
    if(!of) {
        std::cout<<"file error!"<<std::endl;
        return -1;
    }
    of<<std::setw(20)<<"姓名: "<<"name"<<std::endl;
    of<<std::setw(20)<<"家庭地址: "<<"address"<<std::endl;
    of.close();
    std::cout<<"write file success!"<<std::endl;
    return 0;
}

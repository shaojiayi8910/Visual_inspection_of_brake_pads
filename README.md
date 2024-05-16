# Visual_inspection_of_brake_pads
主要使用opencv与wxwidgets来实现功能，代码最好在code::blocks中编写
Msys2安装Tesseract-OCR教程
打开MINGW64输入命令：
pacman -S mingw-w64-x86_64-leptonica mingw-w64-x86_64-libpng mingw-w64-x86_64-libjpeg-turbo
pacman -S mingw-w64-x86_64-tesseract-ocr
pacman -S mingw-w64-clang-x86_64-tesseract-data

到这里可以按下win+R输入cmd然后输入tesseract -v查看有没有安装成功

接着在MIGW64命令行窗口输入命令：
pkg-config --cflags tesseract
pkg-config --libs tesseract
会输出类似的代码：
-I/mingw64/include/leptonica
-L/mingw64/lib -ltesseract -larchive -lcurl

配置CB：
设置编译器和链接器路径
1.	打开Code::Blocks，选择 Settings > Compiler...。
2.	在“Selected compiler”中选择 GNU GCC Compiler。
3.	点击 Toolchain executables 标签，设置编译器路径为你自己的MSYS2的mingw-w64工具链路径

在setting>compiler> compiler setting>other compiler option输入：
`pkg-config --cflags tesseract`

在setting>compiler>linker libraries输入：tesseract和leptonica

在setting>compiler>search directories> compiler输入：
你的MSYS2中mingw64的include路径、include下tesseract、leptonica的路径；
在setting>compiler>search directories> linker输入：
你的MSYS2中mingw64的lib路径


最后添加环境变量：变量名：TESSDATA_PREFIX 变量值：* \mingw64\share\tessdata
*为msys2的安装路径

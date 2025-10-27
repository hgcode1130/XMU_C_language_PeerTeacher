# 💻 课堂代码 / Course Code

本目录包含历年 C/C++ 课程的完整课堂代码示例，按照上课日期组织。

## 📁 目录说明

```
course-code/
└── archive-original/    # 原始代码备份 (2024.10 - 2025.06)
    ├── 2024_10_9_course_1/
    ├── 2024_11_10_course_6/
    ├── 2024_12_18_course_12/
    ├── 2025_01_09_course_15/
    └── ...
```

## 📅 课程进度表

### 2024 年秋季学期

| 课程编号 | 日期 | 主要内容 | 目录 |
|---------|------|----------|------|
| Course 1 | 2024.10.09 | C语言基础、Hello World | `2024_10_9_course_1/` |
| Course 2-5 | 2024.10-11 | 基础语法、运算符、控制流 | `2024_10_*_course_*/` |
| Course 6-10 | 2024.11-12 | 函数、指针、数组 | `2024_11_*_course_*/` |
| Course 11-12 | 2024.12 | **链表操作**（重点） | `2024_12_*_course_*/` |
| Course 13 | 2024.12.24 | **高精度运算** | `2024_12_24_course_13/` |

### 2025 年春季学期

| 课程编号 | 日期 | 主要内容 | 目录 |
|---------|------|----------|------|
| Course 1 | 2025.02.27 | 复习基础语法 | `2025_2_27_course_1/` |
| Course 14+ | 2025.03-06 | 结构体、文件I/O、调试 | `2025_*_*_course*/` |

## 🎯 重点课程详解

### Course 11-12: 链表专题 🔗

**核心内容**：
- 单链表的创建与遍历
- 链表合并（归并）
- 链表反转（迭代/递归）
- 环形链表检测
- 回文链表判断

**推荐学习顺序**：
1. 先学习 `tutorials/c-basics/6.初识指针.txt`
2. 理解指针与结构体的结合使用
3. 查看课堂代码中的链表实现
4. 自己动手实现基本链表操作

**典型文件**：
- `2024_12_18_course_12/`中的链表相关代码

---

### Course 12: 文件操作 📂

**核心内容**：
- 文件打开/关闭（`fopen`, `fclose`）
- 文件读写（`fread`, `fwrite`, `fprintf`, `fscanf`）
- 文件定位（`fseek`, `ftell`, `rewind`）
- 二进制文件与文本文件

**常用模式**：
```c
FILE *fp = fopen("data.dat", "rb");
if (fp == NULL) {
    perror("文件打开失败");
    return -1;
}

fseek(fp, 0, SEEK_END);
long size = ftell(fp);
fseek(fp, 0, SEEK_SET);  // 或 rewind(fp)

char *buffer = (char*)malloc(size);
fread(buffer, 1, size, fp);

fclose(fp);
free(buffer);
```

---

### Course 13: 高精度运算 🔢

**项目说明**：
上机考试题目 - 实现超出基本数据类型范围的大数运算

**技术要点**：
- 使用数组存储大数的每一位
- 实现加法、减法、乘法
- 处理进位和借位

**学习价值**：
- 深入理解数组操作
- 锻炼算法设计能力
- 模拟计算机底层运算

---

### Course 14: 结构体与文件综合 📊

**核心内容**：
- 结构体定义与初始化
- 结构体数组
- 结构体与文件I/O结合
- 商品信息管理系统

**典型代码模式**：
```c
struct Goods {
    char item[30];
    double price;
    int count;
};

// 从文件读取结构体
FILE *fp = fopen("goods.dat", "rb");
struct Goods goods[100];
for (int i = 0; i < n; i++) {
    fread(&goods[i], sizeof(struct Goods), 1, fp);
}
fclose(fp);
```

---

## 📖 代码组织说明

### 文件命名规范

每个课程目录通常包含：
- 编号文件：`1.cpp`, `2.cpp`, ... - 按练习顺序编号
- 主题文件：`链表.cpp`, `reverse.cpp` - 按功能命名
- 项目文件：`*.sln`, `*.vcxproj` - Visual Studio 项目文件
- 说明文件：`README.md`, `answer.md` - 题目说明和答案

### 典型目录结构

```
2024_12_18_course_12/
├── 1.cpp                    # 练习1
├── 2.cpp                    # 练习2
├── merge_list.cpp           # 链表合并
├── reverse.cpp              # 链表反转
├── README.md                # 课程说明
├── answer.md                # 参考答案
├── *.sln                    # VS解决方案
└── Debug/Release/           # 编译输出
```

---

## 🛠️ 编译与运行

### Windows (Visual Studio)

```powershell
# 打开.sln文件
start project.sln

# 或使用MSBuild命令行编译
MSBuild.exe project.sln /p:Configuration=Release
```

### Windows (MSVC命令行)

```powershell
# 单文件编译
cl /EHsc program.cpp

# 多文件编译
cl /EHsc main.cpp module.cpp
```

### Windows (MinGW/GCC)

```powershell
# C文件
gcc program.c -o program.exe

# C++文件
g++ program.cpp -o program.exe
```

### Linux/Mac

```bash
# C文件
gcc program.c -o program

# C++文件
g++ program.cpp -o program
```

---

## 💡 学习建议

### 如何使用课堂代码

1. **跟随进度**：按照课程编号顺序学习
2. **动手实践**：不要只看代码，要自己敲一遍
3. **理解原理**：弄清楚每行代码的作用
4. **举一反三**：尝试修改代码，观察结果变化
5. **解决问题**：遇到编译错误要学会调试

### 代码风格注意事项

课堂代码的特点：
- ⚠️ 可能混用 C 和 C++ 语法（如 `#include <bits/stdc++.h>`）
- ⚠️ 包含中文注释（GBK 或 UTF-8 编码）
- ⚠️ 部分代码为竞赛风格（追求简洁而非最佳实践）
- ✅ 重点在于演示概念，而非生产级代码

### 常见问题排查

**编译错误**：
- 检查文件编码（中文注释可能导致问题）
- 确认编译器支持的 C/C++ 标准
- 检查 `#include` 路径

**运行错误**：
- 数组越界
- 指针未初始化
- 文件路径错误（Windows 路径需要转义 `\\`）
- 内存泄漏（未释放 `malloc`/`new` 的内存）

---

## 🔍 代码索引

### 按主题查找代码

| 主题 | 推荐课程 | 关键文件 |
|------|---------|---------|
| 基础语法 | Course 1-5 | `2024_10_*_course_*/` |
| 函数与递归 | Course 6-8 | `2024_11_*_course_*/` |
| 指针基础 | Course 7-9 | `2024_11_*_course_*/` |
| 链表操作 | Course 11-12 | `2024_12_18_course_12/` |
| 文件I/O | Course 12 | 包含 `fopen`, `fread` 的文件 |
| 高精度运算 | Course 13 | `2024_12_24_course_13/` |
| 结构体 | Course 14 | `2025_*_*_course14/` |

### 按难度查找代码

- **入门级** (⭐): Course 1-5 - 基础语法和控制流
- **初级** (⭐⭐): Course 6-10 - 函数、数组、基础指针
- **中级** (⭐⭐⭐): Course 11-13 - 链表、文件、算法
- **进阶** (⭐⭐⭐⭐): Course 14+ - 综合应用

---

## 📝 注意事项

1. **学术诚信**：代码仅供学习参考，不要直接用于作业
2. **版权声明**：课堂代码归厦门大学课程所有
3. **编码问题**：部分文件包含中文，注意字符编码
4. **平台差异**：Windows 路径使用 `\\`，Linux/Mac 使用 `/`

---

## 🤝 贡献

发现代码问题或有改进建议？
- 提交 [Issue](../../issues)
- 发起 [Pull Request](../../pulls)

---

<div align="center">

**编程是实践的艺术，多写多练！💪**

[返回主目录](../README.md)

</div>

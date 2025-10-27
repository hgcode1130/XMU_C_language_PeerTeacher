# XMU C/C++ 语言课程教学资料库

<div align="center">

[![License](https://img.shields.io/badge/license-Educational-blue.svg)](LICENSE)
[![Language](https://img.shields.io/badge/language-C%2FC%2B%2B-orange.svg)]()
[![University](https://img.shields.io/badge/university-厦门大学-red.svg)](https://www.xmu.edu.cn/)
[![Course](https://img.shields.io/badge/course-程序设计-green.svg)]()

**厦门大学 C/C++ 语言程序设计课程完整教学资源**

[📚 快速开始](#快速开始) • [🗂️ 目录结构](#目录结构) • [📖 学习路径](#学习路径) • [🤝 贡献指南](#贡献指南)

</div>

---

## 📝 简介

这是厦门大学 C/C++ 语言程序设计课程的完整教学资料库，包含：

- 📖 **系统化教程**：从基础到进阶的完整教学文档
- 💻 **课堂代码**：历年课程的完整代码示例
- 📝 **考试资料**：历年期中期末试题及详细解答
- 🎮 **实践项目**：三子棋、扫雷等完整游戏项目
- 📊 **课件资源**：配套 PPT 课件和学习笔记

无论您是初学者、助教还是教师，这里的资源都能为您的学习和教学提供全面支持。

## 🚀 快速开始

### 适用人群

| 角色 | 推荐资源 | 使用方式 |
|------|----------|----------|
| 👶 **C语言初学者** | `tutorials/` + `course-code/` | 按照[学习路径](#学习路径)逐步学习 |
| 🎓 **备考学生** | `exams/` + `tutorials/` | 刷历年真题，查漏补缺 |
| 👨‍🏫 **助教/教师** | 全部资料 | 参考教学设计和作业设计 |
| 👨‍💻 **进阶学习者** | `cpp-materials/` + `tutorials/projects/` | 深入学习C++和项目实战 |

### 克隆仓库

```bash
git clone https://github.com/YOUR_USERNAME/XMU_C_language_PeerTeacher.git
cd XMU_C_language_PeerTeacher
```

### 目录说明

查看各目录的 README.md 文件获取详细信息：

- [📖 tutorials/README.md](tutorials/README.md) - 教学资料使用指南
- [💻 course-code/README.md](course-code/README.md) - 课堂代码组织说明
- [📝 exams/README.md](exams/README.md) - 考试资料导航（包含C/C++）
- [📚 docs/learning-path.md](docs/learning-path.md) - 系统化学习路径

---

## 🗂️ 目录结构

```
XMU_C_language_PeerTeacher/
├── 📖 tutorials/              # 教学资料
│   ├── c-basics/            # C语言基础教程 (8个主题)
│   ├── slides/              # 课件
│   │   ├── beginner/        # C语言初阶课件
│   │   ├── advanced/        # C语言进阶课件
│   │   └── cpp/             # C++课件
│   ├── projects/            # 实践项目 (三子棋 + 扫雷)
│   └── reference/           # 参考文档 (C++速成等)
├── 💻 course-code/          # 课堂代码
│   └── archive-original/    # 原始代码备份 (2024-2025)
├── 📝 exams/                # 考试资料
│   ├── c-language/          # C语言试卷 (2012-2024)
│   │   ├── midterm/         # 期中试题
│   │   └── final/           # 期末试题
│   └── cpp/                 # C++试卷和复习资料
│       ├── midterm/         # 期中试题和复习资料
│       └── final/           # 期末试题和复习资料
└── 📚 docs/                 # 文档资料
    └── learning-path.md     # 学习路径
```

### 📖 tutorials/ - 教学资料

**C语言基础教程** (`c-basics/`)：8个主题系统学习

1. C语言概览 - 语言特性和第一个程序
2. 操作符 - 运算符及优先级
3. 分支和循环 - 控制流结构
4. 函数 - 函数设计与递归
5. 数组 - 数组与字符串
6. 初识指针 - 指针基础
7. 初识结构体 - 结构体定义和使用
8. 实用调试技巧 - 调试方法

**课件资源** (`slides/`)
- `beginner/` - C语言初阶课件 PPT
- `advanced/` - C语言进阶课件 PPT
- `cpp/` - C++课件和示例代码

**实践项目** (`projects/`)
- `tic-tac-toe/` - 三子棋游戏完整实现
- `minesweeper/` - 扫雷游戏完整实现

**参考文档** (`reference/`)
- C++速成指南等快速入门文档

### 💻 course-code/ - 课堂代码

历年课程的完整代码示例，按日期组织：
- 2024年 10月 - 2025年 6月的课堂代码
- 涵盖基础语法、指针、链表、文件操作等

### 📝 exams/ - 考试资料

**C语言试卷** (`c-language/`)
- 期中: 2019, 2020, 2024 年试题及答案
- 期末: 2012-2019 年试题，部分含详细解答

**C++试卷** (`cpp/`)
- `midterm/` - 期中试题和复习资料
- `final/` - 期末试题和复习资料（包含大量模拟题和历年真题）

## 📖 学习路径

### 👶 初学者路径（零基础）

| 阶段 | 时间 | 学习内容 | 资源 |
|------|------|----------|------|
| 第 1-2 周 | 8-12h | C语言概览、基本语法 | `tutorials/c-basics/1-2` |
| 第 3-4 周 | 10-15h | 分支与循环 | `tutorials/c-basics/3` + `course-code/` |
| 第 5-6 周 | 12-18h | 函数与数组 | `tutorials/c-basics/4-5` |
| 第 7-8 周 | 15-20h | 指针基础 | `tutorials/c-basics/6` |
| 第 9-10 周 | 10-15h | 结构体与调试 | `tutorials/c-basics/7-8` |
| 第 11-12 周 | 20h+ | 实践项目 | `tutorials/projects/` |

**学习建议**：
1. 每学完一个主题后，编写相应的小程序
2. 参考 `course-code/` 中的课堂示例加深理解
3. 完成每个章节后的练习题
4. 尝试修改和扩展项目代码

### 🎓 考前复习路径

**期中考试准备**（覆盖前 8 周内容）

1. **基础复习** (2-3 天)
   - 复习 `tutorials/c-basics/1-4`
   - 重点：操作符优先级、循环嵌套、函数参数传递

2. **刷题阶段** (3-4 天)
   - 完成 `exams/c-language/midterm/` 中所有试题
   - 总结错误类型，查漏补缺

3. **模拟考试** (1-2 天)
   - 限时完成一套完整试卷
   -对照答案进行评分

**期末考试准备**（完整课程）

1. **系统复习** (5-7 天) - 复习所有 `tutorials/c-basics/`
2. **重点攻克** (4-5 天) - 指针、数组、结构体、文件操作
3. **刷题阶段** (5-6 天) - 完成 `exams/c-language/final/` 所有试题
4. **综合模拟** (2-3 天) - 每天一套完整试卷

### 👨‍💻 进阶学习路径（C++）

1. **C++ 基础** - 学习 `cpp-materials/reference/C++速成.md`
2. **面向对象** - 类与对象、继承与多态
3. **STL 容器** - vector、list、map 等常用容器
4. **考试准备** - 完成 `cpp-materials/review/` 中的模拟题

---

## 🤝 贡献指南

我们欢迎并感谢任何形式的贡献！

### 如何贡献

1. **报告问题**：发现错误或有建议？请创建 [Issue](../../issues)
2. **添加内容**：有新的学习资料？欢迎提交 Pull Request
3. **完善文档**：帮助改进 README 和教程说明
4. **分享经验**：分享你的学习心得和项目实践

详细贡献指南请查看 [CONTRIBUTING.md](CONTRIBUTING.md)

### 贡献者

感谢所有为本项目做出贡献的学长和同学！

---

## ℹ️ 注意事项

- 📚 **学术诚信**：请将试题资料用于学习参考，而非直接拄贝答案
- 🛠️ **开发环境**：Windows + Visual Studio，但代码可移植
- 🔤 **编码格式**：部分文件含中文注释，GBK/UTF-8 编码
- ⚖️ **许可声明**：本仓库仅供教学参考，不用于商业目的

---

## 🔗 相关链接

- [厦门大学官网](https://www.xmu.edu.cn/)
- [C 语言在线文档](https://zh.cppreference.com/w/c)
- [C++ 在线文档](https://zh.cppreference.com/w/cpp)

---

<div align="center">

**如果这个仓库对你有帮助，请给个 ⭐ Star ！**

Made with ❤️ by XMU Students

</div>

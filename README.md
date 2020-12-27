### 这是什么？

Template-Generator 是一个 lyc 瞎写的，用于快速生成 HTML 格式的模板的开源项目。

[Demo](<https://lycltb.github.io/homepage/source/Templates.html>)

### 如何使用？

在文件夹下新建文件夹 `code`

把你的模板放进这个文件夹，文件名需要保证是英文。

运行 `main.exe`

如果你不太理解，可以[下载 release](<https://github.com/lycLTb/ACM-Template-Generator/releases/download/V1.0/ACM-Template-Generator-Release.zip>)来观察一个实例。（Release 中的 `main.cpp` 不一定是最新的

### Features

- 支持代码高亮
- 索引目录
- 一键复制
- 所有代码集成在一个 HTML 文件内

### 关于自定义代码高亮

前往 [Prism.js](https://prismjs.com/) 官网下载对应主题的 `css` 和 `js` 文件，并用它们替换 `/source/` 中的 `prism.js` 和 `prism.css`

### 致谢

复制代码功能使用了 [给 LibreOJ 添加复制按钮的用户脚本](<https://github.com/woshiluo/syzoj-copy-button>) 的代码

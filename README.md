## github

### 查询技巧

- awesome 有趣的
- tutorial 书籍文档
- sample样例

### 三要素

- 仓库

	- 是项目管理存储的基本单元，可包含多个分支
	- 一个仓库一般只会保留一个项目

- 提交

	- 目的是备份对代码的修改，便于回溯，使用者可以观察整个工程的开发设计流程
	- 绿色是新增加的，红色是删除的，白色是保留的

- 分支

	- 是真正的代码存储单元
	- 默认主分支是mater main
	- 既可以管理代码存储，又便于协作开发

### 仓库内容

- code

	- 资源存储、代码资源、二进制、许可证等

- issurs

	- 一些问题的提问与回答

- README.md

	- 开发者说明文档，是使用markdown语言编写的的工程自述文件、开发进度等

- LICENSE

	- 许可证，最大使用限制的有：GPL2.0、GPL3.0、Apachce2.0、Mit

## Git

### 设备认证

- 创建本地仓库

	- 命令：
	```C
	git init
	
	```
	- 属于隐藏文件，使用ls -a查看

[![image.png](https://i.postimg.cc/K8XNMtq4/image.png)](https://postimg.cc/fJKm4Shh)

- 绑定设备与账户

	- 查看配置文件：
	```c
	git config --list
	
	```
	- 设置用户邮箱：
	```c
	git config --global user.email "your email":
	```

	- 设置用户名字：
	```c
	git config --global user.name "your name"
	```
[![2.png](https://i.postimg.cc/qRvr0JRD/2.png)](https://postimg.cc/WDCCwP00)

	- 创建本地密文：

	```c
	ssh-keygen -t rsa -C //-t是加密类型，rsa是非对称加密算法
	```
	- 在相应目录中查找，使用记事本打开，末尾要有邮箱
	- 在github密钥处绑定，绑定时需要重新输入密码
	- 测试是否成功：
	```c
	ssh -T git@github.com
	```
[![image.png](https://i.postimg.cc/rmZkwBRV/image.png)](https://postimg.cc/HcMKSPtR)

	- 绑定仓库路径：
	  git remote orgin (别名)  后面加路径（可加双引号，删除remove),执行成功是没有反应的	
	```c
	git remote origin ssh //ssh后面加路径	
	```
		

### 本地设备与云端的交互

- 上传与更新

	- 本地有对应的code.c或cpp文件
	- 使用git add code.c把文件录入到git缓冲区
	```c
	git add code.c
	```

	- 使用git commit -m "中文、英文提交声明“,提交到本地仓库
	```c 
	git commit -m "this is a test commit"
	```

	- 使用git push orgin master提交到云端（需要有网络，别名要正确，如果有同名则覆盖，无则创建）
	
	```c
	git push origin master
	```
[![image.jpg](https://i.postimg.cc/Jh1Vcrb7/image.jpg)](https://postimg.cc/LJ0bmMCG)

- 云端更新，本地未更新

	- 云端更新本地没更新会导致版本不一致，这时候本地更新到云端会被拒绝，需要使用pull命令
	- 第一步：
	```c
	git pull --rebase orgin master
	```

	- 第二步选择方式
	```c

		 git rebase --skip //把引起冲突的commmit丢掉
		- git rebase --rebort  //恢复rebase之前的代码
		- git rebase --continue //合并冲突，解决冲突，再次提交解决完的代码
	```

	- 第三步正常进行上传更新

- 下载
	```c
	 git clone http(复制粘贴)
	```
- 其他命令

	- git status查看状态，可以看到你的删除操作
	- git rm 文件名彻底删除你的文件，包括库
	- git restore 文件名如果库还有对应文件，进行恢复

## markdown

### 文本修饰语言

### 语法

- <br>

	- 换行标签，也可以自己使用回车加空格实现换行

- #

	- 标题，几级标题就几个#号，#号与标题内容隔开一个空格

- *

	- 字体修饰符

		- *内容*，斜体
		- **内容**，粗体
		- ***内容***，斜粗体

	- 无序修饰符

		- *空格 一级列表标题
		- 换行加table，*空格 二级标题（三级列表类似）


- ~~

	- \~~内容~~，删除线

- --

	- 分割线

- \>
	- 引用，几级引用就有几个>
	
- 数字.

	- 有序列表，使用方法与无序一致，可以相互混合使用
[![image.png](https://i.postimg.cc/q7jf1PLs/image.png)](https://postimg.cc/JyDdndS0)

[![image.jpg](https://i.postimg.cc/j55pmMgG/image.jpg)](https://postimg.cc/8F2XrmVH)

- 表格

	- 使用形式 

		- 属性|属性|属性

	- 对齐方式

		- --|，左对齐
		- ：--：|居中
		- --:|右对齐（后面没有其他属性就不跟|）

[![image.png](https://i.postimg.cc/2SY8Mf4M/image.png)](https://postimg.cc/Vd780pZW)

[![image.png](https://i.postimg.cc/YCxqwyR9/image.png)](https://postimg.cc/RWNz7dj5)


- `(反点)

	- \`\`\`代码类型  代码 \`\`\`  
[![image.png](https://i.postimg.cc/6QjW82Dx/image.png)](https://postimg.cc/p9jb7TWs)

	- 凸显，\`内容\`
[![image.png](https://i.postimg.cc/ZRWTpYSB/image.png)](https://postimg.cc/47TkTgns)

- 超链接

	- [链接名] （https,"链接说明"）

- 图片

	- ！[图片名] （图片的本地路径或网络路径，"图片说明"）
	- 如果是本地路径，云端是无法访问的，所以需要图床工具来转成网络地址

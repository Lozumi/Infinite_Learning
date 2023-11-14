记载WSL2上Debian的安装过程和一些常用优化配置，带来流畅的使用体验。

## WSL2安装Debian

待更新。

## WSL2上Debian的优化配置

### 设置使用 `sudo` 时免输密码

每次使用 sudo 时都需要输入密码确实烦人, 毕竟是私人电脑, 安全性有锁屏密码保护就可以了, 为了使用方便, 不仿取消使用 sudo 时需要输入 root 用户密码的设定:

打开终端, 输入 sudo vi /etc/sudoers , 在打开的文件中, 将

```sh
%sudo ALL=(ALL:ALL) ALL
```


改为：

```sh
%sudo ALL=(ALL:ALL) NOPASSWD:ALL
```


即可。

### 更换国内软件源

#### 编辑软件源列表

软件源配置保存在`/etc/apt/sources.list`中，打开以修改。

```sh
sudo vim /etc/apt/sources.list
```

按i插入，使用鼠标或方向键控制光标删除原有软件源，并任选以下源写入。个人认为中科大源库较全面，速度较快。

中科大

```sh
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse

```

阿里云

```sh
deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse

```

清华TUNA

```sh
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse

```

#### 更新软件源列表

```sh
sudo apt-get update
sudo apt-get upgrade
```

### 显示更多字符：安装自定义字体文件

美化终端提示信息或查看特定文件可能需要系统显示更多的字符。

#### 下载字体

- https://www.nerdfonts.com/font-downloads

可以下载一整个字体包，包含多种样式。

#### 字体生效

将字体包文件夹移动到`/usr/share/fonts`

```sh
cp -r {font_dir_path} /usr/share/fonts/{certain_dir} //按实际情况填入
```

更新字体缓存

```sh
cd /usr/share/fonts
sudo apt-get install fontconfig
fc-cache -fv
```

查看字体列表

```sh
fc-list
```

重启终端即生效。

### 参考资料

[powerlevel10k: 最好看，方便，实用的命令行主题 - luoxian - 博客园 (cnblogs.com)](https://www.cnblogs.com/luoxian1011/p/15854153.html)

[教你如何将WSL系统更换国内源？+固定路径+国内镜像源+详细教程_星辰同学wwq的博客-CSDN博客_wsl换源](https://blog.csdn.net/weixin_41529012/article/details/117226884)

[Centos7安装高版本zsh&zim框架安装powerlevel10k_雪月三十的博客-CSDN博客](https://blog.csdn.net/weixin_49764009/article/details/128646525)
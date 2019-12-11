# IDE Project For gui_dev

### 说明：

​	此SDK非完整版本，完整版本需增加以下文件：

​		1、components/facesdk文件夹

​		2、src/face_gui_demo文件夹

​		完整版本获取方式，请阅读 [获取完整版SDK](https://wiki.ai-alloy.com/start-intro/env-build )。

### 构建

1. 拉取仓库分支

2. 在IDE中打开文件夹

3. 双击 kendryte-package.json, 在"项目配置"页面中配置"项目依赖", 选择"浏览线上软件包列表"

4. 在打开的"软件包管理"页面中选择"kendryte-standalone-sdk", 选择"develop",下载到本地

5. 构建

> 这个仓库支持使用命令行 或者 IDE 进行构建
>
> 有两个名词近似的线上包 kendryte-standalone-sdk 和 kendryte/standalone-sdk 
>
> 为便于管理依赖版本git上后期上传了上面提到的2个包 

### 调试

1. 先启动openocd服务,通过IDE或者手动在控制台启动都可以。建议使用控制台启动，因为这个服务不太稳定容易挂。
2. IDE切换到DEBUG模式，启动调试。可能需要通过重新启动才能正常的进入debug模式。
3. 可以启动调试但是不能设置断点，可能需要完全的重新构建。

### 问题

1. face_gui_demo工程不能编译, 

2. 由gui_dev合并过来,并合并了rt-thread相关的一些编译选项和宏

   > -fno-common会导致运行时挂机
3. 由IDE自动拉取的k210官方代码存在问题
4. 


### IDE设置

 1. 修改E:\KendryteIDE\UserData\latest\user-data\User\settings.json的用户配置文件,禁用自动格式化
```json
    {
        "editor.formatOnType": false,
        "editor.formatOnPaste": false,
        "editor.formatOnSave": false
    }
```

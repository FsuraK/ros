#方法一：ssh
缺点是每个电脑的ssh不一样，不同网络可能也不一样
## 配置


#方法二：个人令牌
## 下载---使用token/个人令牌---直接访问和修改

直接用：git clone https://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@github.com/FsuraK/ros.git
密码：每次都要输入，不好使

## 上传---首先cd ros目录
git add .  
// 此处的“.”表示当前目录，如果只添加某些目录，则使用：git add [目录1] [目录2]

git commit -m "提交注释"  
// 提交

git push -u origin main  
// 提交到远程仓库

## 从github更新到本地
git pull origin  

//如果本地修改了文件，会发生冲突  
//将本地恢复到上一个commit id，然后再执行上面的指令  
git reset --hard  





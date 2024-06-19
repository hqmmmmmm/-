
[Git 基本操作 | 菜鸟教程](https://www.runoob.com/git/git-tutorial.html)



---

### 配置用户信息
```shell
git config --global user.name   "xxx"
git config --global user.email  "xxx"
git config --list    # 查看配置信息
```

---

### 分支管理

```shell
git branch          # 列出所有分支
git branch dev      # 创建dev分支

git checkout dev      # 切换到dev分支
git checkout -b dev   # 创建dev分支并切换到该分支下

git switch dev      # 切换到dev分支
git switch -c dev   # 创建dev分支并切换到该分支下

git branch -d dev   # 删除dev分支

git merge dev      # 将dev分支合并到当前分支

git merge --abort   # 退出合并的中间状态
```












## 3.远程仓库
生成ssh密钥
ssh-keygen -t rsa -C "youremail@example.com"

### 3.1添加远程库

添加远程库
git remote add origin git@github.com:[username]/learngit.git

git push -u origin master   
加上了-u参数，Git不但会把本地的master分支内容推送的远程新的master分支，还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令。

查看远程库信息
git remote -v  

解除本地和远程的绑定关系
git remote rm origin

### 3.2从远程库克隆

git clone [url]





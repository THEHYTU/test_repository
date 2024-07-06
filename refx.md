# 数据结构复习

## 一、二叉树

### 1.二叉树的性质

（1）总节点2^k -1

(2)叶子节点2^(k-1)

(3)n0=n2+1，度为0的节点是度为2的数目+1，度1度0度2的节点和为总节点数目

（4）完全二叉树的深度为log 2 ^n +1

（4）完全二叉树的父亲节点如果是0-n/2,那么2i+1>=n有左节点，2i+2>=n有右节点

## 2.二叉树的遍历：

（1）非递归的深度优先遍历

先序：

```c++
void PreOrderLoop(TreeNode *root)
{
    std::stack<TreeNode *> s;
    TreeNode *cur, *top;
    cur = root;
    while (cur != NULL || !s.empty())
    {
        while (cur != NULL)
        {
            printf("%c ", cur->data);
            s.push(cur);
            cur = cur->left;
        }

        top = s.top();
        s.pop();

        cur = top->right;
    }
}
```



中序：

```c++
void InOrderLoop(TreeNode *root)
{
    std::stack<TreeNode *> s;
    TreeNode *cur;
    cur = root;
    while (cur != NULL || !s.empty())
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();
        printf("%c ", cur->data);

        cur = cur->right;
    }
}
```

后序：

```c++
void PostOrderLoop(TreeNode *root)
{
    std::stack<TreeNode *> s;
    TreeNode *cur, *top, *last = NULL;
    cur = root;
    while (cur != NULL || !s.empty())
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }

        top = s.top();

        if (top->right == NULL || top->right == last){
            s.pop();
            printf("%c ", top->data);
            last = top;
        }
        //左右根，需要保证当前节点是度为0的节点
        else {
            cur = top->right;
        }
    }
}
```

（2）广度优先

非递归：

```c++
void floorTravarsal(BinaryTree* tree) {
    queue<BinaryTree*> waitQue;
    waitQue.push(tree);
    while (!waitQue.empty()) {
        BinaryTree* p = waitQue.front();
        waitQue.pop();
        cout << p->data << endl;
        if (p->p_left != nullptr) {
            waitQue.push(p->p_left);
        }
        if (p->p_right != nullptr) {
            waitQue.push(p->p_right);
        }
    }
    cout << endl;
}
```

可以参考的链接：

[二叉树]: https://blog.csdn.net/Monster_ii/article/details/82115772	"二叉树的遍历"



递归没写过，这里仅参考用：

```c++
public void sequenceTraversal(Tree root) {
    if (root == null) {
        return;
    }
    int deep = deep(root);
    for (int i = 1; i <= deep; i++) {
        seqTraversal(root, i);
    }
}

private void seqTraversal(Tree root, int level) {
    if (root == null || level < 1) {
        return;
    }

    if (level == 1) {
        System.out.print(root.data + " ");
        return;
    }
    //左子树
    seqTraversal(root.lchild, level - 1);
    //右子数
    seqTraversal(root.rchild, level - 1);
}

/**
 * 计算树的深度
 * @param root
 * @return
 */
public int deep(Tree root) {
    if (root == null) {
        return 0;
    }

    int left = deep(root.lchild);
    int right = deep(root.rchild);

    return (left > right) ? (left + 1) : (right + 1);
}

```

3.完全二叉树的创建

```c++
BinTree CreateBinTree()//创建一个完全二叉树，是全过程的精髓
{
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreateQueue();//创建一个空队列
	scanf_s("%d", &Data);//临时存放数据
	if (Data != NoInfo)//等于0表示输入终结
	{
		BT = (BinTree)malloc(sizeof(struct TreeNode));//为二叉树节点申请一个内存,先插入二叉树
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT);//入队
	}
	else//等于0表示输入终结
		return NULL;
	while (Q->Size != 0)//如果队列不为空
	{
		T = DeleteQ(Q);//出队,已经筛选好了指针，可以直接用
		scanf_s("%d", &Data);
		if (Data == NoInfo)
		{
			T->Left = NULL;
			T->Right = NULL;
			return BT;
		}
		else//为新数据申请内存节点，把节点插入二叉树
		{
			T->Left = (BinTree)malloc(sizeof(struct TreeNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ(Q, T->Left);
OBOBOBOBOBOB		}
		scanf_s("%d", &Data);
OBOBOB		if (Data == NoInfo)
OBOBOB		{
OBOBOB			T->Right = NULL;
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB			return BT;
		}
OBOBOB		else//为新数据申请内存节点，把节点插入二叉树
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB		{
			T->Right = (BinTree)malloc(sizeof(struct TreeNode));
OBOBOB			T->Right->Data = Data;
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB			T->Right->Left = T->Right->Right = NULL;
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB			AddQ(Q, T->Right);
OBOBOB		}
	}
OBOBOB	return BT;
}
OBOBOB
```
OBOBOB
OBOBOB### 3.二叉搜索树
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
​	（一）二叉搜索树的特点
OBOBOB
OBOBOB​	二叉搜索树：一棵二叉树，可以为空；如果不为空，满足以下性质：
OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB1. 非空左子树的所有键值小于其根结点的键值。
OBOBOB
2. 非空右子树的所有键值大于其根结点的键值。
OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB3. 左、右子树都是二叉搜索树。
OBOBOB
OBOBOB   （二）二叉搜索树的插入与删除
OBOBOB
[6~OBOBOBOBOBOBOBOB   插入：

OBOBOBOBOBOBOBOBOB   ```c++
OBOBOB   BinTree Insert( BinTree BST, ElementType X )
OBOBOB[6~OBOBOBOBOBOBOBOB   {
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB       if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
           BST = (BinTree)malloc(sizeof(struct TNode));
           BST->Data = X;
           BST->Left = BST->Right = NULL;
OAOAOAOAOAOAOAOAOA       }
       else { /* 开始找要插入元素的位置 */
OAOAOA           if( X < BST->Data )
               BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
OAOAOA           else  if( X > BST->Data )
OBOBOB               BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
           /* else X已经存在，什么都不做 */
       }
       return BST;
   }
   
   ```

   删除：

   ```c++
   BinTree Delete( BinTree BST, ElementType X ) 
   { 
       Position Tmp; 
       if( !BST ) 
           printf("要删除的元素未找到"); 
       else {
           if( X < BST->Data ) 
               BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
           else if( X > BST->Data ) 
               BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
           else 
OAOAOA           { /* BST就是要删除的结点 */
               /* 如果被删除结点有左右两个子结点 */ 
               if( BST->Left && BST->Right ) 
               {
                   /* 从右子树中找最小的元素填充删除结点 */
                   Tmp = FindMin( BST->Right );
                   BST->Data = Tmp->Data;
                   /* 从右子树中删除最小元素 */
                   BST->Right = Delete( BST->Right, BST->Data );
               }
               else 
               { /* 被删除结点有一个或无子结点 */
                   Tmp = BST; 
                   if( !BST->Left )       /* 只有右孩子或无子结点 */
                       BST = BST->Right; 
                   else                   /* 只有左孩子 */
                       BST = BST->Left;
                   free( Tmp );
               }
           }
       }
       return BST;
   }
   
   ```

   ### 4.二叉树的旋转

   //没有验证过

   ```c++
   #pragma once
    
   #include <iostream>
   using namespace std;
    
   template <class T>
   struct TreeNode
   {
   	T data;
   	TreeNode* pLeft;		//左孩子
   	TreeNode* pRight;		//右孩子
   	int height;				//高度
   	TreeNode(const T& data)
   	{
   		this->data = data;
   		pLeft = pRight = nullptr;
   		height = 0;
   	}
   };
    
   template <class T>
   class ACL_Tree
   {
   public:
   	ACL_Tree() { pRoot = nullptr; }
   	~ACL_Tree() {}
   	//插入节点
   	void Insert_Node(const T& newdata)
   	{
   		_insert(pRoot, newdata);
   	}
   	//获取某个节点的高度
   	int _getHeight(TreeNode<T>* root);
    
   	//情况一 右旋
   	TreeNode<T>* RR(TreeNode<T>* root);
   	//情况二 左旋
   	TreeNode<T>* LL(TreeNode<T>* root);
   	//情况三 左右旋
   	TreeNode<T>* LR(TreeNode<T>* root);
   	//情况四 右左旋
   	TreeNode<T>* RL(TreeNode<T>* root);
OBOBOB   private:
OBOBOBOBOBOB   	void _insert(TreeNode<T>*& pRoot, const T& data);
   private:
   	TreeNode<T>* pRoot;
OBOBOBOBOBOBOBOBOB   };
OBOBOBOBOBOBOBOBOB    
    
OBOBOB   template <class T>
   void ACL_Tree<T>::_insert(TreeNode<T>*& pRoot, const T& data)
OBOBOBOBOBOBOBOBOB   {
   	if (pRoot == nullptr)
OBOBOB   	{
OBOBOBOBOBOB   		//如果当前节点为空，则直接插入
   		pRoot = new TreeNode<T>(data);
   	}
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   	else if (data < pRoot->data)
   	{
OBOBOB   		//左插
OBOBOB   		_insert(pRoot->pLeft, data);
OBOBOB   		//判断是否需要旋转
   		if (_getHeight(pRoot->pLeft) - _getHeight(pRoot->pRight) > 1)
OBOBOB   		{
   			if (data < pRoot->pLeft->data)
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   			{
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   				//RR  左旋
   				pRoot = RR(pRoot);
OBOBOB   			}
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   			else
   			{
OBOBOB   				//LR  左右旋
   				pRoot = LR(pRoot);
   			}
OBOBOB   		}
   	}
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   	else
   	{
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   		//右插
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   		_insert(pRoot->pRight, data);
   		if (_getHeight(pRoot->pRight) - _getHeight(pRoot->pLeft) > 1)
OBOBOB   		{
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   			if (data >= pRoot->pRight->data)
   			{
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB   				//LL 右旋
   				pRoot = LL(pRoot);
   			}
OBOBOBOBOBOBOBOBOB   			else
   			{
   				//RL  右左旋
   				pRoot = RL(pRoot);
   			}
OAOAOA   		}
OAOAOA   	}
   	//3 设置高度
OAOAOA   	int leftHeight = _getHeight(pRoot->pLeft);
   	int rightHeight = _getHeight(pRoot->pRight);
OAOAOA    
   	pRoot->height = 1 + (
   		(leftHeight > rightHeight) ? leftHeight : rightHeight
   		);
   }
    
   template<class T>
   //获取某个节点的高度
   inline int ACL_Tree<T>::_getHeight(TreeNode<T>* root)
   {
   	if (root)
   	{
   		return root->height;
   	}
   	return 0;
   }
   //右旋
   template<class T>
   inline TreeNode<T>* ACL_Tree<T>::RR(TreeNode<T>* pRoot)
   {
   	//1. pTemp临时存储pRoot的pLeft
   	TreeNode<T>* pTemp = pRoot->pLeft;
   	//2. pTemp的右孩子成为pRoot的左孩子
   	pRoot->pLeft = pTemp->pRight;
   	//3. pRoot成为pTemp的右孩子
   	pTemp->pRight = pRoot;
   	//4. 高度设置
   	pRoot->height = 1 + ((_getHeight(pRoot->pLeft) > _getHeight(pRoot->pRight)) ?
   		_getHeight(pRoot->pLeft) : _getHeight(pRoot->pRight));
   	pTemp->height=1+ ((_getHeight(pTemp->pLeft) > _getHeight(pTemp->pRight)) ?
   		_getHeight(pTemp->pLeft) : _getHeight(pTemp->pRight));
    
   	return pTemp;
   }
   //左旋
   template<class T>
   inline TreeNode<T>* ACL_Tree<T>::LL(TreeNode<T>* pRoot)
   {
   	//1. pTemp临时存储pRoot的pRight
   	TreeNode<T>* pTemp = pRoot->pRight;
   	//2. pTemp的左孩子成为pRoot的右孩子
   	pRoot->pRight = pTemp->pLeft;
   	//3. pRoot成为pTemp的左孩子
   	pTemp->pLeft = pRoot;
   	//4. 高度设置
   	pRoot->height = 1 + ((_getHeight(pRoot->pLeft) > _getHeight(pRoot->pRight)) ?
   		_getHeight(pRoot->pLeft) : _getHeight(pRoot->pRight));
   	pTemp->height = 1 + ((_getHeight(pTemp->pLeft) > _getHeight(pTemp->pRight)) ?
   		_getHeight(pTemp->pLeft) : _getHeight(pTemp->pRight));
    
   	return pTemp;
   }
    
   template<class T>
   inline TreeNode<T>* ACL_Tree<T>::LR(TreeNode<T>* pRoot)
   {
   	//以pRoot的pLeft为轴左旋
   	pRoot->pLeft = LL(pRoot->pLeft);
   	//再右旋
   	return RR(pRoot);
   }
    
   template<class T>
   inline TreeNode<T>* ACL_Tree<T>::RL(TreeNode<T>* pRoot)
   {
   	//以pRoot的pRight为轴右旋
   	pRoot->pRight = RR(pRoot->pRight);
   	//再左旋
   	return LL(pRoot);
   }
    
   ```

   

OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOB
OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB## 二、B树

OBOBOB### 1.B要求
OBOBOB
- M阶段B树即是M杈
- 各个节点内记录的个数<=M-1
OBOBOB- 根节点的记录个数可以是1个
OBOBOB- 其他节点的记录个数>=ceil(M/2)-1
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 各个节点的记录索引从左到右从小到大有序
- 左子树的记录索引<当前记录<右子树的记录索引
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
### 2.B插入
OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 将当前记录放入叶子节点中
- 讨论叶子节点内记录的个数
OBOBOB
  - /<m-1,不处理
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB  - />m-1，裂变，中间节点移至父亲层，左右两侧的节点记录成为其左右子树，讨论父亲节点的记录个数
OBOBOBOBOBOB
OBOBOB### 3.B删除
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
- 查找（非叶子变成叶子）
OBOBOB- 删除一条记录
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 讨论节点内的记录个数
OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB  - />=ceil(m/2)-1,不处理
  - <ceil(m/2)-1

    - 先找兄弟借，兄弟节点满足要求，兄弟如果在左边，兄弟节点右侧上升变为父亲，父亲下移加入自己
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB    - 兄弟如果在右边，父亲节点下移，兄弟节点的最左节点上升成为父亲
    - 兄弟节点不满足要求，找父亲借，父亲节点下移，兄弟父亲自己组合成新的节点
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOB    - 讨论对象变成父亲节点

OBOBOB## 三、B+树
OBOBOB
[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB### 1.B+要求

OBOBOB- M阶树M叉
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOB- 节点分为索引节点和叶子节点
- 节点内的记录/索引的个数<=M-1
OBOBOBOBOBOBOBOBOB[6~OBOBOBOBOB- 根节点即可是叶子节点也可以是索引节点
OBOBOB- 根节点的记录个数可以是一个
- 从左到右从小到大有序
OBOBOB- 左子树记录的值<当前记录<右子树记录的值
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 节点的个数>ceil(M/2)-1
- 相邻的叶子节点间有指针从左到右指向
OBOBOB
OBOBOB### 2.B+插入
[6~OBOBOBOBOB
- 将当前记录放入叶子节点中
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 讨论叶子节点内记录的个数
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB  - <m-1,不处理
  - \>m-1，裂变，前M/2成为左子树，第M/2+1个记录索引复制一份到父亲节点，讨论父亲节点的个数
OBOBOB    - <=M-1不处理
OBOBOB    - \>M-1，裂变，中间索引移动到父亲层，左侧成为其左子树，右侧成为其右子树，继续讨论新的父亲的索引
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB### 3.B+删除

[6~OBOBOBOBOBOBOBOBOBOBOB- 查找
- 删除一条记录
OBOBOBOBOBOB[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 讨论节点内的记录个数

[6~[6~OB  - />=ceil(m/2)-1,不处理，删除的节点如果是父亲索引对应的节点，那么更新父亲索引
OBOBOBOBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB  - <ceil(m/2)-1
    - 兄弟节点有空余，兄弟记录移动一个到当前节点，更新父亲索引
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB    - 兄弟节点不满足要求，将当前节点与兄弟节点结合成一个新的节点，删除父亲索引

OBOBOB      - 讨论父亲节点索引的个数
OBOBOB
[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB        - 满足要求不处理
        - 小于，看父亲兄弟节点的个数
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB          - 大于，父亲索引下移到当前节点，兄弟节点上移一个索引到父亲层
          - 等于，父亲索引下移与当前节点兄弟节点合并成一个新的节点，讨论新的父亲索引的个数
OBOBOB
[6~[6~[6~OBOBOBOBOBOB## 四、红黑树

OBOBOB### 1.RBT性质
OBOBOB
OBOBOB- 节点不是红的就是黑色的
OBOBOB- 根节点必须是黑色的
- 终端的空节点视为黑色的节点，即黑哨兵
OBOBOB- 树中不允许两个红色节点是父子关系
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB- 从任意节点出发，到它所能到达的终端节点的各个路径上黑色节点的数目必须相等

OBOBOB### 2.有关RBT的结论
OBOBOB
OBOBOB- 没有一条路径的长度是其他路径长度的两倍
OBOBOB- 增删查的时间消耗是log2 n
OBOBOB
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB### 3.RBT的添加

OBOBOB是否为空
OBOBOB
OBOBOB- 空，当前节点为根节点，颜色变为黑色
[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOB- 非空

OBOBOB  - 父亲为黑色，直接添加
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
  - 父亲为红色
OBOBOB
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB    - 叔叔是红色
OBOBOBOBOBOB
[6~OBOBOBOBOBOBOBOBOBOBOB      - 父亲和叔叔变黑色，爷爷变成红色，对爷爷进行重新讨论（需要判断爷爷是不是根节点）
OBOBOB
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB    - 叔叔是黑色或者空

OBOBOB      - 父亲在爷爷的左侧
[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
        ​    子节点在父亲的左值，LL;父变黑，爷爷变红，爷爷右旋
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
        ​	子节点在父亲的右侧，LR;父亲变黑，爷爷变红，父亲左旋，转换为LL
OBOBOB
OBOBOBOBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB      - 父亲在爷爷的右侧
OBOBOB
OBOBOB        ​		子节点在父亲的右侧，RR;父变黑，爷爷变红，爷爷左旋
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
        ​		子节点在父亲的左侧，RL;父变黑，爷爷变红，父亲右旋，转换为RR
OBOBOBOBOBOB
OBOBOB    
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOBOBOBOBOBOBOB[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB  ### 4.RBT的删除
OBOBOB
OBOBOB  ​	讨论被删除节点的情况

OBOBOB  - 情况一：树只有根，且无子，直接删除，树变为空
  - 情况二：被删除节点是根且有一个孩子，红子变黑成为新根
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB  - 情况三：被删除的叶子节点是红色的，直接删除，把其赋空
  - 情况四：被删除的节点是黑色节点，且有一个孩子的情况下，把红子变黑，爷孙相连，删掉黑节点
OBOBOB  - 情况五：被删除节点是黑色，非根，无子，可以直接删，然后再讨论情况（按顺序）
OBOBOB
    - 找兄弟，兄弟是红色的，兄弟变黑，父亲变为红色，以父亲为旋转点，旋转（看兄弟在哪个方向，兄右左旋，兄左右旋），更新兄弟节点
    - 兄弟是黑色的，没有子节点（或两个侄子全黑），找父亲
OBOBOB
      - 父亲是红色的，父亲变黑，兄弟变红，结束操作
OBOBOB      - 父亲是黑色的，兄弟变红，父亲变为新的操作节点，继续讨论（如果父亲为根）

OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB    - 兄弟是黑色的，侄子富裕的情况（侄子中有红色的）

OBOBOB      - 左侄子红，右侄子黑
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOBOBOBOBOBOBOB[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB        - 兄弟在父亲的右侧

OBOBOB          - 兄弟变为红色，左侄子变黑，以兄弟为旋转点，右旋，更新兄弟节点
OBOBOB
OBOBOB        - 兄弟是父亲的左侧
OBOBOB
OBOBOB          - 父亲颜色给兄弟，父亲变为黑色的，左侄子变为黑色的，以父亲为旋转点，右旋，结束操作
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
      - 左侄子黑，右侄子红 + 左侄子红，右侄子红
OBOBOB
OBOBOB        - 兄弟在父亲的右侧
OBOBOB
[6~[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB          - 父亲颜色给兄弟，父亲变为黑色的，右侄子变为黑色的，以父亲为旋转点，左旋，结束操作

OBOBOB        - 兄弟在父亲的左侧

OBOBOB          - 兄弟变为红色，右侄子变为黑色，以兄弟为旋转节点左旋，更新兄弟节点
OBOBOB
## 五、字典树
OBOBOB[6~[6~OBOBOBOBOBOBOB
#### 	1.功能
OBOBOBOBOBOB
OBOBOB​		查找
​		计数
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB​		排序

OBOBOBOBOBOBOBOBOBOBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB#### 	2.特点
OBOBOBOBOBOB
​		根节点不能为空
OBOBOB​		节点内没有字符
OBOBOB
OBOBOBOBOBOBOBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB#### 	3.创建

OBOBOBOBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB​			(1)遍历str
OBOBOB​				无指向，创建节点，下一个
OBOBOB​				有指向，下一个
OBOBOB​			（2）末尾标记

OBOBOB代码：
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB
OBOBOB[6~OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB```c++
#include<iostream>
OBOBOB#include<stdlib.h>
OBOBOB#include<vector>
using namespace std;
OBOBOB//定义一个结构体
OBOBOBtypedef struct Trie
{
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB	int count ;//计数器，初始值为0，为1时表示结束
	vector<Trie*> Chidren;
	string str;//使数据更直观
OBOBOB	Trie():Chidren(26),count(0),str("") {}//初始化
[6~OBOB}Trie;
void Addword(Trie*& root, vector<string> dic)
OBOBOB{
	//循环输入
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB	for (int i = 0; i < dic.size(); i++)
	{
OBOBOB		string temp = dic[i];//依次赋值
		Trie* node = root;
		//遍历创建
OBOBOB		for (int j = 0; j < temp.size(); j++)
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB		{
			if (node->Chidren[temp[j] - 'a'] == NULL)
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB			{
				//没有就创建新的节点
OBOBOB				node->Chidren[temp[j] - 'a'] = new Trie();
			}
OBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOBOB			node = node->Chidren[temp[j] - 'a'];
OBOBOB			
		}
OBOBOBOBOBOBOBOBOBOBOBOB		node->str = temp;
		node->count = 1;
		
OBOBOB	}
}
//遍历
void Travalsaver(Trie* root)
{
	if (root == NULL) return;
	if (root->count == 1)
		cout << root->str << endl;
	for (int i = 0; i < 26; i++)
	{
		Travalsaver(root->Chidren[i]);
	}
}
//查询
void Serach(Trie* root,string str)
{
	Trie* p = root;
	for (int i = 0; i < str.size(); i++)
	{
		if (p->Chidren[str[i] - 'a'] == NULL)
		{
			//没有就创建新的节点
			cout << "当前字典树中不存在这个单词" << endl;
			return;
		}
		p= p->Chidren[str[i] - 'a'];
		if (p->count == 1)
		{
			cout << "找到了" << endl;
			return;
		}
	}
}

int main()
{
	Trie* tree = new Trie();
	vector<string> dic = {"abondon","apple","wacting","gift","lover","back","heart"};
	Addword(tree, dic);
	Travalsaver(tree);
	Serach(tree, "heart");
	return 0;
}
```



## 六、哈希表

### 1.映射方式

- 散列函数

### 2.可能的问题

- 哈希冲突(不同的值计算出的哈希值可能相同)

### 3.解决方法

- 开放地址

  - 线性探测

    - 往后寻找空间，后面没人就占用
    - 适用于数据量小的情况下

  - 线性补偿探测（基本没人用，固定间隔）
  - 二次探测（+-1,+-4,+-9.......）

- 拉链法

  - 利用链表进行存储

### 4.探究与比较

- 线性探测

OAOAOA  - 装载因子要小于0.8，越趋近于0.8冲突可能性越大
  - 装载因子阿尔法=数据个数/表长
  - 扩容问题
  - 删除问题

- 拉链法

  - 阿尔法小于1
  - 扩容问题

    - 旧表当中的节点空间是完全可以复用的

OAOAOA      - 我们在依次变量的时候就 直接依次遍历链表和其中的结点，把每个结点直接挪到 新表的 指针数组后面，按照新表当中的 插入规则插入即可

  - 删除问题

    - 正常的链表删除

- 比较得出拉链法的优点

  - 冲突处理简单
  - 删除简单
  - 数据量未知的情况下更方便处理问题
  - 数据量大数据空间大

## 七、图

### 		1.图的简单创建

```c++
#include <iostream>
#include <cstring> // for memset
#include <queue>
using namespace std;

#define MaxNum (100)

typedef struct graph
{
    int array[MaxNum][MaxNum]; // 邻接矩阵
    int nNum, edgeNum;         // 顶点与边的个数
} graph;

graph* CreGraph()
{
    graph* t = new graph;
    // 输入边与节点的个数
    cout << "输入顶点与边的个数：";
    cin >> t->nNum >> t->edgeNum;

    // 检查输入的顶点和边的个数是否合理
    if (t->nNum > MaxNum || t->nNum <= 0 || t->edgeNum < 0) {
        cout << "输入的顶点或边的数量不合法。" << endl;
        delete t;
        return nullptr;
    }

    // 设置初值为0
    memset(t->array, 0, sizeof(t->array));

    // 开始放入边
    int v1, v2;
    for (int i = 0; i < t->edgeNum; i++)
    {
        cout << "输入两个顶点：";
        cin >> v1 >> v2;
OBOBOB        if (v1 != v2 && v1 >= 1 && v2 >= 1 && v1 <= t->nNum && v2 <= t->nNum && t->array[v1 - 1][v2 - 1] == 0)
        {
            t->array[v1 - 1][v2 - 1] = 1;
            t->array[v2 - 1][v1 - 1] = 1;
        }
        else
        {
            cout << "输入不合法或重复边，重新输入。" << endl;
            i--;
        }
    }
    return t;
}

void traversal(graph* p)
{
    if (p == nullptr) return;



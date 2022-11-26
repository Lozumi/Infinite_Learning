// 约瑟夫环（加强版）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

/*************************************链表的节点*****************************/
template <typename T>
struct node1
{
public:
    T number;       //存编号；
    T password;     //存密码；
    node1<T> *next; //指向下一个节点的地址；
};

/*************************************************************************************/

/*************************************链表类的建立************************************/
template <typename T>
class link
{                     //链表类；
    node1<T> *header; //只有一个属性值；其保存链表的头部节点的头地址；
public:
    link();                                           //无参构造函数；
    ~link();                                          //析构函数；
    node1<T> *back() const;                           //返回链表的头节点地址；
    int len_link() const;                             //计算链表的长度；
    void trave_two() const;                           //对节点的两个变量进行遍历；
    void trave_one() const;                           //对节点的一个变量进行遍历；
    void create_new_node(const int a, const int b);   //创建向节点加入两个变量的新节点；
    void create_new_node(const int a);                //创建向节点加入一个变量的新节点；
    void replace_password(const int a, int password); //改变编号为a的节点的密码；
    void delete_link();                               //删除链表；
    void remove_one_node(node1<T> *p);                //删除一个节点；
    int remove_more(const int x);                     //删除编号为x的所有节点；
    node1<T> *find_id(const int x);                   //查找编号为x的用户，不存在则返回null；
    node1<T> *loaction(int x);                        //返回第x节点的内存地址；
    void insert(node1<T> *p, node1<T> *q);            //在p节点后加入q节点，不存在p节点则输出操作失败；
    int back_name(const int t);                       //返回编号为t的密码；
};

template <typename T>
link<T>::link()
{
    header = nullptr;
}

template <typename T>
link<T>::~link()
{
    delete_link();
}

//返回链表的头地址；
template <typename T>
node1<T> *link<T>::back() const
{
    return header;
}

//计算链表的长度；
template <typename T>
int link<T>::len_link() const
{
    node1<T> *p;
    p = header;
    int k = 0;
    while (p != nullptr)
    {
        k++;
        p = p->next; //指向下一个节点；
    }
    return k;
}

//对节点的两个变量进行遍历；
template <typename T>
void link<T>::trave_two() const
{
    node1<T> *cour;
    cour = header;
    if (cour == nullptr)
        ;
    else
    {
        while (cour != nullptr)
        {
            cout << "Number: \t" << cour->number << "\t";
            cout << "Password: \t" << cour->password << "\n"; //输出每个节点的值；
            cour = cour->next;
        }
        cout << endl;
    }
}

//对节点的一个变量进行遍历；
template <typename T>
void link<T>::trave_one() const
{
    node1<T> *cour;
    cour = header;
    if (cour == nullptr)
        ;
    else
    {
        while (cour != nullptr)
        {
            cout << cour->number << ' ';
            //输出每个节点的值；
            cour = cour->next;
        }
        cout << endl;
    }
}

//创建向节点加入两个变量的新节点；
template <typename T>
void link<T>::create_new_node(const int a, const int b)
{
    if (header == nullptr)
    {
        header = new node1<T>;
        header->number = a;
        header->password = b;
        header->next = nullptr;
    }
    else
    {
        node1<T> *q;
        q = header;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        node1<T> *p;
        p = new node1<T>;
        p->number = a;
        p->password = b;
        q->next = p;
        p->next = nullptr;
    }
}

//创建向节点加入一个变量的新节点；
template <typename T>
void link<T>::create_new_node(const int a)
{
    if (header == nullptr)
    {
        header = new node1<T>;
        header->number = a;
        header->next = nullptr;
    }
    else
    {
        node1<T> *q;
        q = header;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        node1<T> *p;
        p = new node1<T>;
        p->number = a;
        q->next = p;
        p->next = nullptr;
    }
}

//改变编号为a的节点的密码；
template <typename T>
void link<T>::replace_password(const int a, int password)
{
    node1<T> *p;
    p = header;
    while (p != nullptr)
    {
        if (p->number == a)
        {
            p->password = password;
            break;
        }
        p = p->next;
    }
}

//删除一个节点；
template <typename T>
void link<T>::remove_one_node(node1<T> *p)
{
    /*****
    创建一个prve指针
    用prve指针寻找所要删除的p节点的
    前面一个节点的地址；
    *****/
    node1<T> *prve;
    prve = header;
    if (p == prve)
        header = p->next;
    else
    {
        while (prve->next != p)
        {
            prve = prve->next;
        }
        prve->next = p->next;
    }
    delete p;
}

//删除链表；
template <typename T>
void link<T>::delete_link()
{
    /*****
    创建两个node*类型的变量，p&q
    q帮助协助连接链表，p保存链表头，对p进行删除处理；
    *****/
    node1<T> *p;
    node1<T> *q = nullptr;
    p = header;
    while (p != nullptr)
    {
        q = p->next;
        remove_one_node(p);
        p = q;
    }
    header = nullptr;
}

//删除编号为x的所有节点；
template <typename T>
int link<T>::remove_more(const int x)
{
    /****
    q连接节点，p判断是否删除节点，
    并进行删除处理；
    ****/
    int k = 0;
    node1<T> *p;
    node1<T> *q = nullptr;
    p = header;
    while (1)
    {
        if (p->number == x)
        {
            q = p->next;
            remove_one_node(p);
            p = q;
            k++;
        }
        else
            p = p->next;
        if (p == nullptr)
            break;
    }
    return k;
}

//查找编号为x的用户，不存在则返回null；
template <typename T>
node1<T> *link<T>::find_id(const int x)
{
    /****
    创建两个指针，pq
    p判断是否p->n == x
    q返回满足条件的地址；
    ****/
    node1<T> *p;
    node1<T> *q;
    q = p = header;
    while (1)
    {
        if (p->number == x)
        {
            return q;
            break;
        }
        p = p->next;
        q = q->next;
        if (q == nullptr)
        {
            return q;
            break;
        }
    }
}

//返回第x节点的内存地址；
template <typename T>
node1<T> *link<T>::loaction(int x)
{
    /****
    先用 int m保存链表的总长度；
    然后遍历寻找；
    返回P即可；
    ****/
    node1<T> *p;
    p = header;
    int m = 0;
    while (p != nullptr)
    {
        m++;
        p = p->next;
    }
    p = header;
    if (x <= m)
    {
        int i;
        if (x == 1)
            ;
        else
        {
            for (i = 2; i <= x; i++)
                p = p->next;
        }
        return p;
    }
    else
        return nullptr;
}

//返回编号为t的密码；
template <typename T>
int link<T>::back_name(const int t)
{
    node1<T> *p;
    p = header;
    while (p != nullptr)
    {
        if (p->number == t)
        {
            return p->mi;
            break;
        }
        p = p->next;
    }
}

//在p节点后加入q节点，不存在p节点则输出操作失败；
template <typename T>
void link<T>::insert(node1<T> *p, node1<T> *q)
{
    /****
    判断两种情况，
    1.插入头部
    2.插入一般部位
    插入头部直接即可插
    插入一般部位，应先让q连接p后面的节点
    即：q->next = p->next
    然后：p->next = q;
    ****/
    node1<T> *tt = new node1<T>;
    tt = header;
    if (p->next == nullptr)
    {
        p->next = q;
        q->next = nullptr;
    }
    else
    {
        while (tt != p)
        {
            tt = tt->next;
            if (tt == nullptr)
                break;
        }
        if (tt)
        {
            q->next = tt->next;
            tt->next = q;
        }
        else
            cout << "不存在p节点!\n";
    }
}

/*************************************************************************************/

/*********************************约瑟夫环类的创建********************************/
template <typename T>
class Joseph_ring
{
private:
    link<T> t;   //保存初始每位成员编号和密码的链表；
    link<T> tt;  //保存出位顺序编号的链表；
    node1<T> *q; //辅助指针；
    node1<T> *p; //辅助指针；
    int m;

public:
    Joseph_ring(int a);
    ~Joseph_ring();
    void pro_system();             //对生成的约瑟夫环进行处理操作，算出出位顺序并存在tt链表中
    void Generate_list(T *a, T n); //生成储存每位成员的编号和密码的函数
    void trave_tw()
    {
        t.trave_two();
    }
    void trave_on()
    {
        tt.trave_one();
    }
};

template <typename T>
Joseph_ring<T>::Joseph_ring(int a) : m(a)
{
    q = nullptr;
    p = nullptr;
}

template <typename T>
Joseph_ring<T>::~Joseph_ring()
{
    // delete q;
    // delete p;
}

//生成储存每位成员的编号和密码的函数
template <typename T>
void Joseph_ring<T>::Generate_list(T *a, T n)
{
    int i, j = 1;
    for (i = 0; i < n; j++, i++)
        t.create_new_node(j, a[i]);
    p = t.back();
}

//对生成的约瑟夫环进行处理操作，算出出位顺序并存在tt链表中
template <typename T>
void Joseph_ring<T>::pro_system()
{
    int i = 2;
    while (i <= m)
    {
        /*查找数到m时的人的编号*/
        if (p->next == nullptr)
            p = t.back();
        else
            p = p->next;
        i++;
    }
    //将数到m时的编号放入tt链表中；
    tt.create_new_node(p->number);
    //如果到达链表末尾，返回表头；
    if (p->next != nullptr)
        q = p->next;
    else
        q = t.back();
    //更新密码m值；
    m = p->password;
    t.remove_one_node(p);
    p = q;
    //链表不空，接着调用该函数再处理；
    //为空截止；
    if (t.back() != nullptr)
    {
        pro_system();
    }
}
/*************************************************************************************/

int main()
{
    int m;
    cout << "Please input your numbers that you want to test: " << endl;
    int n;
    cin >> n;
    if (n > 0)
    {
        int *a;
        a = new int[n];
        cout << "Please enter everyone's password in turn: \n";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << "Please enter the initial password [m]: \n";
        cin >> m;
        Joseph_ring<int> Jose(m);
        Jose.Generate_list(a, n);
        cout << "We will perform the Joseph loop operation for the initial password m: ["
             << " " << m << " ]\n";
        cout << "Everyone's number and password om order as follows: \n";
        Jose.trave_tw();
        Jose.pro_system();
        cout << "The following is the order in which people are out: \n";
        Jose.trave_on();
        delete[] a;
    }
    else
    {
        cout << "There was a mistake in the number of people entered!\n";
    }
    return 0;
}

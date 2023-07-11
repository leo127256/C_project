#include <iostream>
using namespace std;

typedef class LinkedList {
public:
	LinkedList(int data);
	void headadd_node(int n);
	void tailadd_node(int n);
	int delete_node(int n);
	int search_node(int index);
	int insert_node(int index, int data);
	int search_length() { cout << "Length is " << length << endl; return length; }
	void clear_linkedlist();
	void print();
	bool nohave_head() { 
		if (head == nullptr)
		{
			cout << "没有head结点,请选择创建结点。" << endl;
			return false;
		}
		return true;
	}
	void menu();
private:
	typedef class Node {
	public:
		int data;
		Node* next;
	}node;
	Node* head;
	int length = 0;
}LinkedList;

LinkedList::LinkedList(int data)
{
	head = new Node;
	head->data = data;
	head->next = nullptr;
	length++;

}

void LinkedList::print()
{
	node* p = head;
	for (int count = 0; p != nullptr; p = p->next,count++)
		cout << "(" << count << ")" << p->data << endl;
	cout << endl;
}

void LinkedList::headadd_node(int n)
{
	node* new_node = new Node;
	new_node->data = n;
	new_node->next = nullptr;

	if (head == nullptr) //如果头节点是空的
	{
		head = new_node;
		length++;
	}
	new_node->next = head;
	head = new_node;
	length++;
}

void LinkedList::tailadd_node(int n)
{
	node* new_node = new Node;
	new_node->data = n;
	new_node->next = nullptr;

	if (head == nullptr)
	{
		head = new_node;
		length++;
	}

	node* p = head;
	while (p->next != nullptr)
		p = p->next;
	p->next = new_node;
	length++;
}

int LinkedList::delete_node(int index)
{
	node* p = head;
	node* pre = nullptr;
	int i = 0;

	if (index < 0 || index >= length)
	{
		cout << "删除不合法。" << endl;
		return 0;
	}

	for (;i < length; p = p->next,i++)
	{
		if (index == 0)
		{
			head = p->next;
			cout << "删除了data为" << p->data << "的值。" << endl;
			delete p;
			length--;
			return 1;
		}
		if (i == index)
		{
			pre->next = p->next;
			cout << "删除了data为" << p->data << "的值。" << endl;
			delete p;
			length--;
			return 1;
		}
		pre = p;
	}
	cout << "删除失败。" << endl;
	return 0;
}

int LinkedList::search_node(int index)
{
	node* p = head;
	int i = 0;
	if (index < 0 || index >= length)
	{
		cout << "查找不合法。" << endl;
		return 0;
	}
	for (; i != index; p = p->next, i++);
	cout << "该节点为(" << i << ")" << p->data << endl;
	return 1;
}

int LinkedList::insert_node(int index, int data)
{
	node* new_node = new Node;
	new_node->next = nullptr;
	new_node->data = data;
	node* p = head;
	node* pre = new Node;
	if (index < 0 || index > length)
	{
		cout << "插入不合法。" << endl;
		return 0;

	}

	if (index == 0)
	{
		new_node->next = head;
		head = new_node;
		length++;
		return 1;

	}
	
	for (int i = 0; i < index; p = p->next, i++)
		pre = p;

	if (!pre)
	{
		cout << "插入的点的前一个指针指向的节点是无效的。" << endl;
		return 0;

	}

	if (p == nullptr)
	{
		pre->next = new_node;
		length++;
		return 1;

	}
	else
	{
		pre->next = new_node;
		new_node->next = p;
		length++;
		return 1;
	}
	return 0;

}

void LinkedList::clear_linkedlist()
{
	node* p = head; //指向头节点开始释放他们指向的内存空间
	node* L = p;
	for (int index = 0; index < length; index++)
	{
		L = L->next;
		delete p;
		p = L;
	}
	head = nullptr;
	cout << "清空单链表完毕!" << endl;
	length = 0;
}

void LinkedList::menu()
{
	int choose;
	int data;
	int index;
	while (true)
	{
		cout << "\n------欢迎来到杰哥单链表仿真模拟器------" << endl;
		cout << "(1)头插法          " << "  ";
		cout << "(2)尾插法          " << endl;
		cout << "(3)索引值随机插入法" << "  ";
		cout << "(4)打印单链表      " << endl;
		cout << "(5)删除结点        " << "  ";
		cout << "(6)清空这个单链表  " << endl;
		cout << "(7)查看链表长度    " << "  ";
		cout << "(8)结束程序        " << endl;
		cout << "(9)查找特定索引值的结点" << endl;
		cout << "请选择:";
		cin >> choose;
		while (choose <= 0 || choose > 9)
		{
			cout << "请选择:";
			cin >> choose;
		}
		switch (choose)
		{
			case 1: {
				if (nohave_head() == false)
					break;
				cout << "插入的整型数值: "; 
				cin >> data; 
				headadd_node(data);
				break;
		}
			case 2: {
				if (nohave_head() == false)
					break;
				cout << "插入的整型数值: ";
				cin >> data;
				tailadd_node(data);
				break;
		}
			case 3: {
				cout << "插入的整型数值: ";
				cin >> data;
				cout << "插入的索引值: ";
				cin >> index;
				insert_node(index, data);
				break;
			}
			case 4: {
				print();
				break;
			}
			case 5: {
				cout << "插入的索引值: ";
				cin >> index;
				delete_node(index);
				break;
			}
			case 6: {
				clear_linkedlist();
				break;
			}
			case 7: {
				search_length();
				break;
			}
			case 8: {
				exit(0);
			}
			case 9:{
				cout << "插入的索引值: ";
				cin >> index;
				search_node(index);
			}
		}
		}
}
int main()
{			
	int head_data;
	cout << "开始前请输入头结点的值:";
	cin >> head_data;
	cin.get();
	LinkedList list(head_data);
	list.menu();

	return 0;
}
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
			cout << "û��head���,��ѡ�񴴽���㡣" << endl;
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

	if (head == nullptr) //���ͷ�ڵ��ǿյ�
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
		cout << "ɾ�����Ϸ���" << endl;
		return 0;
	}

	for (;i < length; p = p->next,i++)
	{
		if (index == 0)
		{
			head = p->next;
			cout << "ɾ����dataΪ" << p->data << "��ֵ��" << endl;
			delete p;
			length--;
			return 1;
		}
		if (i == index)
		{
			pre->next = p->next;
			cout << "ɾ����dataΪ" << p->data << "��ֵ��" << endl;
			delete p;
			length--;
			return 1;
		}
		pre = p;
	}
	cout << "ɾ��ʧ�ܡ�" << endl;
	return 0;
}

int LinkedList::search_node(int index)
{
	node* p = head;
	int i = 0;
	if (index < 0 || index >= length)
	{
		cout << "���Ҳ��Ϸ���" << endl;
		return 0;
	}
	for (; i != index; p = p->next, i++);
	cout << "�ýڵ�Ϊ(" << i << ")" << p->data << endl;
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
		cout << "���벻�Ϸ���" << endl;
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
		cout << "����ĵ��ǰһ��ָ��ָ��Ľڵ�����Ч�ġ�" << endl;
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
	node* p = head; //ָ��ͷ�ڵ㿪ʼ�ͷ�����ָ����ڴ�ռ�
	node* L = p;
	for (int index = 0; index < length; index++)
	{
		L = L->next;
		delete p;
		p = L;
	}
	head = nullptr;
	cout << "��յ��������!" << endl;
	length = 0;
}

void LinkedList::menu()
{
	int choose;
	int data;
	int index;
	while (true)
	{
		cout << "\n------��ӭ�����ܸ絥�������ģ����------" << endl;
		cout << "(1)ͷ�巨          " << "  ";
		cout << "(2)β�巨          " << endl;
		cout << "(3)����ֵ������뷨" << "  ";
		cout << "(4)��ӡ������      " << endl;
		cout << "(5)ɾ�����        " << "  ";
		cout << "(6)������������  " << endl;
		cout << "(7)�鿴������    " << "  ";
		cout << "(8)��������        " << endl;
		cout << "(9)�����ض�����ֵ�Ľ��" << endl;
		cout << "��ѡ��:";
		cin >> choose;
		while (choose <= 0 || choose > 9)
		{
			cout << "��ѡ��:";
			cin >> choose;
		}
		switch (choose)
		{
			case 1: {
				if (nohave_head() == false)
					break;
				cout << "�����������ֵ: "; 
				cin >> data; 
				headadd_node(data);
				break;
		}
			case 2: {
				if (nohave_head() == false)
					break;
				cout << "�����������ֵ: ";
				cin >> data;
				tailadd_node(data);
				break;
		}
			case 3: {
				cout << "�����������ֵ: ";
				cin >> data;
				cout << "���������ֵ: ";
				cin >> index;
				insert_node(index, data);
				break;
			}
			case 4: {
				print();
				break;
			}
			case 5: {
				cout << "���������ֵ: ";
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
				cout << "���������ֵ: ";
				cin >> index;
				search_node(index);
			}
		}
		}
}
int main()
{			
	int head_data;
	cout << "��ʼǰ������ͷ����ֵ:";
	cin >> head_data;
	cin.get();
	LinkedList list(head_data);
	list.menu();

	return 0;
}
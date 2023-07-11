#include <iostream>
using namespace std;
#include <string>
#define N 50

class stu {

public:
	string name;
	string number;
	int score = 0;
	void print(stu(&allperson)[N])
	{
        for(int i = 0;allperson[i].score != 0;i++)
        {
            for(int j = i+1;allperson[j].score != 0;j++)
            {
                if(allperson[i].score < allperson[j].score)
                {
                    stu t = allperson[i];
                    allperson[i] = allperson[j];
                    allperson[j] = t;
                }
            }
        }

		for(int k = 0;allperson[k].score != 0;k++)
        {
            cout << "姓名:" << allperson[k].name << '\t' << "学号:" <<
            allperson[k].number << '\t' << "成绩:" << allperson[k].score << endl;
        }

	}
};

bool number_determine(string number)
{
    string Number_template = "22010502";

    for(int i = 0;i < Number_template.size();i++)
    {
        if(number[i] != Number_template[i])
            return false;
    }

    return true;
}

void number_error(string& number)
{
    cout << "请重新输入学号:";
    cin >> number;
}

void Enter_information(stu(&p)[N])
{
    string name;
	string number;
	int score;
	string result;
    int find_student = 0;
	for(int i = 0;p[i].score != 0;i++)
    ++find_student;

    for (int i = find_student; i < N; i++)
	{
		p[i].score = 0;
	}

	for (int i = find_student; i < N; i++)
	{
		cout << "输入你的成绩录入进去:";
        while (!(cin >> score))
		{
			cout << "输入的数据类型不合法，请重新输入" << endl;
			getchar();
			fflush(stdin);
			cin.clear();
			cin.sync();
		}
        
		while (score < 0 || score > 100)
		{
			cout << "输入你的成绩录入进去:";
			cin >> score;
		}

		p[i].score = score;
		cout << "输入你的学号录入进去:";
		cin >> number;

        while(!number_determine(number))
        {
           number_error(number);
        }

        p[i].number = number;
		cout << "输入你的姓名录入进去:";
		cin >> name;
		p[i].name = name;
		fflush(stdin);
		cout << "--------是否继续录入:是(y)否(n)" << endl;
		cin >> result;

		while(result != "n" && result != "y")
        {  
            cout << "--------是否继续录入:是(y)否(n)";
            cin >> result;
        }
           
        if (result[0] == 'n' && result[1] == '\0')
			break;
	}
}

void View_information(stu(&p)[N])
{
    string search;
    cout << "请输入你要查找的模式:(1)学号查找(2)姓名查找" << endl;

    for(cin >> search;;)
    {
        while(search != "1" && search != "2")
        cin >> search;
        break;
    }
    if(search == "1")
    {
        string search_number;
        bool result = false;
        cout << "请输入你要查找的学号:";
        cin >> search_number;

        for(int i = 0;i < N;i++)
        {
            if(p[i].number == search_number)
            {
                cout << endl << "姓名:" <<  p[i].name << '\t' << "学号:" << p[i].number 
                << '\t' << "成绩:" << p[i].score << endl;  
                result = true;
                break;
            }
        }

        if(result == false)
        {
            cout << "--------------------" << endl;
            cout << "查找不到哦!杰哥这边建议你去添加学生成绩信息~" << endl;
            cout << "--------------------" << endl;
        }
       
    }
    if(search == "2")
    {
        string search_name;
        cout << "请输入你要查找的姓名:";
        cin >> search_name;
        bool result = false;

        for(int i = 0;i < N;i++)
        {
            if(p[i].name == search_name)
            {
                cout << endl << "姓名:" <<  p[i].name << '\t' << "学号:" << p[i].number 
                << '\t' << "成绩:" << p[i].score << endl;  
                result = true;
                break;
            }
        }

        if(result == false)
        {
            cout << "--------------------" << endl;
            cout << "查找不到哦!杰哥这边建议你去添加学生成绩信息~" << endl;
            cout << "--------------------" << endl;
        }
        
    }
}

int main()
{
	stu p[N];
    int search = 0;
    while(true)
    {
        cout << "请问你需要什么操作呢?" << endl;
        cout << "--------添加学生成绩信息(1)" << endl;
        cout << "--------打印学生成绩表(2)" << endl;
        cout << "--------查看学生信息(3)" << endl;
        cout << "--------退出学生信息管理系统(4)" << endl;
       
        while (!(cin >> search))
		{
			cout << "输入的数据类型不合法，请重新输入" << endl;
			getchar();
			fflush(stdin);
			cin.clear();
			cin.sync();
		}
        while(search != 1 && search != 2 && search != 3 && search != 4)
            cin >> search;
        
        switch(search)
        {
            case 1: Enter_information(p); break;
            case 2: p->print(p); break;
            case 3: View_information(p); break;
            case 4: exit(0);
        }
        cout << endl << "--------------------" << endl;
    }
    system("pause");
	return 0;
}
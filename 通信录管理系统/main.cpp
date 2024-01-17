#include <iostream>
using namespace std;

#define max 1000

struct Person
{
    string name;
    string sex;
    int age;
    string telenum;
    string address;
};

struct Addressbooks
{
    struct Person personayy[max];
    int size;
};

void showMenu();
void addPerson(Addressbooks *ads);
void showPerson(Addressbooks *ads);
int isExist(Addressbooks *ads, string name);
void delePerson(Addressbooks *ads);
void findPerson(Addressbooks *ads);
void modifyPerson(Addressbooks *ads);
void cleanPerson(Addressbooks *ads);

int main()
{
    Addressbooks book;
    book.size = 0;
    int select;
    while (true)
    {
        showMenu();
        cout << "请输入功能" << endl;
        cin >> select;
        switch (select)
        {
        case 0:
            cout << "退出通讯录" << endl;
            return 0;
        case 1:
            cout << "添加联系人" << endl;
            addPerson(&book);
            break;
        case 2:
            cout << "显示联系人" << endl;
            showPerson(&book);
            break;
        case 3:
        {
            delePerson(&book);
            break;
        }
        case 4:
            cout << "查找联系人" << endl;
            findPerson(&book);
            break;
        case 5:
            cout << "修改联系人" << endl;
            modifyPerson(&book);
            break;
        case 6:
            cout << "清空联系人" << endl;
            cleanPerson(&book);
            break;
        default:
            cout << "无效输入" << endl;
        }
    }

    showMenu();
}
//显示菜单列表
void showMenu()
{
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
}

//增加联系人
void addPerson(Addressbooks *ads)
{
    if (ads->size == max)
    {
        cout << "通信录已满" << endl;
    }
    else
    {
        cout << "请输入姓名：" << endl;
        cin >> ads->personayy[ads->size].name;
        cout << "请输入性别：" << endl;
        cin >> ads->personayy[ads->size].sex;
        cout << "请输入年龄：" << endl;
        cin >> ads->personayy[ads->size].age;
        cout << "请输入手机号码：" << endl;
        cin >> ads->personayy[ads->size].telenum;
        cout << "请输入住址：" << endl;
        cin >> ads->personayy[ads->size].address;
        ads->size++;
    }
}

//显示通讯录列表
void showPerson(Addressbooks *ads)
{
    if (ads->size == 0)
    {
        cout << "通讯录没有内容" << endl;
    }
    else
    {
        cout << "姓名"
             << "\t"
             << "性别"
             << "\t"
             << "年龄"
             << "\t"
             << "手机号码"
             << "\t"
             << "住址" << endl;
        for (int i = 0; i < ads->size; i++)
        {
            cout << ads->personayy[i].name << "\t";
            cout << ads->personayy[i].sex << "\t";
            cout << ads->personayy[i].age << "\t";
            cout << ads->personayy[i].telenum << "\t\t";
            cout << ads->personayy[i].address << endl;
        }
    }
}

//查找联系人是否存在
int isExist(Addressbooks *ads, string name)
{
    for (int i = 0; i < ads->size; i++)
    {
        if (name == ads->personayy[i].name)
        {
            return i;
        }
    }
    cout << "查无此人" << endl;
    return -1;
}

//删除联系人
void delePerson(Addressbooks *ads)
{
    string name;
    cout << "请输入要删除的名字" << endl;
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1)
    {
        for (ret; ret < ads->size; ret++)
        {
            ads->personayy[ret] = ads->personayy[ret + 1];
        }
        ads->size--;
        cout << "删除成功" << endl;
    }
}

//查找联系人
void findPerson(Addressbooks *ads)
{
    string name;
    cout << "请输入要查找的名字" << endl;
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1)
    {
        cout << "姓名"
             << "\t"
             << "性别"
             << "\t"
             << "年龄"
             << "\t"
             << "手机号码"
             << "\t"
             << "住址" << endl;
        cout << ads->personayy[ret].name << "\t";
        cout << ads->personayy[ret].sex << "\t";
        cout << ads->personayy[ret].age << "\t";
        cout << ads->personayy[ret].telenum << "\t\t";
        cout << ads->personayy[ret].address << endl;
        cout << "查找成功" << endl;
    }
}

//修改联系人
void modifyPerson(Addressbooks *ads)
{
    string name;
    cout << "请输入要修改的名字" << endl;
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1)
    {
        cout << "姓名"
             << "\t"
             << "性别"
             << "\t"
             << "年龄"
             << "\t"
             << "手机号码"
             << "\t"
             << "住址" << endl;
        cout << ads->personayy[ret].name << "\t";
        cout << ads->personayy[ret].sex << "\t";
        cout << ads->personayy[ret].age << "\t";
        cout << ads->personayy[ret].telenum << "\t\t";
        cout << ads->personayy[ret].address << endl;

        cout << "请输入修改后姓名：" << endl;
        cin >> ads->personayy[ret].name;
        cout << "请输入修改后性别：" << endl;
        cin >> ads->personayy[ret].sex;
        cout << "请输入修改后年龄：" << endl;
        cin >> ads->personayy[ret].age;
        cout << "请输入修改后手机号码：" << endl;
        cin >> ads->personayy[ret].telenum;
        cout << "请输入修改后住址：" << endl;
        cin >> ads->personayy[ret].address;
    }
}


//清空联系人
void cleanPerson(Addressbooks *ads){
    ads->size = 0;
    cout << "清空联系人" << endl;
}
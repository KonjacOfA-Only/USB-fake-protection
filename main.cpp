#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <windows.h>
#include <bits/stdc++.h>

/*
	zh_CN:开源许可
		BND工作室拥有开源代码的修改权，其他人可基于源代码进行修改编译，请在welcomepage()中自行署名，注明编译日期以及版本号
		实例：Official-20190929-1949
		Official指官方编译，第三方修改请注明Unofficial
		后面是日期及时间
	en_US:Opensource Lisense
		BND STUDIO have the right of edit this code,others can edit yourself and compile,but please sign in "welcomepage()"
		and have a signal of COMPILE DATE and VERSION
		example:Official-20190929-1949
*/

using namespace std;

int cnt;
char passwd[20],clr[3]; 

void choosepage(); 
void page_4();

void view() {
	system("goto.bat");
} 

void page_1() {
	bool flag=true;
	char password[20];
	cout<<"请输入密码：";
	cin>>password;
	int len1=strlen(passwd),len2=strlen(password);
	if(len1!=len2) {
		cout<<"密码输入错误！"<<endl;
		system("pause");
		system("cls");
		page_1();
	}
	else {
		for(int i=1;i<=len1;i++) {
			if(passwd[i]!=password[i])
				flag=false;
		}
		if(flag) 
			view();
		else {
			cout<<"密码输入错误！"<<endl;
			system("pause");
			system("cls");
			page_1();
		}
	}
}

void repass() {
	ofstream fout("cache/cache.scp");
	system("cls");
	cout<<"请输入修改后的密码：";
	cin>>passwd;
	fout<<"1"<<endl<<passwd; 
	cout<<"密码修改成功，返回主界面?(y/n):";
	char ch;
	cin>>ch;
	if(ch=='y') {
		system("pause");
		system("cls");
		choosepage();
	}
	else if(ch=='n')
		cout<<endl; 
	else {
		cout<<"输入错误！自动返回主界面中"<<endl;
		system("pause");
		system("cls");
		choosepage();
	} 
}

void page_2() {
	bool flag=true;
	char password[20];
	cout<<"请输入密码：";
	cin>>password;
	int len1=strlen(passwd),len2=strlen(password);
	if(len1!=len2) {
		cout<<"密码输入错误！"<<endl;
		system("pause");
		system("cls");
		page_2();
	}
	else {
		for(int i=1;i<=len1;i++) {
			if(passwd[i]!=password[i])
				flag=false;
		}
		if(flag) 
			repass();
		else {
			cout<<"密码输入错误！"<<endl;
			system("pause");
			system("cls");
			page_2();
		}
	}
}

void reset() {
	ofstream fout("cache/cache.scp");
	fout<<"0"<<endl;
	cout<<"重置成功，正在关闭程序"<<endl;
	system("pause");
}

void page_3() {
	bool flag=true;
	char password[20];
	cout<<"请输入密码：";
	cin>>password;
	int len1=strlen(passwd),len2=strlen(password);
	if(len1!=len2) {
		cout<<"密码输入错误！"<<endl;
		system("pause");
		system("cls");
		page_3();
	}
	else {
		for(int i=1;i<=len1;i++) {
			if(passwd[i]!=password[i])
				flag=false;
		}
		if(flag) 
			reset();
		else {
			cout<<"密码输入错误！"<<endl;
			system("pause");
			system("cls");
			page_3();
		}
	}
}

void choosepage() {
	cout<<"1.浏览被加密的个人文件夹"<<endl; 
	cout<<"2.修改加密文件夹密码"<<endl;
	cout<<"3.重置软件设置"<<endl;
	cout<<"4.修改颜色"<<endl; 
	cout<<"输入选项(必须输入整数，否则产生bug概不负责)：";
	char choice;
	cin>>choice; 
	if(choice=='1') {
		system("cls");
		page_1();
	} else if(choice=='2') {
		system("cls");
		page_2();
	} else if(choice=='3') {
		system("cls");
		page_3();
	} else if(choice=='4') {
		system("cls");
		page_4();
	} else {
		cout<<"选项输入错误，请重新输入选项"<<endl;
		system("pause");
		system("cls");
		choosepage();
	} 
}

void preuse() {
	ofstream fout("cache/cache.scp");
	cout<<"在U盘根目录新建两个文件夹，改名\'protected\'和\'cache\'，在/cache里新建文本文档cache.scp，内容为0，隐藏这两个文件夹（不要隐藏子目录及子目录里文件"<<endl;
	cout<<"将DDF-Usb protection全部复制入根目录，隐藏批处理文件"<<endl;
	cout<<"全部完成后";
	system("pause");
	cout<<endl<<"设置密码：";
	cin>>passwd;
	fout<<"1"<<endl<<passwd<<endl<<"3f"; 
	system("cls");
} 

void check() {	
	ifstream fin("cache/cache.scp");
	fin>>cnt;
	if(cnt==0) 
		preuse();
	else {
		fin>>passwd;
		fin>>clr;
	}
}

void welcomepage() {
	cout<<endl<<endl<<endl;
	cout<<"                          USB保护程序 v1.1.1              "<<endl;
	cout<<"                    编译时间:Official-20190929-2100       "<<endl;
	cout<<"                  编译人:A-Only的小蒟蒻(源代码贡献者)     "<<endl;
	cout<<endl;
	cout<<"              BND-STUDIO project-DDF 项目:USB-protection  "<<endl;
	cout<<"                      项目发起人:A-Only的小蒟蒻           "<<endl;
	system("pause");
	system("cls"); 
} 

void page_4() {
	cout<<"修改颜色请参照以下颜色代码"<<endl;
	system("color 12a");
	cout<<"请输入颜色代码：";
	cin>>clr;
	ofstream fout("cache/cache.scp");
	fout<<"1"<<endl<<passwd<<endl<<clr; 
}

void defultcolor() {
	system("color 3f");
}

int main(int argc, char** argv) {
	char cmd[]="color ";
	defultcolor();  
	check();
	system(strcat(cmd,clr));
	welcomepage();
	choosepage();
	return 0;
}

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <windows.h>
#include <bits/stdc++.h>

/*
	zh_CN:��Դ���
		BND������ӵ�п�Դ������޸�Ȩ�������˿ɻ���Դ��������޸ı��룬����welcomepage()������������ע�����������Լ��汾��
		ʵ����Official-20190929-1949
		Officialָ�ٷ����룬�������޸���ע��Unofficial
		���������ڼ�ʱ��
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
	cout<<"���������룺";
	cin>>password;
	int len1=strlen(passwd),len2=strlen(password);
	if(len1!=len2) {
		cout<<"�����������"<<endl;
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
			cout<<"�����������"<<endl;
			system("pause");
			system("cls");
			page_1();
		}
	}
}

void repass() {
	ofstream fout("cache/cache.scp");
	system("cls");
	cout<<"�������޸ĺ�����룺";
	cin>>passwd;
	fout<<"1"<<endl<<passwd; 
	cout<<"�����޸ĳɹ�������������?(y/n):";
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
		cout<<"��������Զ�������������"<<endl;
		system("pause");
		system("cls");
		choosepage();
	} 
}

void page_2() {
	bool flag=true;
	char password[20];
	cout<<"���������룺";
	cin>>password;
	int len1=strlen(passwd),len2=strlen(password);
	if(len1!=len2) {
		cout<<"�����������"<<endl;
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
			cout<<"�����������"<<endl;
			system("pause");
			system("cls");
			page_2();
		}
	}
}

void reset() {
	ofstream fout("cache/cache.scp");
	fout<<"0"<<endl;
	cout<<"���óɹ������ڹرճ���"<<endl;
	system("pause");
}

void page_3() {
	bool flag=true;
	char password[20];
	cout<<"���������룺";
	cin>>password;
	int len1=strlen(passwd),len2=strlen(password);
	if(len1!=len2) {
		cout<<"�����������"<<endl;
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
			cout<<"�����������"<<endl;
			system("pause");
			system("cls");
			page_3();
		}
	}
}

void choosepage() {
	cout<<"1.��������ܵĸ����ļ���"<<endl; 
	cout<<"2.�޸ļ����ļ�������"<<endl;
	cout<<"3.�����������"<<endl;
	cout<<"4.�޸���ɫ"<<endl; 
	cout<<"����ѡ��(���������������������bug�Ų�����)��";
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
		cout<<"ѡ�������������������ѡ��"<<endl;
		system("pause");
		system("cls");
		choosepage();
	} 
}

void preuse() {
	ofstream fout("cache/cache.scp");
	cout<<"��U�̸�Ŀ¼�½������ļ��У�����\'protected\'��\'cache\'����/cache���½��ı��ĵ�cache.scp������Ϊ0�������������ļ��У���Ҫ������Ŀ¼����Ŀ¼���ļ�"<<endl;
	cout<<"��DDF-Usb protectionȫ���������Ŀ¼�������������ļ�"<<endl;
	cout<<"ȫ����ɺ�";
	system("pause");
	cout<<endl<<"�������룺";
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
	cout<<"                          USB�������� v1.1.1              "<<endl;
	cout<<"                    ����ʱ��:Official-20190929-2100       "<<endl;
	cout<<"                  ������:A-Only��С�X�m(Դ���빱����)     "<<endl;
	cout<<endl;
	cout<<"              BND-STUDIO project-DDF ��Ŀ:USB-protection  "<<endl;
	cout<<"                      ��Ŀ������:A-Only��С�X�m           "<<endl;
	system("pause");
	system("cls"); 
} 

void page_4() {
	cout<<"�޸���ɫ�����������ɫ����"<<endl;
	system("color 12a");
	cout<<"��������ɫ���룺";
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

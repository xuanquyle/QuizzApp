#include<iostream>
#include"Question.h"
#include "Person.h"
#include<fstream>
#include<string>
#include<string.h>
#include "Contestants.h"
#include<list>
#include <ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;   
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void SetList( list <Question> &l,string FileName)
{
	ifstream f(FileName);
	string a[5];
	int i=0;
	while(getline(f,a[i]))
	{
		if(i!=4)
			i++;
		else
		{
			Question q(a[0],a[1],a[2], a[3],a[4]);
			l.push_back(q);
			i=0;
		}
	}
	f.close();
}
int check(list<Question> &l,string a[])
{
	int i=0,temp=0,score=0;
	list <Question>::iterator p=l.begin();
	while(p!=l.end())
	{
		string c=p->getTrue_AS();
		if(a[i]==c)
			score++;
		i++;
		p++;
	}
	return score;
}
bool check(string a[])
{
	for(int i=0;i<5;i++)
		if(a[i]=="0")
			return false;
	return true;
}
void reTest(list<Question> &l, int t,string a[]) 
{
	list <Question>::iterator p=l.begin();
	int temp=0;
	while (temp!=t-1)
	{
		p++;
		temp++;
	}
	cout<<temp+1<<". "<<*p;
	string u;
	do{
		cout<<"Nhap dap an: ";cin>>u;	
	}
	while( u <"a" || u >"c");
	a[temp]=u;
}
void answer(string a[])
{
	cout<<"Dap an cua ban "<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"Cau "<<i+1;

		if(a[i]=="0")
			cout<<" Chua tra loi"<<endl;
		else cout<<" "<<a[i]<<endl;
	}
}
int backTime(time_t t)
{
	
	if(50-((clock()-t)/1000)>0)
	{
			gotoxy(40,2);
			cout<<"| Thoi gian con "<<50-((clock()-t)/1000)<<" giay |"<<endl ;
			gotoxy(40,3);
			cout<<"-------------------------\n";
	}
	else 
	{
		gotoxy(40,2);
		cout<<"|	Da het gio	|";
		gotoxy(40,3);
		cout<<"--------------------------\n";
		Sleep(200);
		exit;
	}
	return 50-((clock()-t)/1000);
}
void Test( list <Question> &l, string a[])
{
	time_t t=clock();
	for(int i=0;i<5;i++)
		a[i]="0";
	list <Question>::iterator p=l.begin();
	int i=0;
	//while(!check(a))
	//{
		while(p!=l.end())
		{
			system("cls");
			if(backTime(t)<0)
				return;
			
			if(a[i]=="0")
			{
				cout<<i+1<<". "<<*p;
				string b1 ,b2;
				do
				{
					cout<<" Nhap vao Dap an OR Skip S ";
					cin>>b1;
				}
				while((b1!="a"&&b1!="b"&&b1!="c")&&b1!="S");
				if((b1 >="a" || b1<="c")&&b1!="S")
					a[i]=b1;	
				
			}
				i++;
				p++;	
		}
	//	i=0;
	//	p=l.begin();
	//}
	int rt=1;
	
	while(rt!=0)
	{
		system("cls");
		if(backTime(t)<0)
			return;
			answer(a);
			char c;
			cout<<"Nhap vao cau muon sua 1->5 OR Ket thuc 0: ";
			cin>>c;
			system("cls");
			if(backTime(t)<0)
			return;
			if((c>='1'&&c<='5')||c=='0')
			{
				rt=c-'0';
				if(rt>=1&& rt<=5)
					reTest(l,rt,a);
				if(rt==0)
					break;
			}
	}
	system("cls");
}
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
int main()
{
	textcolor(6);
	list<Question> l;
	Contestants c;
	cout<<" =====================Welcome to Quick Test============================\n ";
	cout<<" Join Press 1 - Exit press anyKey "<<endl;
	int join;
	cin>>join;
	cin.ignore();
	if(join==1)
	{
		string id, name;
		while(id==""||name=="")
		{
			
			cout<<"Nhap ID: ";getline(cin,id);
			cout<<"Nhap Name: ";getline(cin,name);
		}
		string s="SET";
		s=s+(char)(c.getKey()+48)+".txt";
		SetList(l,s);
		cout<<"\nExam paper code: "<<c.getKey()<<endl;
		cout<<"Ready Start.";
		for(int i=0;i<10;i++)
		{
			cout<<".";
			Sleep(150);
		}
		string a[5];
		time_t bg= clock();
		time_t start= time(0);
		Test(l,a);
		time_t end= clock();
		tm *begin= localtime(&start);
		time_t used=(end-bg)/1000;
		c.setCon(id, name,check(l,a));
		textcolor(5);
		cout<<"\n--------------------------------------------\n";
		cout<<c;
		cout<<"Ngay du thi: "<<asctime(begin);
		cout<<"Tong thoi gian: "<<(used<50?used:50)<<" giay"<<endl;
		c.inText();
	}
}
/* Thành viên nhóm:
1. Võ Hải Tuyên				1951120146
2. Lê Xuân Quý				1951120131
3. Tô Thị Thanh Tâm			1951120136
4. Nguyễn Tuấn Khanh		1951120101
5. Diệp Thế Vương Huy		1951120097
****************************************************
<> Điểm Nổi Bật:
- Lựa chọn đề thi ngẫu nhiên đã đc lưu trữ trước đó cho từng người tham gia
- Có giới hạn thời gian làm bài thi. Nếu hết giờ chương trình sẽ không cho phép tiếp tục làm bài
- Lưu kết quả thi của từng người theo từng đề vào các file kết quả cho đề tương ứng
- Đưa ra xếp hạng của người thi đối với những người thi trước
- Các hàm được tối ưu để có thể tái sử dụng lại
<> Hạn Chế
- Không nhiều chức năng 
- Có những ý tưởng chưa đưa vào bài làm: Lấy dữ liệu Person từ 1 file dữ liệu lớn (Vd như trường học,..), nếu không có dữ liệu không cho phép làm bài (dạng đăng nhập); 

*/

		#include<iostream>
        #include<fstream>
		#include<stdlib>
		#include<string>
		fstream f1,f2;
		class generid
		{
			public:
			int suid;
			int bid;
		}master;
		class student
		{
			public:
			int sid;
			char stuname[30];
			void studentdetails();
		}st;
		class book
		{
			public:
			int bokid;
			char bkname[30];
			char authname[30];
			int bokissue;
			void bookdetails();
			void bookissue();
			void bookdepo();
		}bk;
		void addst()
		{
			f1.open("student.txt",ios::out|ios::app);
			f2.open("mastercode.txt",ios::binary|ios::app);
			char ch;
			do
			{
				clrscr();
				st.sid=master.suid;
				cout<<"Please enter student id "<<endl;
				cout<<st.sid+1<<endl;
				master.suid++;
				f2.write((char *)&st,sizeof(st));
				cout<<"Please enter student name "<<endl;
				gets(st.stuname);
				f1.write((char*)&st,sizeof(st));
				cout<<"do you want to add more record..(y/n?)"<<endl;
				cin>>ch;
			}while(ch=='y'||ch=='Y');
			f2.close();
			f1.close();
		}
		void dispallstudent()
		{
			clrscr();
			f1.open("student.txt",ios::in);
			if(!f1)
			{
				cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
				getch();
				return;
			}
			cout<<"==========================================================================="<<endl;
			cout<<setw(12)<<"STUDENT ID"<<setw(30)<<"STUDENT NAME  "<<endl;
			cout<<"==========================================================================="<<endl;
			while(f1.read((char*)&st,sizeof(student)))
			{
				cout<<setw(3)<<st.sid+1<<setw(30)<<st.stuname<<endl;
			}
			f1.close();
			getch();
		}
		void dispspecstud()
		{
			clrscr();
			cout<<"\nSTUDENT DETAILS\n";
			int flag=0;
			int s=0;
			cout<<"Enter student id you want to view the details "<<endl;
			cin>>s;
			f1.open("student.txt",ios::in);
			while(f1.read((char*)&st,sizeof(st)))
			{
				if(s==(st.sid+1))
				{
					cout<<"==========================================================================="<<endl;
					cout<<setw(12)<<"STUDENT ID"<<setw(30)<<"STUDENT NAME  "<<endl;
					cout<<"==========================================================================="<<endl;
					cout<<setw(3)<<st.sid+1<<setw(30)<<st.stuname<<endl;
					flag=1;
				}
			}
			f1.close();
			if(flag==0)
				cout<<"\n\nStudent does not exist";
			getch();
		}
		void modifstud()
		{
			int found=0;
			f1.open("student.txt",ios::in);
			f2.open("temp.txt",ios::out);
			char namest[30];
			gotoxy(16,18);cout<<"Please enter student name you want to modify"<<endl;
			gotoxy(16,19);gets(namest);
			while(f1.read((char *)&st,sizeof(st)))
			{
				if(strcmp(st.stuname,namest)==0)
				{
					gotoxy(16,20);cout<<"Enter new student name "<<endl;
					gotoxy(16,21);gets(st.stuname);
					gotoxy(16,22);cout<<"ID of new student is "<<st.sid+1<<endl;
					gotoxy(16,24);cout<<" Record Updated"<<endl;
					found=1;
				}
				f2.write((char*)&st,sizeof(st));
			}
			if(found==0)
			{
				gotoxy(16,20);cout<<"Student record not found "<<endl;
			}
			f1.close();
			f2.close();
			remove("student.txt");
			rename("temp.txt","student.txt");
			getch();
		}
		void delstud()
		{
			int idst=0;
			f1.open("student.txt",ios::in);
			f2.open("tempo.txt",ios::out);
			gotoxy(16,18);cout<<"Please enter student id for which record is to be deleted "<<endl;
			gotoxy(16,19);cin>>idst;
			while(f1.read((char*)&st,sizeof(st)))
			{
				if((st.sid+1)!=idst)
				{
					f2.write((char *)&st,sizeof(st));
				}
			}
			f1.close();
			f2.close();
			remove("student.txt");
			rename("tempo.txt","student.txt");
			getch();
		}
		void addbook()
		{
			char ch;
			f1.open("book.txt",ios::app|ios::out);
			f2.open("mastercode.txt",ios::binary|ios::app);
			do
			{
				clrscr();
				bk.bokid=master.bid;
				cout<<"Please enter book id "<<endl;
				cout<<bk.bokid+1<<endl;
				master.bid++;
				f2.write((char *)&bk,sizeof(bk));
				f2.close();
				cout<<"Please enter book name "<<endl;
				gets(bk.bkname);
				cout<<"Please enter author name "<<endl;
				gets(bk.authname);
				f1.write((char*)&bk,sizeof(bk));
				cout<<"\n\nDo you want to add more record..(y/n?)";
				cin>>ch;
			}while(ch=='y'||ch=='Y');
			f2.close();
			f1.close();
		}
		void dispallbook()
		{
			clrscr();
			f1.open("book.txt",ios::in);
			if(!f1)
			{
				cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
				getch();
				return;
			}
			cout<<"=============================================================="<<endl;
			cout<<setw(11)<<"BOOK ID"<<setw(20)<<"BOOK NAME  "<<setw(20)<<" AUTHOR NAME "<<endl;
			cout<<"=============================================================="<<endl;
			while(f1.read((char*)&bk,sizeof(bk)))
			{
				cout<<setw(5)<<bk.bokid+1<<setw(27)<<bk.bkname<<setw(16)<<bk.authname<<endl;
			}
			f1.close();
			getch();
		}
		void dispspecbook()
		{
			clrscr();
			cout<<"\nBOOK DETAILS\n";
			int flag=0,i=0;
			f1.open("book.txt",ios::in);
			cout<<"Enter book id you want to get the details "<<endl;
			cin>>i;
			while(f1.read((char*)&bk,sizeof(bk)))
			{
				if(i==(bk.bokid+1))
				{
					cout<<"=============================================================="<<endl;
					cout<<setw(11)<<"BOOK ID"<<setw(20)<<"BOOK NAME  "<<setw(20)<<" AUTHOR NAME "<<endl;
					cout<<"=============================================================="<<endl;
					cout<<setw(5)<<bk.bokid+1<<setw(27)<<bk.bkname<<setw(16)<<bk.authname<<endl;
					flag=1;
				}
			}
			f1.close();
			if(flag==0)
				cout<<"\n\nBook does not exist";
			getch();
		}
		void modifybook()
		{
			f1.open("book.txt",ios::in);
			f2.open("tempt.txt",ios::out);
			char namebk[30];
			gotoxy(16,18);cout<<"Please enter book name you want to modify"<<endl;
			gotoxy(16,19);gets(namebk);
			while(f1.read((char *)&bk,sizeof(bk)))
			{
				if(strcmp(bk.bkname,namebk)==0)
				{
					gotoxy(16,20);cout<<"Enter new book name "<<endl;
					gotoxy(16,21);gets(bk.bkname);
					gotoxy(16,22);cout<<"Enter new author name "<<endl;
					gotoxy(16,23);gets(bk.authname);
					gotoxy(16,24);cout<<"ID of new book is "<<bk.bokid+1<<endl;
				}
				f2.write((char*)&bk,sizeof(bk));
			}
			f1.close();
			f2.close();
			remove("book.txt");
			rename("tempt.txt","book.txt");
			getch();
		}
		void delbook()
		{
			f1.open("book.txt",ios::in);
			f2.open("tempor.txt",ios::out);
			int idbook=0;
			gotoxy(16,18);cout<<"Please enter book id for which record is to be deleted "<<endl;
			gotoxy(16,19);cin>>idbook;
			while(f1.read((char*)&bk,sizeof(bk)))
			{
				if((bk.bokid+1)!=idbook)
				{
					f2.write((char*)&bk,sizeof(bk));
				}
			}
			f1.close();
			f2.close();
			remove("book.txt");
			rename("tempor.txt","book.txt");
			getch();
		}
		void student::studentdetails()
		{
			int f=0;
			while(1)
			{
				clrscr();
				gotoxy(16,1);cout<<"--------------STUDENT MENU---------------"<<endl;
				gotoxy(16,2);cout<<"1. Add student details "<<endl;
				gotoxy(16,4);cout<<"2. Display all student details "<<endl;
				gotoxy(16,6);cout<<"3. Display specific student details "<<endl;
				gotoxy(16,8);cout<<"4. Modify student details "<<endl;
				gotoxy(16,10);cout<<"5. Delete student details"<<endl;
				gotoxy(16,12);cout<<"6. Return to back menu "<<endl;
				gotoxy(16,14);cout<<"7. Exit "<<endl;
				gotoxy(16,15);cout<<"----------------------------------------"<<endl;
				gotoxy(16,16);cout<<"Please select your choice   ";
				cin>>f;
				switch(f)
				{
					case 1: addst();break;
					case 2: dispallstudent();break;
					case 3: dispspecstud();break;
					case 4: modifstud();break;
					case 5: delstud();break;
					case 6: return;
					case 7: exit(0);
					default: cout<<"Error.Please enter appropriate choice "<<endl;
				}
			}
		}
		void book::bookdetails()
		{
			int d=0;
			while(1)
			{
				clrscr();
				gotoxy(16,1);cout<<"--------------BOOK MENU---------------"<<endl;
				gotoxy(16,2);cout<<"1. Add book details "<<endl;
				gotoxy(16,4);cout<<"2. Display all book details "<<endl;
				gotoxy(16,6);cout<<"3. Display specific book details "<<endl;
				gotoxy(16,8);cout<<"4. Modify book details "<<endl;
				gotoxy(16,10);cout<<"5. Delete book details"<<endl;
				gotoxy(16,12);cout<<"6. Return to back menu "<<endl;
				gotoxy(16,14);cout<<"7. Exit "<<endl;
				gotoxy(16,15);cout<<"----------------------------------------"<<endl;
				gotoxy(16,16);cout<<"Please select your choice   ";
				cin>>d;
				switch(d)
				{
					case 1: addbook();break;
					case 2: dispallbook();break;
					case 3: dispspecbook();break;
					case 4: modifybook();break;
					case 5: delbook();break;
					case 6: return;
					case 7: exit(0);
					default: cout<<"Error.Please enter appropriate choice "<<endl;
				}
			}
		}
		void book::bookissue()
		{
			f1.open("student.txt",ios::in|ios::out);
			f2.open("book.txt",ios::in|ios::out);
			int bisid=0;
			int sisid=0;
			int flag=0;
			int found=0;
			bk.bokissue=0;
			gotoxy(16,14);
			cout<<"Note : You can take only one book at a time "<<endl;
			gotoxy(16,15);cout<<"Please enter student id "<<endl;
			gotoxy(16,16);cin>>sisid;
			while(f1.read((char*)&st,sizeof(st)))
			{
				if(sisid==(st.sid+1))
				{
					found=1;
					if(bk.bokissue==0)
					{
						gotoxy(16,17);cout<<"PLease enter book id "<<endl;
						gotoxy(16,18);cin>>bisid;
						while(f2.read((char *)&bk,sizeof(bk)))
						{
							if(bisid==(bk.bokid+1))
							{
								flag=1;
								bk.bokissue=1;
								cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date"
								"in backside of book and submit within 15 days fine Rs. 2 for each day"
								   " after 7 days period";
							}
						}
						if(flag==0)
						{
							cout<<"Book does not exist "<<endl;
						}
					}
					else
					{
						cout<<"Book not returned "<<endl;
					}
				}
			}
			if(found==0)
			{
				cout<<"Student record not exist "<<endl;
			}
			f1.close();
			f2.close();
			getch();
		}
		void book::bookdepo()
		{
			int ss=0,bb=0;
			int found=0,flag=0;
			int day;
			int fine;
			bk.bokissue=1;
			clrscr();
			cout<<"\n\nBOOK DEPOSIT ...";
			cout<<"\n\n\tEnter The student's id ";
			cin>>ss;
			f1.open("student.txt",ios::in);
			f2.open("book.txt",ios::in);
			while(f1.read((char*)&st,sizeof(st)))
			{
				if(ss==(st.sid+1))
				{
					found=1;
					if(bk.bokissue==1)
					{
					while(f2.read((char*)&bk,sizeof(bk)))
					{
						flag=1;
						cout<<"\n\n\t Enter book id ";
						cin>>bb;
						  if(bb==(bk.bokid+1))
						  {
							cout<<"\n\nBook deposited in no. of days  :";
							cin>>day;
							if(day>7)
							{
								fine=(day-7)*2;
								cout<<"\n\nFine has to deposited Rs. "<<fine;
							}
							cout<<"\n\n\t Book deposited successfully";
						break;
						  }
					}
					}
				}
			   }
			   getch();
		  f1.close();
		  f2.close();
		}
		void intro()
		{
			clrscr();
			cout<<endl<<endl<<endl;
			cout<<"\t\tLIBRARY MANANEMENT SYSTEM "<<endl;
			cout<<endl<<endl<<endl;
			cout<<"\t\tMADE BY: ";
			cout<<"SAGAR PATEL, YESHA PATEL, NISHANK SHAH, MISHIT SHAH "<<endl;
			cout<<endl;
			cout<<"\t\tCHARUSAT UNIVERSITY OF SCIENCE AND TECHNOLOGY\n";
			cout<<"\t\tCSPIT EC\n";
			getch();
		}
		void main()
		{
			clrscr();
			int a;
			intro();
			while(1)
			{
				clrscr();
				gotoxy(16,1);cout<<"----------MAIN MENU----------"<<endl;
				gotoxy(16,2);cout<<"1 : Student details "<<endl;
				gotoxy(16,4);cout<<"2 : Book details "<<endl;
				gotoxy(16,6);cout<<"3 : Book issue "<<endl;
				gotoxy(16,8);cout<<"4 : Book deposit "<<endl;
				gotoxy(16,10);cout<<"5 : Exit "<<endl;
				gotoxy(16,11);cout<<"-----------------------------"<<endl;
				gotoxy(16,12);cout<<"Please enter your choice   ";
				cin>>a;
				switch(a)
				{
					case 1:  st.studentdetails();break;
					case 2:  bk.bookdetails();break;
					case 3:  bk.bookissue();break;
					case 4:  bk.bookdepo();break;
					case 5:  exit(0);
					default: cout <<"Error.Pls enter proper choice "<<endl;
				}
				getch();
			}
		}

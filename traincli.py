import os
from tkinter import *
import re
import numpy as np

root=Tk()
root.title('列车管理系统')
root.geometry('480x360')
trainlist =[]
s= ''

class Train:
    def __init__(self):
        self.forname = ''
        self.ID =''
        self.lastname = ''
        self.time = 0.0
        self.price = 0
        self.seating = 0

def Init(tralist):
    print ("初始化......")
    file_object = open('train.txt', 'r')
    for line in file_object:
        tra = Train()
        line = line.strip("\n")
        s = line.split(" ")
        tra.ID = s[0]
        tra.forname = s[1]
        tra.lastname = s[2]
        tra.time = s[3]
        tra.price = s[4]
        tra.seating = s[5]
        tralist.append(tra)
    file_object.close()
    print ("初始化成功！")

class ADD:
    def Add_f(self):
        roob = Toplevel(root)
        roob.title('列车信息输入')
        roob.geometry('480x360')

        lb1 = Label(roob, text='车次',bg='#C0C0C0',fg = "black")
        lb1.place(relx=0.2, rely=0.1, relwidth=0.3, relheight=0.1)
        a_text = StringVar()
        a_text.set("")
        self.inp1 = Entry(roob, textvariable=a_text)
        self.inp1.place(relx=0.55, rely=0.1, relwidth=0.35, relheight=0.1)

        lb2 = Label(roob, text='起点',bg='#C0C0C0',fg = "black")
        lb2.place(relx=0.2, rely=0.2, relwidth=0.3, relheight=0.1)
        b_text = StringVar()
        b_text.set("")
        self.inp2 = Entry(roob, textvariable=b_text)
        self.inp2.place(relx=0.55, rely=0.2, relwidth=0.35, relheight=0.1)

        lb3 = Label(roob, text='终点',bg='#C0C0C0',fg = "black")
        lb3.place(relx=0.2, rely=0.3, relwidth=0.3, relheight=0.1)
        c_text = StringVar()
        c_text.set("")
        self.inp3 = Entry(roob, textvariable=c_text)
        self.inp3.place(relx=0.55, rely=0.3, relwidth=0.35, relheight=0.1)

        lb4 = Label(roob, text='时间',bg='#C0C0C0',fg = "black")
        lb4.place(relx=0.2, rely=0.4, relwidth=0.3, relheight=0.1)
        d_text = StringVar()
        d_text.set("")
        self.inp4 = Entry(roob, textvariable=d_text)
        self.inp4.place(relx=0.55, rely=0.4, relwidth=0.35, relheight=0.1)

        lb5 = Label(roob, text='票价',bg='#C0C0C0',fg = "black")
        lb5.place(relx=0.2, rely=0.5, relwidth=0.3, relheight=0.1)
        e_text = StringVar()
        e_text.set("")
        self.inp5 = Entry(roob, textvariable=e_text)
        self.inp5.place(relx=0.55, rely=0.5, relwidth=0.35, relheight=0.1)

        lb6 = Label(roob, text='座位数',bg='#C0C0C0',fg = "black")
        lb6.place(relx=0.2, rely=0.6, relwidth=0.3, relheight=0.1)
        f_text = StringVar()
        f_text.set("")
        self.inp6 = Entry(roob, textvariable=f_text)
        self.inp6.place(relx=0.55, rely=0.6, relwidth=0.35, relheight=0.1)

        self.bt = Button(roob, text="添加", command=lambda: self.Add(a_text, b_text, c_text, d_text, e_text, f_text))
        self.bt.place(relx=0.4, rely=0.75, relwidth=0.2, relheight=0.1)

        self.btClose = Button(roob, text='关闭', command=roob.destroy)
        self.btClose.place(relx=0.4, rely=0.85, relwidth=0.2, relheight=0.1)

        self.txt = Text(roob)
        #self.txt.place(relx=0.1, rely=0.8, relwidth=0.4, relheight=0.1)

    def Delete(self):
        self.inp1.delete(0, END)
        self.inp2.delete(0, END)
        self.inp3.delete(0, END)
        self.inp4.delete(0, END)
        self.inp5.delete(0, END)
        self.inp6.delete(0, END)

    def Add(self, ID, forname, lastname, time, price, seating):
        tra = Train()
        tra.ID = str(ID.get())
        tra.forname = str(forname.get())
        tra.lastname = str(lastname.get())
        tra.time = str(time.get())
        tra.price = str(price.get())
        tra.seating = str(seating.get())
        print(tra.ID, tra.forname, tra.lastname, tra.time, tra.price, tra.seating)
        if self.searchByID(trainlist, tra.ID) == True:
            self.txt.delete(1.0, END)
            self.txt.insert(END, '车次重复,保存失败')
            return
        trainlist.append(tra)
        file_object = open("train.txt", "a")
        file_object.write(tra.ID)
        file_object.write(" ")
        file_object.write(tra.forname)
        file_object.write(" ")
        file_object.write(tra.lastname)
        file_object.write(" ")
        file_object.write(tra.time)
        file_object.write(" ")
        file_object.write(tra.price)
        file_object.write(" ")
        file_object.write(tra.seating)
        file_object.write("\n")
        file_object.close()
        self.txt.delete(1.0, END)
        self.txt.insert(END, '保存成功')

        return

    def searchByID(self, tralist, ID):
        for item in tralist:
            if item.ID == ID:
                return True
        return False

class DEL():
    def Del_f(self):
        roob = Toplevel(root)
        roob.title('列车信息删除')
        roob.geometry('480x360')

        lb4 = Label(roob, text='车次',bg='#C0C0C0',fg = "black")
        lb4.place(relx=0.2, rely=0.25, relwidth=0.2, relheight=0.1)
        d_text = StringVar()
        d_text.set("")
        self.inp4 = Entry(roob, textvariable=d_text)
        self.inp4.place(relx=0.45, rely=0.25, relwidth=0.25, relheight=0.1)

        self.bt = Button(roob, text="确定",bg='#C0C0C0',fg = "black",command=self.Del)
        self.bt.place(relx=0.75, rely=0.75, relwidth=0.15, relheight=0.1)

        self.txt = Text(roob)

    def searchByID(self, tralist, ID):
        for item in tralist:
            if item.ID == ID:
                return True
        return False

    def Del(self):
        ID = self.inp4.get()
        if self.searchByID(trainlist, ID) == False:
            self.txt.delete(1.0, END)
            self.txt.insert(END, '没有该列车信息！')
            self.inp4.delete(0, END)
            return

        for item in trainlist:
            if item.ID == ID:
                trainlist.remove(item)
                self.txt.delete(1.0, END)
                self.txt.insert(END, '删除成功！')
                self.inp4.delete(0, END)
                break

        file_object = open("train.txt", "w")
        for tra in trainlist:
            file_object.write(tra.ID)
            file_object.write(" ")
            file_object.write(tra.forname)
            file_object.write(" ")
            file_object.write(tra.lastname)
            file_object.write(" ")
            file_object.write(str(tra.time))
            file_object.write(" ")
            file_object.write(str(tra.price))
            file_object.write(" ")
            file_object.write(str(tra.seating))
            file_object.write("\n")
        file_object.close()

class Remove():
    def Search_f(self):
        roob=Toplevel(root)
        roob.title('列车信息查询')
        roob.geometry('480x360')

        lb4 = Label(roob, text='车次',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb4.place(relx=0.2, rely=0.1, relwidth=0.2, relheight=0.1)
        d_text=StringVar()
        d_text.set("")
        self.inp4 = Entry(roob,textvariable =d_text)
        self.inp4.place(relx=0.45, rely=0.1, relwidth=0.25, relheight=0.1)

        self.bt=Button(roob,text="查询",command=self.Search)
        self.bt.place(relx=0.65, rely=0.7, relwidth=0.25, relheight=0.1)
        
        self.txt = Text(roob)
        self.txt.place(relx=0.0, rely=0.4, relwidth=1, relheight=0.15)

    def Search(self):
        ID=self.inp4.get()
        if self.searchByID(trainlist, ID) == False:
            self.txt.delete(1.0,END)
            self.txt.insert(END,'没有该列车信息！' )
            self.inp4.delete(0, END)
            return
        
        self.txt.delete(1.0,END)
        self.txt.insert(END,"{0:^5}\t{1:{6}^5}\t{2:{6}^5}\t{3:{6}^6}\t{4:{6}^6}\t{5:{6}^6}".format("车次","起点","终点","时间","票价","座位",chr(12288)))
        for item in trainlist:
            if item.ID == ID:
                self.txt.insert(END,"{0:^6}\t{1:{6}^5}\t{2:{6}^5}\t{3:{6}^7}\t{4:{6}^8}\t{5:{6}^7}".format(item.ID,item.forname,item.lastname,item.time,item.price,item.seating,chr(12288)))
                self.inp4.delete(0, END)
                break

    def searchByID(self,tralist,ID):
        for item in tralist:
            if item.ID == ID:
                return True
        return False

class Tsearch():
    def Change_f(self):
        roob=Toplevel(root)
        roob.title('修改')
        roob.geometry('480x360')

        lb1 = Label(roob, text='车次',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb1.place(relx=0.25, rely=0.1, relwidth=0.2, relheight=0.1)
        a_text=StringVar()
        a_text.set("")
        self.inp1 = Entry(roob,textvariable =a_text)
        self.inp1.place(relx=0.5, rely=0.1, relwidth=0.3, relheight=0.1)
            
        lb2 = Label(roob, text='起点',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb2.place(relx=0.25, rely=0.2, relwidth=0.2, relheight=0.1)
        b_text=StringVar()
        b_text.set("")
        self.inp2 = Entry(roob,textvariable =b_text)
        self.inp2.place(relx=0.5, rely=0.2, relwidth=0.3, relheight=0.1)
        
        lb3 = Label(roob, text='终点',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb3.place(relx=0.25, rely=0.3, relwidth=0.2, relheight=0.1)
        c_text=StringVar()
        c_text.set("")
        self.inp3 = Entry(roob,textvariable =c_text)
        self.inp3.place(relx=0.5, rely=0.3, relwidth=0.3, relheight=0.1)
          
        lb4 = Label(roob, text='时间',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb4.place(relx=0.25, rely=0.4, relwidth=0.2, relheight=0.1)
        d_text=StringVar()
        d_text.set("")
        self.inp4 = Entry(roob,textvariable =d_text)
        self.inp4.place(relx=0.5, rely=0.4, relwidth=0.3, relheight=0.1)
           
        lb5 = Label(roob, text='票价',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb5.place(relx=0.25, rely=0.5, relwidth=0.2, relheight=0.1)
        e_text=StringVar()
        e_text.set("")
        self.inp5 = Entry(roob,textvariable =e_text)
        self.inp5.place(relx=0.5, rely=0.5, relwidth=0.3, relheight=0.1)
        
        lb6 = Label(roob, text='座位数',bg='#C0C0C0',fg = "black",relief = GROOVE)
        lb6.place(relx=0.25, rely=0.6, relwidth=0.2, relheight=0.1)
        f_text=StringVar()
        f_text.set("")
        self.inp6 = Entry(roob,textvariable =f_text)
        self.inp6.place(relx=0.5, rely=0.6, relwidth=0.3, relheight=0.1)
        
        self.bt2=Button(roob,text="修改",command=self.Change)
        self.bt2.place(relx=0.7, rely=0.8, relwidth=0.2, relheight=0.1)
        
        self.txt1 = Text(roob)

    def searchByID(self,tralist,ID):
        for item in tralist:
            if item.ID == ID:
                return True
        return False
    
    def Delete(self):
        self.inp1.delete(0, END)
        self.inp2.delete(0, END)
        self.inp3.delete(0, END)
        self.inp4.delete(0, END)
        self.inp5.delete(0, END)
        self.inp6.delete(0, END)
  
    def Change(self):     
        ID=self.inp1.get()
        for item in trainlist:
            if item.ID == ID:
                trainlist.remove(item)
                file_object = open("train.txt", "w")
                for tra in trainlist:
                    file_object.write(tra.ID)
                    file_object.write(" ")
                    file_object.write(tra.forname)
                    file_object.write(" ")
                    file_object.write(tra.lastname)
                    file_object.write(" ")
                    file_object.write(str(tra.time))
                    file_object.write(" ")
                    file_object.write(str(tra.price))
                    file_object.write(" ")
                    file_object.write(str(tra.seating))
                    file_object.write("\n")
                file_object.close()
        tra = Train()
        tra.ID=str(self.inp1.get())
        tra.forname=str(self.inp2.get())
        tra.lastname=str(self.inp3.get())
        tra.time=str(self.inp4.get())
        tra.price=str(self.inp5.get())
        tra.seating=str(self.inp6.get())
        self.Add(trainlist, tra)
        print(tra.ID)    
    def Add(self,tralist,tra): 
        if self.searchByID(tralist, tra.ID) == True:
            self.txt1.delete(1.0,END)
            self.txt1.insert(END,'车次重复,修改失败' )
            return
        tralist.append(tra)
        file_object = open("train.txt", "a")
        file_object.write(tra.ID)
        file_object.write(" ")
        file_object.write(tra.forname)
        file_object.write(" ")
        file_object.write(tra.lastname)
        file_object.write(" ")
        file_object.write(tra.time)
        file_object.write(" ")
        file_object.write(tra.price)
        file_object.write(" ")
        file_object.write(tra.seating)
        file_object.write("\n")
        file_object.close()
        self.txt1.delete(1.0,END)
        self.txt1.insert(END,'修改成功' )
        
        return

class DIS():
    def display(self):
        roob=Toplevel(root)
        roob.title('列车信息显示')
        roob.geometry('490x370')

        self.txt = Text(roob)
        self.txt.place(relwidth=1, relheight=1)
        
        self.txt.insert(END,"{0:^6}\t{1:{6}^6}\t{2:{6}^6}\t{3:{6}^6}\t{4:{6}^6}\t{5:{6}^6}\n".format("车次","起点","终点","时间","票价","座位数",chr(12288)))
        size = os.path.getsize('train.txt')
        if size == 0:
            self.txt.insert(END,'没有车次信息')
            return
        self.Sort(trainlist)
        for item in trainlist:
            self.txt.insert(END,"{0:^8}\t{1:{6}^6}\t{2:{6}^6}\t{3:^12}\t{4:^12}\t{5:^8}\n".format(item.ID,item.forname,item.lastname,item.time,item.price,item.seating,chr(12288)))
        
    def Sort(self,tralist):
        tra = []
        time_count = []
        for li in tralist:
            temp = []
            temp.append(li.ID)
            temp.append(li.forname)
            temp.append(li.lastname)
            temp.append(float(li.time))
            temp.append(int(li.price))
            temp.append(int(li.seating))
            time_count.append(float(li.time))
            tra.append(temp)
        self.insertSort(time_count,tralist)

        
    def insertSort(self,a, tralist):  
        for i in range(len(a)-1):   
            for j in range(i+1,len(a)):  
                if a[i]>a[j]:  
                    temp = tralist[i]  
                    tralist[i] = tralist[j]  
                    tralist[j] = temp  

def main(): 
    b.destroy()
    root.title('列车管理系统')
    root.geometry('480x360')
    root.colors='#59D6FF'

    add=ADD()
    bt1=Button(root,text="列车添加",bg='#C0C0C0',fg = "black",relief = GROOVE,command=add.Add_f)
    bt1.place(relx=0.3, rely=0.2, relwidth=0.3, relheight=0.1)

    cha = Tsearch()
    bt4 = Button(root, text="列车改签",bg='#C0C0C0',fg = "black",relief = GROOVE, command=cha.Change_f)
    bt4.place(relx=0.3, rely=0.6, relwidth=0.3, relheight=0.1)

    sea=Remove()
    bt6=Button(root,text="列车查询",bg='#C0C0C0',fg = "black",relief = GROOVE,command=sea.Search_f)
    bt6.place(relx=0.3, rely=0.4, relwidth=0.3, relheight=0.1)
    
    dis=DIS()
    bt3=Button(root,text="列车显示",bg='#C0C0C0',fg = "black",relief = GROOVE,command=dis.display)
    bt3.place(relx=0.3, rely=0.5, relwidth=0.3, relheight=0.1)

    dela = DEL()
    bt2 = Button(root, text="列车删除", bg='#C0C0C0', fg="black", relief=GROOVE, command=dela.Del_f)
    bt2.place(relx=0.3, rely=0.3, relwidth=0.3, relheight=0.1)

    
    bt5=Button(root,text="退出",bg='#FF0000',fg = "black",relief = GROOVE,command=root.destroy)
    bt5.place(relx=0.3, rely=0.7, relwidth=0.3, relheight=0.1)

Init(trainlist)

b=Button(root,text="列车管理系统",bg='#59D6FF',fg='black',font=('华文新魏',32),relief=SUNKEN,command=main,width=500,height=240)
b.pack()

root.mainloop()



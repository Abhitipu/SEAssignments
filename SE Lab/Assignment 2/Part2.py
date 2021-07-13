"""
Name : Abhinandan De
Roll No : 19CS10069
"""

from tkinter import *
from PIL import ImageTk,Image
from tkinter import ttk
from tkinter import filedialog


class Message1:
    def __init__(self, content = "", sentId = "", receivedId = ""):
        self.content = content
        self.sentId = sentId
        self.receivedId = receivedId
        self.shorten()

    def shorten(self):
        words = self.content.split()
        j = 0
        temp = ""
        for word in words:
            temp += word
            temp += " "
            j += len(word)+1
            if j > 40:
                j = 0
                temp += '\n'
        self.content = temp

class Picture1:
    def __init__(self, addr, sid, rid):
        self.addr = addr
        self.sid = sid
        self.rid = rid


class User:
    def __init__(self, id):
        self.id = id
        self.contacts = []          # ids of the contacts
        self.groups = []            # ids of the groups
        self.sentMessages = []
        self.receivedMessages = []
        self.sentPictures = []      # filepaths pictures
        self.receivedPictures = []

    def add(self, contact):
        self.contacts.append(contact)

    def addGroup(self, group):
        self.groups.append(group)

    def sendMesg(self, mesg):
        self.sentMessages.append(mesg)

    def receiveMesg(self, mesg):
        self.receivedMessages.append(mesg)

    def sendPic(self, pic):
        self.sentPictures.append(pic)

    def receivePic(self, pic):
        self.receivedPictures.append(pic)


class Group:

    def __init__(self, id):
        self.id = id
        self.members = []

    def add(self, member):
        self.members.append(member)

    def sendMesg(self, content, sid):
        msg = Message1(content, sid, self.id)
        users[hash[sid]].sendMesg(msg)

        for mem in self.members:
            if sid == mem.id:
                continue
            msg = Message1(content, sid, mem.id)
            mem.receiveMesg(msg)

    def sendPic(self, name, sid):
        pic = Picture1(name, sid, self.id)
        users[hash[sid]].sendPic(pic)

        for mem in self.members:
            if sid == mem.id:
                continue
            pic = Picture1(name, sid, mem.id)
            mem.receivePic(pic)


class Window(Frame):
    def __init__(self, master, curUser):
        self.msg_file = open("message.txt", 'a+')
        self.msg_file.seek(0)               # moving the file pointer to the beginning of the file
        self.data = self.msg_file.readlines()
        self.syncMessages()                 # sync messages from previous runs!
        Frame.__init__(self, master)
        self.master = master

        # Creating a scroll Bar
        self.main_frame = Frame(master)
        self.main_frame.pack(fill=BOTH, expand=1)

        # Creating a canvas for the scroll bar
        self.my_canvas = Canvas(self.main_frame, bg="#BBF97E")
        self.my_canvas.pack(side=LEFT, fill=BOTH, expand=1)

        # Initialisation of the scroll bar
        self.my_scrollbar = ttk.Scrollbar(self.main_frame, orient=VERTICAL, command=self.my_canvas.yview)
        self.my_scrollbar.pack(side=RIGHT, fill=Y)

        # binding the scrollbar to the canvas
        self.my_canvas.configure(yscrollcommand=self.my_scrollbar.set)
        self.my_canvas.bind('<Configure>', lambda e: self.my_canvas.configure(scrollregion=self.my_canvas.bbox("all")))

        # initialising the main frame
        self.frame = Frame(self.my_canvas, bg = "#BBF97E", height=1000, width=1000)
        self.my_canvas.create_window((0, 0), window=self.frame, anchor="nw")

        # Setting the basics
        master.title("Wassuppppp!!")
        master.grid_columnconfigure(0, weight=1)
        master.grid_rowconfigure(0, weight=1)

        self.curUser = curUser
        self.labels = []
        self.texts = []
        self.buttons = []
        self.radbuttons = []
        self.drops = []
        self.fname = ""
        self.rimgs = []
        self.simgs = []

        # Creating the menus
        my_menu = Menu(self.frame)
        master.config(menu=my_menu)

        my_menu.add_command(label="Messages", command=self.loadMessages)
        my_menu.add_command(label="Contacts", command=self.loadContacts)
        my_menu.add_command(label="Groups", command=self.loadGroups)
        my_menu.add_command(label="Compose", command=self.composeNpost)

        # A drop down menu for switching user
        self.var = StringVar(master)
        self.var.set(users[0].id)

        # the drop down menu for switching user
        opt = ttk.Combobox(self.frame, values=[user.id for user in users], textvariable=self.var, width=15)
        opt.grid(row=0, column=0, padx=10, pady=10)

        btn = Button(self.frame, text = "Switch User", command = self.switchUser, bg="#0959FE", font=("Calibri", 12), padx=10, fg="white")
        btn.grid(row=0, column=1, padx=10, pady=10, sticky=W)

        # Basic info updates
        self.updateBasic()

        # updating the exit button
        self.exit_b = Button(self.frame, text="Exit", command=self.finish, bg = "#FE0909", fg="white", font = ("Calibri", 12), padx=10 )
        self.exit_b.grid(row=0, column=2, pady=10, padx=10)

        self.pack()
        self.loadMessages()

    def syncMessages(self):                     # for resyncing data from previous runs of the program

        j = 0
        n = len(self.data)
        for j in range(0, n):
            if self.data[j] == "Message to User\n":
                sid = self.data[j + 1].strip('\n')
                rid = self.data[j + 2].strip('\n')
                j += 3
                cont = ""
                while (self.data[j] != "***END***\n"):
                    cont += self.data[j]
                    j += 1
                self.sMu(cont, sid, rid)
                j -= 1

            elif self.data[j] == "Message to Group\n":
                sid = self.data[j + 1].strip('\n')
                rid = self.data[j + 2].strip('\n')
                j += 3
                cont = ""
                while (self.data[j] != "***END***\n"):
                    cont += self.data[j]
                    j += 1
                self.sMg(cont, sid, rid)
                j -= 1

            elif self.data[j] == "Picture to User\n":
                sid = self.data[j + 1].strip('\n')
                rid = self.data[j + 2].strip('\n')
                cont = self.data[j + 3].strip('\n')
                j += 3
                self.sPu(cont, sid, rid)

            elif self.data[j] == "Picture to Group\n":
                sid = self.data[j + 1].strip('\n')
                rid = self.data[j + 2].strip('\n')
                cont = self.data[j + 3].strip('\n')
                j += 3
                self.sPg(cont, sid, rid)

    def sMu(self, cont, sid, rid, upd=False):       # sends messages and updates to message.txt file
        msg = Message1(cont, sid, rid)
        users[hash[sid]].sendMesg(msg)
        users[hash[rid]].receiveMesg(msg)
        if upd:
            self.msg_file.write("Message to User\n")
            self.update(cont, sid, rid)

    def sMg(self, cont, sid, rid, upd=False):       # the upd is made to True is we need to update data
        groups[hash2[rid]].sendMesg(cont, sid)
        if upd:
            self.msg_file.write("Message to Group\n")
            self.update(cont, sid, rid)

    def sPu(self, cont, sid, rid, upd=False):
        pic = Picture1(cont, sid, rid)
        users[hash[sid]].sendPic(pic)
        users[hash[rid]].receivePic(pic)
        if upd:
            self.msg_file.write("Picture to User\n")
            self.update(cont, sid, rid)

    def sPg(self, cont, sid, rid, upd=False):
        groups[hash2[rid]].sendPic(cont, sid)
        if(upd):
            self.msg_file.write("Picture to Group\n")
            self.update(cont, sid, rid)

    def update(self, cont, sid, rid):       # makes updates to message.txt
        self.msg_file.write(sid + '\n')
        self.msg_file.write(rid+ '\n')
        self.msg_file.write(cont)
        self.msg_file.write("***END***\n")

    def clearUp(self):              # utility function to clear us the screen
        for lab in self.labels:
            lab.destroy()

        for tex in self.texts:
            tex.destroy()

        for btn in self.buttons:
            btn.destroy()

        for dr in self.drops:
            dr.destroy()

        for radb in self.radbuttons:
            radb.destroy()

        self.drops.clear()
        self.radbuttons.clear()
        self.labels.clear()
        self.texts.clear()
        self.buttons.clear()

    def loadMessages(self):             # loading the messages
        self.clearUp()
        self.master.geometry("500x700")
        i = 3
        lb1 = Label(self.frame, text="Received Items", bg="pink", width=26, font=("Comic SANS MS", 20))
        lb1.grid(row=2, column=0, padx=20, pady=20, columnspan=3)
        self.labels.append(lb1)

        for mesg in self.curUser.receivedMessages:
            lb = Label(self.frame, text=("By: " + str(mesg.sentId) + "\n" + mesg.content), bg="cyan", font=("Calibri", 12), padx = 10)
            lb.grid(row=i, column=0, padx=10, pady=10, columnspan=3)
            i += 1
            self.labels.append(lb)

        for pic in self.curUser.receivedPictures:
            fname = pic.addr
            fname = fname.strip('\n')
            my_img = Image.open(fname)
            (w, h) = my_img.size
            if (w > h):                            # proportionate resizing
                h = (200 * h) // w
                w = 200
            else:
                w = (200 * w) // h
                h = 200

            my_img = my_img.resize((w, h), Image.ANTIALIAS)
            self.rimgs.append(ImageTk.PhotoImage(my_img))
            lb2 = Label(self.frame, text="Sent by: " + pic.sid, font=("Calibri", 12))
            lb2.grid(row=i, column=0, columnspan=3, padx=10, pady=10)
            i += 1
            lb3 = Label(self.frame, image=self.rimgs[-1])
            lb3.grid(row=i, column=0, padx=10, pady=10, columnspan=3)
            i += 1
            self.labels.append(lb2)
            self.labels.append(lb3)

        lb2 = Label(self.frame, text="Sent Items", bg="pink", width=20, font=("Comic SANS MS", 20))
        lb2.grid(row=i, column=0, padx=20, pady=20, columnspan=3)
        i += 1
        self.labels.append(lb2)

        for mesg in self.curUser.sentMessages:
            lb = Label(self.frame, text=("To: " + str(mesg.receivedId) + "\n" + mesg.content), bg="yellow", font=("Calibri", 12), padx = 10)
            lb.grid(row=i, column=0, padx=10, pady=10, columnspan=3)
            i += 1
            self.labels.append(lb)

        for pic in self.curUser.sentPictures:
            fname = pic.addr
            fname = fname.strip('\n')
            my_img = Image.open(fname)
            (w, h) = my_img.size
            if(w > h):
                h = (250 * h) // w
                w = 250
            else:
                w = (250 * w) // h
                h = 250

            my_img = my_img.resize((w, h), Image.ANTIALIAS)
            self.simgs.append(ImageTk.PhotoImage(my_img))
            lb2 = Label(self.frame, text="To: " + pic.rid, font=("Calibri", 12))
            lb2.grid(row=i, column=0, columnspan=3, padx=10, pady=10)
            i += 1
            lb3 = Label(self.frame, image=self.simgs[-1])
            lb3.grid(row=i, column=0, padx=10, columnspan=3)
            i += 1
            self.labels.append(lb2)
            self.labels.append(lb3)


    def loadContacts(self):         # loading the contacts
        self.clearUp()
        self.master.geometry("499x700")
        i = 3
        lb1 = Label(self.frame, text="Contacts", bg="#B200FF", width=20, font=("Comic SANS MS", 20))
        lb1.grid(row=2, column=0, padx=20, pady=20, columnspan=3)
        self.labels.append(lb1)

        for ids in self.curUser.contacts:
            lb = Label(self.frame, text=ids, font=("Calibri", 15), width=17, bg="#FF9200")
            self.labels.append(lb)
            lb.grid(row = i, column = 0, padx=10, pady=10, columnspan=3)
            i += 1

    def loadGroups(self):           # loading the groups
        self.clearUp()
        self.master.geometry("501x700")
        i = 3
        lb1 = Label(self.frame, text="Groups", bg="#FF9200", width=20, font=("Comic SANS MS", 20))
        lb1.grid(row=2, column=0, padx=20, pady=20, columnspan=3)
        self.labels.append(lb1)

        for grp in self.curUser.groups:
            lb = Label(self.frame, text=grp.id, font=("Calibri", 15), width=30, bg="#42C7FE")
            self.labels.append(lb)
            lb.grid(row=i, column=0, padx=20, pady=20, columnspan=3)
            i += 1

    def composeNpost(self):             # configuring the compose and post window
        self.clearUp()
        self.master.geometry("625x700")
        i = 2;
        lb1 = Label(self.frame, text="Create and Post Content!", bg="#47EEEC", font=("Comic SANS MS", 20), padx=10, pady=10)
        lb1.grid(row=i, column=0, padx=10, pady=10, columnspan=3)
        i += 1
        self.labels.append(lb1)

        lb2 = Label(self.frame, text="Write something to share", bg="#F7942D", font=("Comic SANS MS", 17), width = 35)
        lb2.grid(row=i, column=0, padx=10, pady=10, columnspan=3)
        i += 1
        self.labels.append(lb2)

        self.tx1 = Text(self.frame, width=70, height=10)
        self.tx1.insert(1.0, "**Enter text**")
        self.tx1.grid(row=i, column=0, padx=10, pady=10, columnspan=3)
        i += 1
        self.texts.append(self.tx1)

        btn = Button(self.frame, text="Post a picture!", font = ("Comic sans ms", 13), bg = "#F7942D", width = 20, height = 2, command=self.getfilename)
        btn.grid(row=i, column=0, padx=10, pady=10)
        self.buttons.append(btn)

        self.texname = Text(self.frame, width=40, height=1)
        self.texname.insert(1.0, "**No file chosen**")
        self.texname.grid(row=i, column=1, columnspan=2, padx=20, pady=20)
        i += 1
        self.texts.append(self.texname)

        self.sendToU = StringVar()
        self.sendToU.set("")
        self.sendToG = StringVar()
        self.sendToG.set("")
        self.choice = IntVar()
        self.choice.set(1)

        self.grp = Radiobutton(self.frame, text="Send to a group", variable=self.choice, value=1, bg="#C577F6", font=("Calibri", 12))
        self.grp.grid(row=i, column=0, padx=10, pady=10, sticky=W)

        self.con = Radiobutton(self.frame, text="Send to a contact", variable=self.choice, value=2, bg="#C577F6", font=("Calibri", 12))
        self.con.grid(row=i, column=2, padx=10, pady=10, sticky=W)
        i += 1

        self.radbuttons.append(self.con)
        self.radbuttons.append(self.grp)

        self.avl_groups = ttk.Combobox(self.frame, values=[group.id for group in self.curUser.groups], textvariable=self.sendToG)
        self.avl_groups.grid(row=i, column=0, padx=10, pady=10, sticky=W)

        self.avl_contacts = ttk.Combobox(self.frame, values=[contact for contact in self.curUser.contacts], textvariable=self.sendToU)
        self.avl_contacts.grid(row=i, column=2, padx=10, pady=10, sticky=W)

        self.drops.append(self.avl_groups)
        self.drops.append(self.avl_contacts)
        i += 1

        self.btn = Button(self.frame, text = "Share!", command = self.share, width=20, bg="#1A32F3", font = ("Calibri", 13), fg="white")
        self.btn.grid(row =i, column=1, padx=10, pady=10)
        self.buttons.append(self.btn)
        i += 1

    def share(self):                    # checks and shares acc to requirement
        if self.choice.get() == 1:
            if(self.tx1.get(1.0, END) != "**Enter text**\n" and self.tx1.get(1.0, END) != "" and self.sendToG.get() != ""):
                self.sendMesgToGroup()
            if(self.texname.get(1.0, END) != "**No file chosen**\n" and self.texname.get(1.0, END) != "" and self.sendToG.get() != ""):
                self.sendPicToGroup()
        else:
            if (self.tx1.get(1.0, END) != "**Enter text**\n" and self.tx1.get(1.0, END) != "" and self.sendToU.get() != ""):
                self.sendMesgToUser()
            if (self.texname.get(1.0, END) != "**No file chosen**\n" and self.texname.get(1.0, END) != "" and self.sendToU.get() != ""):
                self.sendPicToUser()

    def getfilename(self):
        self.fname = filedialog.askopenfilename(initialdir="C:/Users/Abhinandan/Pictures", title="Select a file", filetypes=(("jpg files", "*.jpg"), ("all files", "*.*")))
        self.texname.delete(1.0, END)
        self.texname.insert(1.0, self.fname)

    def sendMesgToGroup(self):
        gid = self.sendToG.get()
        sid = self.curUser.id
        cont = self.tx1.get(1.0, END)
        self.sMg(cont, sid, gid, True)  # using another existing function
        self.tx1.delete(1.0, END)

    def sendPicToGroup(self):
        gid = self.sendToG.get()
        sid = self.curUser.id
        content = self.texname.get(1.0, END)
        self.sPg(content, sid, gid, True)  # using another existing function
        self.texname.delete(1.0, END)

    def sendMesgToUser(self):
        sid = self.curUser.id
        rid = self.sendToU.get()
        cont = self.tx1.get(1.0, END)
        self.sMu(cont, sid, rid, True)  # using another existing function
        self.tx1.delete(1.0, END)

    def sendPicToUser(self):
        sid = self.curUser.id
        rid = self.sendToU.get()
        cont = self.texname.get(1.0, END)
        self.sPu(cont, sid, rid, True)  # using another existing function
        self.texname.delete(1.0, END)

    def switchUser(self):           # switching user
        userNo = hash[self.var.get()]
        self.curUser = users[userNo]
        self.loadMessages()
        self.updateBasic()

    def updateBasic(self):          # updating the user who is logged in
        self.lb1 = Label(self.frame, text="Currently logged in as " + self.curUser.id, bg = "#265125", width=30, height=1, font = ("Lucida handwriting", 15), fg="white")
        self.lb1.grid(row=1, column=0, padx=10, pady=10, columnspan=3)

    def finish(self):               # clearing up data and closing the files
        self.msg_file.close()
        self.clearUp()
        self.quit()



users = []          # the list of users
groups = []         # the list of the groups
hash = {}           # generating a map from user id to index in the list for better time complexity
hash2 = {}          # this map is from group id to index

# updating user list from social_network.txt
with open("social_network.txt", 'r') as file:
    flag = True
    hash_id = 0

    for line in file:

        if line == "#users\n":
            continue
        elif line == "#groups\n":
            flag = False
            continue

        if flag:                # indicates that we are still parsing the users
            gotUserId = False
            id = ""
            word = ""

            for c in line:
                if c == '<' or c == '\n' or c == ' ':
                    continue
                elif gotUserId:
                    if c == ',' or c == '>':
                        newUser.add(word)
                        word = ""
                    else:
                        word += c
                else:
                    if c==':':
                        gotUserId = True
                        id = word
                        newUser = User(id)
                        word = ""
                    else:
                        word += c

            users.append(newUser)
            hash[id] = hash_id
            hash_id += 1

        else:                                  # indicates that we are now parsing the groups
            gotGroupId=False
            GroupId = ""
            word = ""
            hash_id = 0

            for c in line:
                if c == '<' or c == '\n' or c == ' ':
                    continue
                elif gotGroupId:
                    if c == ',' or c == '>':
                        newGroup.add(users[hash[word]])        # basically establishing links between the two
                        users[hash[word]].addGroup(newGroup)
                        word = ""
                    else:
                        word += c
                else:
                    if c == ':':
                        gotGroupId = True
                        GroupId = word
                        newGroup = Group(GroupId)
                        word = ""
                    else:
                        word += c

            groups.append(newGroup)
            hash2[GroupId] = hash_id
            hash_id += 1


root = Tk()
app = Window(root, users[0])

root.mainloop()
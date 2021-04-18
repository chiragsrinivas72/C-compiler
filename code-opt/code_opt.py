f = open("inp.txt","r")
fout = open("out.txt","w")

list_of_lines = f.readlines()
dictValues = dict()
constantFoldedList = []
print("Quadruple form after Constant Folding")
print("-------------------------------------")
for i in list_of_lines:
    i = i.strip("\n")
    op,arg1,arg2,res = i.split()
    if(op in ["+","-","*","/"]):
        if(arg1.isdigit() and arg2.isdigit()):
            result = str(eval(arg1+op+arg2))
            dictValues[res] = result
            print("=",result,"NULL",res)
            constantFoldedList.append(["=",result,"NULL",res])
        elif(arg1.isdigit()):
            if(arg2 in dictValues):
                result = str(eval(arg1+op+dictValues[arg2]))
                dictValues[res] = result
                print("=",result,"NULL",res)
                constantFoldedList.append(["=",result,"NULL",res])
            else:
                print(op,arg1,arg2,res)
                constantFoldedList.append([op,arg1,arg2,res])
        elif(arg2.isdigit()):
            if(arg1 in dictValues):
                result = str(eval(dictValues[arg1]+op+arg2))
                dictValues[res] = result
                print("=",result,"NULL",res)
                constantFoldedList.append(["=",result,"NULL",res])
            else:
                print(op,arg1,arg2,res)
                constantFoldedList.append([op,arg1,arg2,res])
        else:
            flag1=0
            flag2=0
            arg1Res = arg1
            if(arg1 in dictValues):
                arg1Res = str(dictValues[arg1])
                flag1 = 1
            arg2Res = arg2
            if(arg2 in dictValues):
                arg2Res = str(dictValues[arg2])
                flag2 = 1
            if(flag1==1 and flag2==1):
                result = str(eval(arg1Res+op+arg2Res))
                dictValues[res] = result
                print("=",result,"NULL",res) 
                constantFoldedList.append(["=",result,"NULL",res])
            else:
                print(op,arg1Res,arg2Res,res)
                constantFoldedList.append([op,arg1Res,arg2Res,res])

    elif(op=="not"):
        # not a NULL T1
        if(arg1.isdigit()):
            if(arg1 == "0" or arg1 == "0.0" or arg1 == "NULL"):
                dictValues[res]="1"
            else:
                dictValues[res]="0"
            print("=",dictValues[res],"NULL",res)
            constantFoldedList.append(["=",dictValues[res],"NULL",res])

        elif(arg1 in dictValues):
            if(dictValues[arg1] == "0" or dictValues[arg1] == "0.0" or dictValues[arg1] == "NULL"):
                dictValues[res]="1"
            else:
                dictValues[res]="0"
            print("=",dictValues[res],"NULL",res)
            constantFoldedList.append(["=",dictValues[res],"NULL",res])
        else:
            print(op,arg1Res,arg2Res,res)
            constantFoldedList.append([op,arg1,arg2,res])

    elif(op == "if"):
        #if T1 NULL L0
        if(arg1 in dictValues):
            print("if",dictValues[arg1],"NULL",res)
            constantFoldedList.append(["if",dictValues[arg1],"NULL",res])
        else:
            print(op,arg1,arg2,res)
            constantFoldedList.append([op,arg1,arg2,res]) 

    elif(op=="="):
        if(arg1.isdigit()):
            dictValues[res]=arg1
            print("=",arg1,"NULL",res)
            constantFoldedList.append(["=",arg1,"NULL",res])
        else:
            if(arg1 in dictValues):
                print("=",dictValues[arg1],"NULL",res)
                constantFoldedList.append(["=",dictValues[arg1],"NULL",res])
            else:
                print("=",arg1,"NULL",res)
                constantFoldedList.append(["=",arg1,"NULL",res])
    
    else:
        print(op,arg1,arg2,res)
        constantFoldedList.append([op, arg1, arg2, res])
        
print("\n")
print("After common subexpression elimination - ")
print("------------------------------")

firstOccurenceOfRHS = dict()
toBeReplacedDict = dict()

for i in constantFoldedList:
    if (i[0] in ["+", "-", "*", "/"]):
        op=i[0]
        if (i[1].isnumeric() and i[2].isnumeric()):
            pass
        else:
            temp = i[1] + i[0] + i[2]
            if temp not in firstOccurenceOfRHS:
                firstOccurenceOfRHS[temp] = i[3]
            else:
                toBeReplacedDict[i[3]] = firstOccurenceOfRHS[temp]
                split_temp = temp.split(op)
                #print('split,t',split_temp)
                split_temp_arg1 = split_temp[0]
                split_temp_arg2 = split_temp[1]
                final_temp = ''
                if (split_temp_arg1 in toBeReplacedDict):
                    final_temp = toBeReplacedDict[split_temp_arg1] + op + split_temp_arg2
                if (split_temp_arg2 in toBeReplacedDict):
                    final_temp = split_temp_arg1 + op + toBeReplacedDict[split_temp_arg2]
                firstOccurenceOfRHS[final_temp]= toBeReplacedDict[i[3]]

expressionCount = dict()
for i in firstOccurenceOfRHS:
    expressionCount[i]=0

csedList = []

for i in constantFoldedList:
    op = i[0]
    arg1 = i[1]
    arg2 = i[2]
    if (arg1 in toBeReplacedDict):
        arg1 = toBeReplacedDict[arg1]
    if (arg2 in toBeReplacedDict):
        arg2 = toBeReplacedDict[arg2]
    if(arg1!="NULL" and arg2!="NULL"):
        temp = arg1 + op + arg2
        if(temp not in firstOccurenceOfRHS):
            #print(i[3], "=", arg1, op, arg2)
            csedList.append([op, arg1, arg2, i[3]])
        else:
            if(expressionCount[temp]==0):
                #print(i[3], "=", arg1, op, arg2)
                expressionCount[temp] += 1
                csedList.append([op, arg1, arg2, i[3]])
            else:
                pass     
    else:
        #print(i[3], "=", arg1, op, arg2)
        csedList.append([op, arg1, arg2, i[3]])

for i in csedList:
    op = i[0]
    arg1 = i[1]
    arg2 = i[2]
    res=i[3]
    print(op,arg1,arg2,res)

print("\n")
print("Constant folded expression - ")
print("--------------------")
for i in csedList:
    if(i[0]=="="):
        print(i[3],i[0],i[1])
    elif(i[0] in ["+","-","*","/","==","<=","<",">",">="]):
        print(i[3],"=",i[1],i[0],i[2])
    elif(i[0] in ["if","goto","Label","not"]):
        if(i[0]=="if"):
            print(i[0],i[1],"goto",i[3])
        if(i[0]=="goto"):
            print(i[0],i[3])
        if(i[0]=="Label"):
            print(i[3],":")
        if(i[0]=="not"):
            print(i[3],"=",i[0],i[1])

print("\n")
print("After dead code elimination - ")
print("------------------------------")
for i in csedList:
    if(i[0]=="="):
        pass
    elif(i[0] in ["+","-","*","/","==","<=","<",">",">="]):
        print(i[3],"=",i[1],i[0],i[2])
    elif(i[0] in ["if","goto","Label","not"]):
        if(i[0]=="if"):
            print(i[0],i[1],"goto",i[3])
        if(i[0]=="goto"):
            print(i[0],i[3])
        if(i[0]=="Label"):
            print(i[3],":")
        if(i[0]=="not"):
            print(i[3], "=", i[0], i[1])
            
    

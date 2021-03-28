#!/usr/bin/bash

while [ 1 = 1 ]
do
    echo "hello"
done

: '
i=0

while [ $i -lt 3 ]
do 
    echo "i=$i"
    i=`expr $i + 1`
    #    let "i+=1"
done
'

: '
value=`ls`

for i in $value
do
    echo "i=$i"
done
'





: '
for i in 1 2 3 4
do
    echo "i=$i"
    sleep 1
done
'

: '
echo "input val"
read val

if [ "$val" -gt 100 ] || [ "$val" -lt 0 ]
then
    echo "nonono"
    exit
fi

if [ "$val" -ge 90 ]
then 
    echo "A"
elif [ "$val" -ge 80 ]
then
    echo "B"
elif [ "$val" -ge 60 ]
then
    echo "C"
else
    echo "D"
fi
'




#echo "input filename: "
#read filename

#if [ -d "$filename" ]; then
  #  echo "$filename is dirent"
#elif [ -f "$filename" ]; then
 #   echo "$filename is file"
#else
##    echo "$filename not find"
#fi









#str="123"

#echo "input"
#read line

#if [ "$line" -ge "60" ]
#then
   # echo "$line >= 60 "
#elif [ "$line" -gt "0" ] 
#then
 #   echo "$line > 0"
#else
 #   echoo "$line is -"
#fi


#str="1223"
###echo "input"
#read line

#if [ "$line" = "$str" ]
#then
 # echo "==" 
#else
 #   echo "!="
#fi


#if test $line = $str
#then
 #   echo "=="
#fi









#echo "my.sh pid=$$"
#echo "agrc=$#"
#echo "\$0=$0"
#echo "\$1=$1"





#echo "PATH=$PATH"
#echo "MYSTR=$MYSTR"






#val=100
#str=hello
#str1="hello abc $str"

#echo "val=$val"
#echo "str=$str"
#echo "str1=$str1"
#echo 'val=$val'

exit 0

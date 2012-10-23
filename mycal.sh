#!/bin/bash
#code by YC @2012.10.22

a=$1

case $a in
    "January")
    a=1;;
    "February")
    a=2;;
    "March")
    a=3;;
    "April")
    a=4;;
    "May")
    a=5;;
    "June")
    a=6;;
    "July")
    a=7;;
    "August")
    a=8;;
    "September")
    a=9;;
    "October")
    a=10;;
    "November")
    a=11;;
    "December")
    a=12;;
esac

dat="date --date=$2-$a-1"
blank=`$dat +%w`
# echo $dat

mon=`$dat +%B`
if [ "$a" == "12" ]; then
    day_count=31
else
#note: transfrom to decimal (base 10)
day_count=$((10#`date --date=$2-$(($a+1))-1 +%j`- 10#`$dat +%j`))
fi

# echo "$mon ; $blank ; $day_count"

#display
printf "%14s     $2\n" $mon
printf " Sun Mon Tue Wed Thu Fri Sat\n"

for((i=0; i<$blank; i++))
do
    printf "    "
done

for i in $(seq 1 $day_count)
do
    printf "%4d" $i
    blank=$(($blank+1))
    if [ $(($blank%7)) == 0 ]; then
        printf "\n"
    fi
done
printf "\n"

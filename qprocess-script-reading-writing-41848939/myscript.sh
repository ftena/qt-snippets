echo "enter your name:"
read n
if [ ! -z "$n" ];
then
        echo "success" $n
        exit 0;
else
        echo "failed" $n
        exit 1;
fi

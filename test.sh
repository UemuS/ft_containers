if [ -z "$1" ]
  then
    echo "No argument supplied"
	exit 1
elif [ $1 == "stack" ] 
then
	./a.out stack_test > stack_test.out
	./a.out stack_sys > stack_sys.out
	diff stack_test.out stack_sys.out > stack_test.diff
elif [ $1 == "map" ] 
then
	./a.out map_test > map_test.out
	./a.out map_sys > map_sys.out
	diff map_test.out map_sys.out > map_test.diff

elif [ $1 == "set" ] 
then
	./a.out set_test > set_test.out
	./a.out set_sys > set_sys.out
	diff set_test.out set_sys.out > set_test.diff


elif [ $1 == "vector" ] 
then
	./a.out vector_test > vector_test.out
	./a.out vector_sys > vector_sys.out
	diff vector_test.out vector_sys.out > vector_test.diff

elif [ $1 == "clean" ]
then
	rm -rf stack_test.out stack_sys.out stack_test.diff map_test.out map_sys.out map_test.diff set_test.out set_sys.out set_test.diff vector_test.out vector_sys.out vector_test.diff
else
	echo "need to specify stack, map, set, or vector"
fi

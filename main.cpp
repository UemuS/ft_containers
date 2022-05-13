
#include "tests/stack_test.cpp"
#include "tests/stack_sys.cpp"
#include "tests/vector_test.cpp"
#include "tests/vector_sys.cpp"
#include "tests/map_test.cpp"
#include "tests/map_sys.cpp"
#include "tests/set_sys.cpp"
#include "tests/set_test.cpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "Usage: ./tests [stack_test|stack_sys|vector_test|vector_sys|map_test|map_sys|set_test|set_sys]" << std::endl;
    else if (!strcmp(argv[1], "stack_test"))
        stack_test();
    else if (!strcmp(argv[1], "stack_sys"))
        stack_sys();
    else if (!strcmp(argv[1], "vector_test"))
        vector_test();
    else if (!strcmp(argv[1], "vector_sys"))
        vector_sys();
    else if (!strcmp(argv[1], "map_test"))
        map_test();
    else if (!strcmp(argv[1], "map_sys"))
        map_sys();
    else if (!strcmp(argv[1], "set_test"))
        set_test();
    else if (!strcmp(argv[1], "set_sys"))
        set_sys();
	else
		std::cout << "Usage: ./tests [stack_test|stack_sys|vector_test|vector_sys|map_test|map_sys|set_test|set_sys]" << std::endl;
    return (0);
}

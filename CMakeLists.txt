cmake_minimum_required(VERSION 3.25)
project(Philosophers C)

#add_compile_options(-fsanitize=address -fsanitize=leak -g3)
#add_link_options(-fsanitize=address -fsanitize=leak)
#add_compile_options(-fsanitize=thread)
#add_link_options(-fsanitize=thread)

set(CMAKE_C_STANDARD 99)

add_executable(Phylosophers main.c include/philos.h src/philos/philos.c src/check/check_input.c src/utils/phi_atoi.c include/check.h include/utils.h src/philos/actions.c src/utils/phi_strlen.c src/utils/phi_strncmp.c src/utils/errors.c
        src/utils/phi_calloc.c
        src/philos/create_philos.c
        src/utils/prints.c
        src/philos/thread_philos.c
        src/philos/thread_philos.c
		src/philos/mutex.c
		src/utils/message.c
		src/utils/time.c
		src/philos/check_philos.c
		src/philos/free_philos.c
		src/utils/phi_sleep.c)

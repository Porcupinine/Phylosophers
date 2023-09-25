cmake_minimum_required(VERSION 3.25)
project(Phylosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(Phylosophers main.c include/philos.h src/philos/philos.c src/check/check_input.c src/utils/phi_atoi.c include/check.h include/utils.h src/philos/actions.c src/utils/phi_strlen.c src/utils/phi_strncmp.c src/utils/errors.c
        src/utils/phi_calloc.c
        src/philos/create_philos.c
        src/utils/prints.c
        src/philos/thread_philos.c
        src/philos/thread_philos.c
		src/philos/mutex.c)

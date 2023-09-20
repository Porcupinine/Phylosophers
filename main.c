#include "include/philos.h"
#include "include/utils.h"

int main(int argc, char **argv)
{
    t_philos_data run;
    if (argc < 5 || argc > 6)
    {
        phi_error("Wrong amount of arguments\n");
        return (1);
    }
    if (set_data(argv, &run) == 1)
    {
        phi_error("invalid data\n");
        return (1);
    }
    if (argc > 5)
    {
        run.cycles = phi_atoi(argv[5]);
        //we have cycles
    }


}

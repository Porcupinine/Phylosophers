//
// Created by laura on 31-5-23.
//
#include "../../include/philos.h"
#include "../../include/utils.h"
#include "../../include/check.h"

int set_data(char **argv, t_philos_data *run)
{
    if(check_int_limits(argv[1]) == 1)
        return (1);
    if(check_int_limits(argv[2]) == 1)
        return (1);
    if(check_int_limits(argv[3]) == 1)
        return (1);
    if(check_int_limits(argv[4]) == 1)
        return(1);
    run->amount = phi_atoi(argv[1]);
    run->lifespan = phi_atoi(argv[2]);
    run->eat = phi_atoi(argv[3]);
    run->sleep = phi_atoi(argv[4]);
    return (0);
}
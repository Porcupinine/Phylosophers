//
// Created by laura on 31-5-23.
//

#ifndef PHILOS_H
#define PHILOS_H

typedef struct s_philos_data
{
    int amount;
    int lifespan;
    int eat;
    int sleep;
    int cycles;
}t_philos_data;

int set_data(char **argv, t_philos_data *run);

#endif //PHILOS_H

//
// Created by laura on 31-5-23.
//

#include <unistd.h>

void eat(int timmer)
{
    usleep(*timer);

}

void sleep(void *arg)
{
    useconds_t *timer;

    timer = (useconds_t*)arg;
    usleep(*timer);
}

void *think(void *arg)
{

}

#ifndef TASKS_H
#define TASKS_H

#include <QMap>

struct Task {
    double a;
    double b;
    int k;
};

extern const QMap<int, Task> tasks;

#endif // TASKS_H

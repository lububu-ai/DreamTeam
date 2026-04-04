#ifndef TASKS_H
#define TASKS_H

#include <QString>
#include <functional>
#include <vector>
#include <utility>

struct CurrentTask {
    int type = 0;
    QString payload = "";
    double answer = 0.0;

    bool is_valid() const;
    void clear();
};

CurrentTask generate_task(int task_type);

#endif // TASKS_H

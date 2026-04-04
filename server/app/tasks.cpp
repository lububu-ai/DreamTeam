#include "tasks.h"

bool CurrentTask::is_valid() const
{
    return type != 0;
}

void CurrentTask::clear()
{
    type = 0;
    payload.clear();
    answer = 0.0;
}

CurrentTask generate_task(int task_type)
{
    CurrentTask task;
    switch (task_type) {
    case 1:
    {
        double h = (rand() % 10 + 1) / 10.0;
        double y0 = rand() % 10;
        double y1 = rand() % 10;
        double y2 = rand() % 10;
        double answer = h / 3.0 * (y0 + 4.0 * y1 + y2);
        task.type = 1;
        task.payload = QString("%1;%2;%3;%4").arg(h).arg(y0).arg(y1).arg(y2);
        task.answer = answer;
        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        double a = rand() % 10;
        double b = a + 1 + rand() % 10;
        int k = 1 + rand()%5;
        task.type = 3;
        task.payload = QString("%1;%2;%3").arg(a).arg(b).arg(k);
        task.answer = (b-a) / std::pow(2.0, k);
        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        break;
    }
    default:
        break;
    }
    return task;
}

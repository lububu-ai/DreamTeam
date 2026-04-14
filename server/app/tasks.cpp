#include "tasks.h"

bool CurrentTask::is_valid() const
{
    return type != 0;
}

void CurrentTask::clear()
{
    type = 0;
    payload.clear();
    answer.clear();
}



CurrentTask generate_task(int task_type)
{
    CurrentTask task;
    switch (task_type) {
    case 1: //Мусихин
    {
        double h = (rand() % 10 + 1) / 10.0;
        double y0 = rand() % 10;
        double y1 = rand() % 10;
        double y2 = rand() % 10;
        double answer = h / 3.0 * (y0 + 4.0 * y1 + y2);
        task.type = 1;
        task.payload = QString("%1;%2;%3;%4").arg(h).arg(y0).arg(y1).arg(y2);
        task.answer = QString::number(answer, 'f', 6);
        break;
    }
    case 2: //Филатов
    {
        int function_id = rand() % 5; // 0..4
        int a = -10 + rand() % 16;
        int b = a + 1 + rand() % 10;

        QString funcText;
        double fa = 0.0;
        double fb = 0.0;
        double answer = -100.0;

        switch (function_id) {
        case 0:
            funcText = "2x-4";
            fa = 2.0 * a - 4.0;
            fb = 2.0 * b - 4.0;
            break;
        case 1:
            funcText = "x^2-9";
            fa = a * a - 9.0;
            fb = b * b - 9.0;
            break;
        case 2:
            funcText = "x^2-4x+3";
            fa = a * a - 4.0 * a + 3.0;
            fb = b * b - 4.0 * b + 3.0;
            break;
        case 3:
            funcText = "x^3-8";
            fa = a * a * a - 8.0;
            fb = b * b * b - 8.0;
            break;
        case 4:
            funcText = "|x|-3";
            fa = std::abs(a) - 3.0;
            fb = std::abs(b) - 3.0;
            break;
        }

        if ((fa * fb <= 0.0) && !(fa == 0.0 && fb == 0.0) && (fb - fa != 0.0)) {
            answer = (a * fb - b * fa) / (fb - fa);
        } else {
            answer = -100.0;
        }

        task.type = 2;
        task.payload = QString("%1;%2;%3;%4;%5")
                           .arg(funcText)
                           .arg(a)
                           .arg(b)
                           .arg(QString::number(fa, 'f', 3))
                           .arg(QString::number(fb, 'f', 3));
        task.answer = QString::number(answer, 'f', 6);
        break;
    }
    case 3: //Шилова
    {
        double a = rand() % 10;
        double b = a + 1 + rand() % 10;
        int k = 1 + rand() % 5;
        double answer = (b-a) / std::pow(2.0, k);
        task.type = 3;
        task.payload = QString("%1;%2;%3").arg(a).arg(b).arg(k);
        task.answer = QString::number(answer, 'f', 6);
        break;
    }
    case 4: //Семенец
    {
        int n = 6 + rand() % 5;
        int root = rand() % n;

        std::vector<std::vector<int>> adj(n);
        std::vector<std::pair<int,int>> edges;

        for (int v = 1; v < n; ++v) {
            int parent = rand() % v;
            adj[parent].push_back(v);
            adj[v].push_back(parent);
            edges.push_back({parent, v});
        }

        std::vector<int> leaves;

        std::function<void(int,int)> dfs = [&](int v, int p) {
            bool hasChildren = false;
            for (int to : adj[v]) {
                if (to != p) {
                    hasChildren = true;
                    dfs(to, v);
                }
            }
            if (!hasChildren) {
                leaves.push_back(v);
            }
        };

        dfs(root, -1);
        std::sort(leaves.begin(), leaves.end());

        QStringList edgeParts;
        for (const auto& e : edges) {
            edgeParts << QString("%1-%2").arg(e.first).arg(e.second);
        }

        QStringList leafParts;
        for (int x : leaves) {
            leafParts << QString::number(x);
        }

        task.type = 4;
        task.payload = QString("%1;%2;%3").arg(n).arg(root).arg(edgeParts.join(","));
        task.answer = leafParts.join(",");
        break;
    }
    case 5: //Рыбакин
    {
        double a, b, c, d, x0, answer;
        a = (-50.0 + rand() % (101)) / 10.0;
        b = (-50.0 + rand() % (101)) / 10.0;
        c = (-50.0 + rand() % (101)) / 10.0;
        d = (-50.0 + rand() % (101)) / 10.0;
        x0 = (-50.0 + rand() % (101)) / 10.0;
        answer = a * std::log(std::abs(x0) + 1.0) + b * std::sqrt(std::abs(c * x0 + d));
        task.type = 5;
        task.payload = QString("%1;%2;%3;%4;%5").arg(a).arg(b).arg(c).arg(d).arg(x0);
        task.answer = QString::number(answer, 'f', 6);
        break;
    }
    default:
        break;
    }
    return task;
}

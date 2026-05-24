FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Устанавливаем Qt5 и инструменты сборки
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    libqt5sql5 \
    libqt5sql5-sqlite \
    qtwayland5 \
    && rm -rf /var/lib/apt/lists/*

# Рабочая директория для исходников
WORKDIR /server_build
COPY . .

# Заходим в папку, собираем (бинарник рождается с именем tcpServer) и копируем его в корень
RUN cd server/app && qmake app.pro && make && cp tcpServer /tcpServer

# Создаем изолированную папку под базу данных
RUN mkdir -p /db_storage

EXPOSE 33333

# Папка базы данных становится рабочей директорией перед стартом
WORKDIR /db_storage

# Запуск сервера
ENTRYPOINT ["/tcpServer"]

# docker build -t my-qt-server . - создание образа
# docker run -d --name qt-container -p 33333:33333 -v "${PWD}/SQLite.db:/app/runtime/SQLite.db" my-qt-server - создание контейнера
# docker stop qt-container - останавка контейнера
# docker rm qt-container - удаление контейнера
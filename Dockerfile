FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

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

WORKDIR /server_build
COPY . .

RUN cd server/app && qmake app.pro && make && cp tcpServer /tcpServer

RUN mkdir -p /db_storage

EXPOSE 33333

WORKDIR /db_storage

ENTRYPOINT ["/tcpServer"]

# docker build -t my-qt-server . - создание образа
# docker run -d --name qt-container -p 33333:33333 -v "${PWD}/my_server_database:/db_storage" my-qt-server - создание контейнера
# docker stop qt-container - останавка контейнера
# docker rm qt-container - удаление контейнера
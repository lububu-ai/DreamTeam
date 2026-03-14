FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime
RUN echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install -y qtbase5-dev
RUN apt-get install -y qtchooser
RUN apt-get install -y qt5-qmake
RUN apt-get install -y qtbase5-dev-tools
RUN apt-get install -y libqt5sql5
RUN apt-get install -y libqt5sql5-sqlite
RUN apt-get install -y qtwayland5
RUN apt-get install -y build-essential

WORKDIR /app

COPY . .

RUN find . -maxdepth 2 -name "*.cpp" -exec mv {} . \;
RUN find . -maxdepth 2 -name "*.h" -exec mv {} . \;
RUN find . -maxdepth 2 -name "*.pro" -exec mv {} . \;

RUN qmake tcpServer.pro
RUN make

EXPOSE 33333

ENTRYPOINT ["./tcpServer"]
## Part 1. Готовый докер
Взять официальный докер образ с nginx и выкачать его при помощи docker pull
![img](screens/3.png)

Проверить наличие докер образа через docker images
![img](screens/4.png)

Запустить докер образ через docker run -d [image_id|repository]
![img](screens/5.png)

Проверить, что образ запустился через docker ps
![img](screens/6.png)


Посмотреть информацию о контейнере через docker inspect [container_id|container_name]

По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера

id

![img](screens/7.1.png)

size

![img](screens/8.png)

ports

![img](screens/9.png)

Остановить докер образ через docker stop [container_id|container_name]
![img](screens/10.png)

Проверить, что образ остановился через docker ps
![img](screens/11.png)

Запустить докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run
![img](screens/12.png)
![img](screens/13.png)

Проверить, что в браузере по адресу localhost:80 доступна стартовая страница nginx
![img](screens/14.png)


Перезапустить докер контейнер через docker restart [container_id|container_name]
![img](screens/15.png)


Проверить любым способом, что контейнер запустился
![img](screens/13.png)


## Part 2. Операции с контейнером


Прочитать конфигурационный файл nginx.conf внутри докер контейнера через команду exec
![img](screens/16.png)


Создать на локальной машине файл nginx.conf

![img](screens/17.png)

Настроить в нем по пути /status отдачу страницы статуса сервера nginx
![img](screens/18.png)

Скопировать созданный файл nginx.conf внутрь докер образа через команду docker cp
![img](screens/19.png)


Перезапустить nginx внутри докер образа через команду exec
![img](screens/20.png)

Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx
![img](screens/21.png)

Экспортировать контейнер в файл container.tar через команду export
![img](screens/22.png)

Остановить контейнер
(переделала все с контенером 7250dfa40cfc)

![img](screens/23.png)

Удалить образ через docker rmi [image_id|repository], не удаляя перед этим контейнеры
![img](screens/24.png)


Удалить остановленный контейнер

![img](screens/25.png)


Импортировать контейнер обратно через команду import
![img](screens/27.png)


Запустить импортированный контейнер
![img](screens/28.png)


Проверить, что по адресу localhost:80/status отдается страничка со статусом сервера nginx
![img](screens/29.png)


## Part 3. Мини веб-сервер

Написать мини сервер на C и FastCgi, который будет возвращать простейшую страничку с надписью Hello World!

![img](screens/32.png)

скопировала сервер в докер через команду docker cp

перешла в интерактивный режим(внутрь своего контейнера)

![img](screens/copyserver.png)


скачала нужные библиотки:
apt update

apt-get install libfcgi-dev

apt-get install spawn-fcgi

apt-get install gcc

запуск

![img](screens/startserver.png)

Запустить написанный мини сервер через spawn-fcgi на порту 8080

![img](screens/spawn.png)

Написать свой nginx.conf, который будет проксировать все запросы с 81 порта на 127.0.0.1:8080
![img](screens/nginx.png)

cкачала nginx

![img](screens/87.png)

запустила nginx

![img](screens/88.png)
![img](screens/90.png)

скопировала туда файлы server.c и nginx.conf

![img](screens/86.png)


запутила server.c

запустила через spawn-fcgi
![img](screens/85.png)


перезапустила

![img](screens/updatenginx.png)

Проверить, что в браузере по localhost:81 отдается написанная вами страничка
![img](screens/84.png)


## Part 4. Свой докер

При написании докер образа избегайте множественных вызовов команд RUN

Написать свой докер образ, который:

1) собирает исходники мини сервера на FastCgi из Части 3
![img](screens/99.png)

2) запускает его на 8080 порту
![img](screens/8080.png)

3) копирует внутрь образа написанный ./nginx/nginx.conf
![img](screens/copy.png)

4) запускает nginx.
nginx можно установить внутрь докера самостоятельно, а можно воспользоваться готовым образом с nginx'ом, как базовым.
![img](screens/66.png)

Собрать написанный докер образ через docker build при этом указав имя и тег
![img](screens/65.png)

Проверить через docker images, что все собралось корректно
![img](screens/64.png)

Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а (см. Часть 2)
![img](screens/63.png)

Проверить, что по localhost:80 доступна страничка написанного мини сервера
![img](screens/62.png)

Дописать в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx
![img](screens/72.png)

Перезапустить докер образ
Если всё сделано верно, то, после сохранения файла и перезапуска контейнера, конфигурационный файл внутри докер образа должен обновиться самостоятельно без лишних действий

Проверить, что теперь по localhost:80/status отдается страничка со статусом nginx
![img](screens/73.png)

## Part 5. Dockle

После написания образа никогда не будет лишним проверить его на безопасность.
== Задание ==

Просканировать образ из предыдущего задания через dockle [image_id|repository]
![img](screens/was.png)



Исправить образ так, чтобы при проверке через dockle не было ошибок и предупреждений

Для исправления ошибки:

"CIS-DI-0005: Enable Content trust for Docker" перед тем как собрать докер, использую эту команду "export DOCKER_CONTENT_TRUST=1"

"CIS-DI-0010: Do not store credential in environment variables/files"-команда dockle -ak NGINX_GPGKEY -ak NGINX_GPGKEY_PATH lll:2.0

готовый dockerfile
![img](screens/06.png)
![img](screens/05.png)

## Part 6. Базовый Docker Compose

Вот вы и закончили вашу разминку. А хотя погодите...
Почему бы не поэкспериментировать с развёртыванием проекта, состоящего сразу из нескольких докер образов?
== Задание ==

Написать файл docker-compose.yml, с помощью которого:

1) Поднять докер контейнер из Части 5 (он должен работать в локальной сети, т.е. не нужно использовать инструкцию EXPOSE и мапить порты на локальную машину)


2) Поднять докер контейнер с nginx, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера

Замапить 8080 порт второго контейнера на 80 порт локальной машины

Остановить все запущенные контейнеры

Собрать и запустить проект с помощью команд docker-compose build и docker-compose up
![img](screens/00.png)


Проверить, что в браузере по localhost:80 отдается написанная вами страничка, как и ранее


![img](screens/01.png)
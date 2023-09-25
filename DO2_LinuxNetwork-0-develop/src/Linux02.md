## Part 1. Инструмент ipcalc
### 1.1. Сети и маски
Определить и записать в отчёт:

1)адрес сети 192.167.38.54/13
![img](screens/1.png)

2)перевод маски 255.255.255.0 в префиксную и двоичную запись, /15 в обычную и двоичную, 11111111.11111111.11111111.11110000 в обычную и префиксную

255:
![img](screens/2.png)

15:
![img](screens/3.png)

11111111.11111111.11111111.11110000:
![img](screens/4.png)


3)минимальный и максимальный хост в сети 122.167.38.4 при масках: 

/8:
![img](screens/5.png)
11111111.11111111.00000000.00000000:
![img](screens/6.png)
255.255.254.0:
![img](screens/7.png)
/4:
![img](screens/8.png)


### 1.2. localhost

Определить и записать в отчёт, можно ли обратиться к приложению, работающему на localhost, со следующими IP: 194.34.23.100, 127.0.0.2, 127.1.0.1, 128.0.0.1

можно: 

127.0.0.2,

127.1.0.1

нельзя:

194.34.23.100,

128.0.0.1

Так как localhost находится в диапазоне 127.0.0.1 — 127.255.255.254

### 1.3. Диапазоны и сегменты сетей

1)какие из перечисленных IP можно использовать в качестве публичного, а какие только в качестве частных:

частные входят в следующие диапазоны:

10.0.0.0 — 10.255.255.255

100.64.0.0 — 100.127.255.255 

172.16.0.0 — 172.31.255.255 

192.168.0.0 — 192.168.255.255 

остальные являются публиными.

10.0.0.45 -частный

134.43.0.2-публичный

192.168.4.2-частный

172.20.250.4-частный

172.0.2.1-публичный

192.172.0.1-публичный

172.68.0.2-публичный

172.16.255.255-частный

10.10.10.10-частный

192.169.168.1-публичный


2)какие из перечисленных IP адресов шлюза возможны у сети 10.10.0.0/18: 

должно находиться в диапазоне 10.10.0.1-10.10.63.254

10.0.0.1-не подходит

10.10.0.2-подходит

10.10.10.10-подходит 

10.10.100.1-не подходит

10.10.1.255-подходит

## Part 2. Статическая маршрутизация между двумя машинами

Поднять две виртуальные машины (далее -- ws1 и ws2)

![img](screens/9.png)

С помощью команды ip a посмотреть существующие сетевые интерфейсы
![img](screens/10.png)
![img](screens/11.png)

Описать сетевой интерфейс, соответствующий внутренней сети, на обеих машинах и задать следующие адреса и маски: ws1 - 192.168.100.10, маска /16, ws2 - 172.24.116.8, маска /12

ws1:

изменение netplan
![img](screens/12.png)
сохранение изменений
![img](screens/13.png)
после сохранений
![img](screens/14.png)

ws2:

изменение netplan
![img](screens/15.png)
сохранение изменений
![img](screens/16.png)
после сохранений 
![img](screens/17.png)

### 2.1. Добавление статического маршрута вручную

Добавить статический маршрут от одной машины до другой и обратно при помощи команды вида ip r add
![img](screens/18.png)
![img](screens/21.png)


Пропинговать соединение между машинами
![img](screens/19.png)
![img](screens/20.png)

### 2.2. Добавление статического маршрута с сохранением

Добавить ста угой с помощью файла etc/netplan/00-installer-config.yaml

![img](screens/22.png)
![img](screens/23.png)

Пропинговать соединение между машинами
![img](screens/24.png)
![img](screens/25.png)

## Part 3. Утилита iperf3

### 3.1. Скорость соединения

Перевести и записать в отчёт:

8 Mbps = 1 MB/s(мегабит/c в мегабайт/c)
 
100 MB/s = 819200 Kbps(мегабайт/c в килобит/c)
 
1 Gbps = 1024 Mbps(гигабит/c в мегабит/c)

### 3.2. Утилита iperf3

Измерить скорость соединения между ws1 и ws2

![img](screens/26.png)
![img](screens/27.png)

## Part 4. Сетевой экран

### 4.1. Утилита iptables
Создать файл /etc/firewall.sh, имитирующий фаерволл, на ws1 и ws2:

Нужно добавить в файл подряд следующие правила:

1)на ws1 применить стратегию когда в начале пишется запрещающее правило, а в конце пишется разрешающее правило (это касается пунктов 4 и 5)

2)на ws2 применить стратегию когда в начале пишется разрешающее правило, а в конце пишется запрещающее правило (это касается пунктов 4 и 5)

3)открыть на машинах доступ для порта 22 (ssh) и порта 80 (http)

4)запретить echo reply (машина не должна "пинговаться”, т.е. должна быть блокировка на OUTPUT)

5)разрешить echo reply (машина должна "пинговаться")

![img](screens/28.png)
![img](screens/30.png)

Запустить файлы на обеих машинах командами chmod +x /etc/firewall.sh и /etc/firewall.sh

![img](screens/29.png)
![img](screens/31.png)

Разница в том, что команды выполняются по порядку. Поэтому в ws1 пинг будет запрещен(потому что разрешение стоит после запрещения), а в ws2 будет разрешен, так как разрешение стоит первее.

### 4.2. Утилита nmap

Командой ping найти машину, которая не "пингуется", после чего утилитой nmap показать, что хост машины запущен
Проверка: в выводе nmap должно быть сказано: Host is up

В отчёт поместить скрины с вызовом и выводом использованных команд ping и nmap.
![img](screens/32.png)
![img](screens/33.png)
![img](screens/34.png)

Сохранить дампы образов виртуальных машин
![img](screens/35.png)
![img](screens/36.png)

## Part 5. Статическая маршрутизация сети

Поднять пять виртуальных машин (3 рабочие станции (ws11, ws21, ws22) и 2 роутера (r1, r2))

Настроить конфигурации машин в etc/netplan/00-installer-config.yaml согласно сети на рисунке.
![img](screens/37.png)
![img](screens/38.png)
![img](screens/41.png)
![img](screens/39.png)
![img](screens/40.png)
Перезапустить сервис сети. Если ошибок нет, то командой ip -4 a проверить, что адрес машины задан верно. 

Перезапуск командой: sudo systemctl restart NetworkManager

![img](screens/42.png)
![img](screens/46.png)
![img](screens/43.png)
![img](screens/44.png)
![img](screens/45.png)

Также пропинговать ws22 с ws21. Аналогично пропинговать r1 с ws11.
![img](screens/47.png)
![img](screens/48.png)
![img](screens/49.png)
![img](screens/50.png)

### 5.2. Включение переадресации IP-адресов.

Для включения переадресации IP, выполните команду на роутерах: sysctl -w net.ipv4.ip_forward=1

![img](screens/51.png)
![img](screens/52.png)

Откройте файл /etc/sysctl.conf и добавьте в него следующую строку:
net.ipv4.ip_forward = 1
![img](screens/53.png)
![img](screens/54.png)

### 5.3. Установка маршрута по-умолчанию

Настроить маршрут по-умолчанию (шлюз) для рабочих станций. Для этого добавить default перед IP роутера в файле конфигураций
![img](screens/55.png)
![img](screens/56.png)
![img](screens/57.png)

Вызвать ip r и показать, что добавился маршрут в таблицу маршрутизации
![img](screens/58.png)
![img](screens/59.png)
![img](screens/60.png)


Пропинговать с ws11 роутер r2 и показать на r2, что пинг доходит. Для этого использовать команду:
tcpdump -tn -i eth1
![img](screens/61.png)
![img](screens/62.png)

## 5.4. Добавление статических маршрутов

Добавить в роутеры r1 и r2 статические маршруты в файле конфигураций
![img](screens/64.png)
![img](screens/65.png)


Вызвать ip r и показать таблицы с маршрутами на обоих роутерах. 
![img](screens/63.png)
![img](screens/66.png)

Запустить команды на ws11:
ip r list 10.10.0.0/[маска сети] и ip r list 0.0.0.0/0
![img](screens/67.png)
объяснить, почему для адреса 10.10.0.0/[маска сети] был выбран маршрут, отличный от 0.0.0.0/0, хотя он попадает под маршрут по-умолчанию:

был выбран первый, так как он прописал в нетпане+выбирается тот вариант, где маска длиннее

### 5.5. Построение списка маршрутизаторов

Запустить на r1 команду дампа:
tcpdump -tnv -i eth0
![img](screens/68.png)
При помощи утилиты traceroute построить список маршрутизаторов на пути от ws11 до ws21
![img](screens/72.png)

### 5.6. Использование протокола ICMP при маршрутизации
Запустить на r1 перехват сетевого трафика, проходящего через eth0 с помощью команды:
tcpdump -n -i eth0 icmp

Пропинговать с ws11 несуществующий IP (например, 10.30.0.111) с помощью команды:
ping -c 1 10.30.0.111

![img](screens/69.png)
![img](screens/70.png)

Сохранить дампы образов виртуальных машин

![img](screens/71.png)


## Part 6. Динамическая настройка IP с помощью DHCP

Для r2 настроить в файле /etc/dhcp/dhcpd.conf конфигурацию службы DHCP:

1)указать адрес маршрутизатора по-умолчанию, DNS-сервер и адрес внутренней сети. 
![img](screens/73.png)

2)в файле resolv.conf прописать nameserver 8.8.8.8.
![img](screens/74.png)

Перезагрузить службу DHCP командой systemctl restart isc-dhcp-server. Машину ws21 перезагрузить при помощи reboot и через ip a показать, что она получила адрес. Также пропинговать ws22 с ws21.
![img](screens/77.png)
![img](screens/75.png)

Указать MAC адрес у ws11, для этого в etc/netplan/00-installer-config.yaml надо добавить строки: macaddress: 10:10:10:10:10:BA, dhcp4: true
![img](screens/76.png)

Для r1 настроить аналогично r2, но сделать выдачу адресов с жесткой привязкой к MAC-адресу (ws11). Провести аналогичные тесты
![img](screens/81.png)

Запросить с ws21 обновление ip адреса
![img](screens/80.png)

Сохранить дампы образов виртуальных машин

![img](screens/78.png)

sudo dhclient -r -удалить ip
sudo dhclient -v -добавить ip

## Part 7. NAT

В файле /etc/apache2/ports.conf на ws22 и r1 изменить строку Listen 80 на Listen 0.0.0.0:80, то есть сделать сервер Apache2 общедоступным
![img](screens/82.png)
![img](screens/83.png)

Запустить веб-сервер Apache командой service apache2 start на ws22 и r1
![img](screens/84.png)
![img](screens/85.png)

Добавить в фаервол, созданный по аналогии с фаерволом из Части 4, на r2 следующие правила:

1)удаление правил в таблице filter - iptables -F

2)удаление правил в таблице "NAT" - iptables -F -t nat


3)отбрасывать все маршрутизируемые пакеты - iptables --policy FORWARD DROP
![img](screens/86.png)

Запускать файл также, как в Части 4

Проверить соединение между ws22 и r1 командой ping

При запуске файла с этими правилами, ws22 не должна "пинговаться" с r1

![img](screens/87.png)
![img](screens/88.png)

Добавить в файл ещё одно правило:

4)разрешить маршрутизацию всех пакетов протокола ICMP

![img](screens/89.png)
Запускать файл также, как в Части 4

Проверить соединение между ws22 и r1 командой ping

При запуске файла с этими правилами, ws22 должна "пинговаться" с r1
![img](screens/90.png)
![img](screens/91.png)

Добавить в файл ещё два правила:

5)включить SNAT, а именно маскирование всех локальных ip из локальной сети, находящейся за r2 (по обозначениям из Части 5 - сеть 10.20.0.0)
Совет: стоит подумать о маршрутизации внутренних пакетов, а также внешних пакетов с установленным соединением

6)включить DNAT на 8080 порт машины r2 и добавить к веб-серверу Apache, запущенному на ws22, доступ извне сети
![img](screens/93.png)

Проверить соединение по TCP для SNAT, для этого с ws22 подключиться к серверу Apache на r1 командой:
telnet [адрес] [порт]
![img](screens/92.png)
Проверить соединение по TCP для DNAT, для этого с r1 подключиться к серверу Apache на ws22 командой telnet (обращаться по адресу r2 и порту 8080)
![img](screens/94.png)


Сохранить дампы образов виртуальных машин
![img](screens/95.png)

## Part 8. Дополнительно. Знакомство с SSH Tunnels

Запустить на r2 фаервол с правилами из Части 7:

sudo chmod +x /etc/firewall.sh

sudo /etc/firewall.sh

Запустить веб-сервер Apache на ws22 только на localhost (то есть в файле /etc/apache2/ports.conf изменить строку Listen 80 на Listen localhost:80)
![img](screens/96.png)

Воспользоваться Local TCP forwarding с ws21 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws21

ssh -L local_port:destination:destination_port ssh_server

![img](screens/97.png)
![img](screens/98.png)


Воспользоваться Remote TCP forwarding c ws11 до ws22, чтобы получить доступ к веб-серверу на ws22 с ws11

ssh -R remote_port:destination:destination_port ssh_server

![img](screens/100.png)
![img](screens/99.png)


Для проверки, сработало ли подключение в обоих предыдущих пунктах, перейдите во второй терминал (например, клавишами Alt + F2) и выполните команду:
telnet 127.0.0.1 [локальный порт]

Сохранить дампы образов виртуальных машин

![img](screens/101.png)
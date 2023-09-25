## Part 1. Установка ОС
Узнайте версию Ubuntu, выполнив команду 
cat /etc/issue.
![img](screen/1.png)
## Part 2. Создание пользователя
Вставьте скриншот вызова команды для создания пользователя.
![img](screen/21.png)

добавление в группу adm
![img](screen/22.png)
![img](screen/24.png)

Новый пользователь должен быть в выводе команды 
cat /etc/passwd
![img](screen/23.png)
## Part 3. Настройка сети ОС
Задать название машины вида user-1
![img](screen/31.png)
![img](screen/32.png)
Установить временную зону, соответствующую вашему текущему местоположению.
![img](screen/33.png)
Вывести названия сетевых интерфейсов с помощью консольной команды.
![img](screen/34.png)
Один из самых основных виртуальных интерфейсов - lo. Это локальный интерфейс, который позволяет программам обращаться к этому компьютеру.
Используя консольную команду получить ip адрес устройства, на котором вы работаете, от DHCP сервера.

Установка
![img](screen/35.png)
Используя консольную команду получить ip адрес устройства, на котором вы работаете, от DHCP сервера.
![img](screen/36.png)
DHCP - это клиент-серверный протокол динамической конфигурации хоста (Dynamic Host Configuration Protocol), с помощью которого в ИТ-инфраструктуре сетевые параметры каждого нового устройства прописываются автоматически.

Определить и вывести на экран внешний ip-адрес шлюза (ip) и внутренний IP-адрес шлюза, он же ip-адрес по умолчанию (gw)
![img](screen/olo.png)
![img](screen/38.png)

Задать статичные (заданные вручную, а не полученные от DHCP сервера) настройки ip, gw, dns (использовать публичный DNS серверы, например 1.1.1.1 или 8.8.8.8).
![img](screen/39.png)
![img](screen/391.png)
![img](screen/392.png)
![img](screen/393.png)
после ребута
![img](screen/394.png)
![img](screen/395.png)
## Part 4. Обновление ОС
Обновить системные пакеты до последней на момент выполнения задания версии.
![img](screen/41.png)
![img](screen/42.png)
## Part 5. Использование команды sudo
Разрешить пользователю, созданному в Part 2, выполнять команду sudo.
![img](screen/51.png)

Поменять hostname ОС от имени пользователя, созданного в пункте Part 2 (используя sudo).
![img](screen/52.png)

sudo -это утилита, она позволяет временно поднимать привилегии и выполнять задачи администрирования системы
## Part 6. Установка и настройка службы времени
Настроить службу автоматической синхронизации времени.
![img](screen/61.png)

Вывод следующей команды должен содержать NTPSynchronized=yes: 
timedatectl show
![img](screen/62.png)
## Part 7. Установка и использование текстовых редакторов
Установить текстовые редакторы VIM (+ любые два по желанию NANO, MCEDIT, JOE и т.д.)
![img](screen/71.png)

Используя каждый из трех выбранных редакторов, создайте файл test_X.txt, где X -- название редактора, в котором создан файл. Напишите в нём свой никнейм, закройте файл с сохранением изменений.

vim7
![img](screen/72.png)
![img](screen/73.png)
выход: esc+:wq

nano
![img](screen/74.png)
выход:  control+o+x

mcedit
![img](screen/75.png)
выход: f2+f10

Используя каждый из трех выбранных редакторов, откройте файл на редактирование, отредактируйте файл, заменив никнейм на строку "21 School 21", закройте файл без сохранения изменений.
vim
![img](screen/76.png)
выход:q!

nano
![img](screen/77.png)
выход: control+x

mcedit
![img](screen/78.png)
выход: f10

Используя каждый из трех выбранных редакторов, отредактируйте файл ещё раз (по аналогии с предыдущим пунктом), а затем освойте функции поиска по содержимому файла (слово) и замены слова на любое другое.

vim поиск
![img](screen/79.png)

замена
![img](screen/792.png)
/- поиск

nano поиск
![img](screen/793.png)

замена - control /
![img](screen/794.png)
![img](screen/795.png)
поиск - control w

mcedit

поиск -f7
![img](screen/796.png)
![img](screen/797.png)
замена - f4
![img](screen/798.png)
![img](screen/799.png)
![img](screen/700.png)

## Part 8. Установка и базовая настройка сервиса SSHD
Установить службу SSHd.

обновление репозитория
![img](screen/81.png)
установление ssh 
![img](screen/812.png)
установление OpenSSH
![img](screen/813.png)

Добавить автостарт службы при загрузке системы.
![img](screen/82.png)

статус ssh
![img](screen/8.png)

Перенастроить службу SSHd на порт 2022.
![img](screen/83.png)

ssh перезапуск для сохранения изменений 
![img](screen/84.png)

Используя команду ps, показать наличие процесса sshd. Для этого к команде нужно подобрать ключи.

![img](screen/851.png)
-tan:

t-по протоколу TCP

a-Отображение всех подключений и ожидающих портов.

n- Отображение адресов и номеров портов в числовом формате.

Cтолбцы:

Recv-Q -количество запросов в очередях на приём  на данном узле/компьютере

Send-Q -количество запросов в очередях на отправку на данном узле/компьютере

Local Address - адрес и номер локального конца сокета

Foreign Address - адрес и номер порта удаленного порта сокета

State - состояние сокета

Если в качестве адреса отображается 0.0.0.0 , то это означает - "любой адрес", т. е в соединении могут использоваться все IP-адреса существующие на данном компьютере.

![img](screen/852.png)
ps -aux | grep sshd output:

ps-выводит список текущих процессов на вашем сервере в виде таблицы

a-выбрать все процессы, кроме фоновых;

u-выбрать процессы пользователя.

x-заставляет ps перечислить все процессы, принадлежащие вам


## Part 9. Установка и использование утилит top, htop
Установить и запустить утилиты top и htop.

top
![img](screen/9.png)

uptime

![img](screen/uptime.png)

количество авторизованных пользователей

![img](screen/countusers.png)

общую загрузку системы
![img](screen/a.png)
общее количество процессов
![img](screen/b.png)
загрузку cpu
![img](screen/cpu.png)
загрузку памяти
![img](screen/memory.png)
pid процесса занимающего больше всего памяти
![img](screen/pidmemory.png)
pid процесса, занимающего больше всего процессорного времени
![img](screen/ggh.png)

htop
отсортированному по PID
![img](screen/htoppid.png)
PERCENT_CPU
![img](screen/cpuproc.png)
PERCENT_MEM
![img](screen/mem.png)
TIME
![img](screen/time.png)
отфильтрованному для процесса sshd
![img](screen/filtersshd.png)
с процессом syslog, найденным, используя поиск
![img](screen/syslog.png)
с добавленным выводом hostname, clock и uptime
![img](screen/hostnameclockuptime.png)

## Part 10. Использование утилиты fdisk

Запустить команду fdisk -l.
![img](screen/101.png)
имя ![img](screen/name.png)
размер 8.25Gb

количество секторов 8854175744
![img](screen/102.png)

## Part 11. Использование утилиты df
df

Для корневого раздела (/):
![img](screen/df.png)

размер раздела-8408452

размер занятого пространства - 2753880

размер свободного пространства-5205856

процент использования-35


Единица измерения в выводе-килобайты

df -Th
для корневого раздела (/):
![img](screen/th.png)
размер раздела-8.1Gb

размер занятого пространства-2.7Gb

размер свободного пространства-5.0Gb

процент использования-35

Tип файловой системы для раздела-ext4

## Part 12. Использование утилиты du
Вывести размер папок /home, /var, /var/log (в байтах)
![img](screen/121.png)
![img](screen/sh1.png)
Вывести размер всего содержимого в /var/log (не общее, а каждого вложенного элемента, используя *)
![img](screen/122.png)
![img](screen/sh2.png)

## Part 13. Установка и использование утилиты ncdu

Установить утилиту ncdu.
![img](screen/installncdu.png)
Вывести размер папок /home, /var, /var/log.
![img](screen/home.png)
![img](screen/var.png)
![img](screen/varlog.png)

## Part 14. Работа с системными журналами

dmesg
![img](screen/dmesg.png)
syslog
![img](screen/14syslog.png)
auth
![img](screen/auth.png)
время последней успешной авторизации-Feb 12 18:09:48

имя пользователя-user-1

метод входа в систему-sudo

Перезапустить службу SSHd.
![img](screen/141.png)
![img](screen/142.png)

## Part 15. Использование планировщика заданий CRON
uptime
![img](screen/cronuptime.png)
Найти в системных журналах строчки (минимум две в заданном временном диапазоне) о выполнении.
![img](screen/res.png)
список текущих задач
![img](screen/tasks.png)
Удалите все задания из планировщика заданий.
![img](screen/154.png)
![img](screen/1555.png)
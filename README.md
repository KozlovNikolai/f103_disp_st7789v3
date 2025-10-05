устанавливаем git:
https://git-scm.com/downloads/win

Делаем в домашней папке паку - `c` и клонируем туда проект:
```
mkdir c
cd c
git clone https://github.com/KozlovNikolai/f103_disp_st7789v3.git
```
Устанавливаем vscode:
https://code.visualstudio.com/download

Устанавливаем расширения - все от Microsoft:

* C/C++ Extension Pack
* CMake Tools
* Makefile Tools
* ms-vscode-remote.remote-wsl

закрыть vscode и командную строку если открыты.

открыть командную строку (powershell) (`wsl --install Ubuntu` должен быть уже установлен), там:
```
wsl
code --version  (первый раз - установится сервер vs code)
code --version (в консоль должна быть выведена версия установленного vscode)
sudo apt install make stlink-tools
```
там же в wsl устанавливаем тулчейн:

## Вариант1: 
Скачиваем архив тулчейна (если ссылка недоступна - смотри вариант2):
```
// в wsl
cd /tmp
wget https://developer.arm.com/-/media/Files/downloads/gnu/14.3.rel1/binrel/arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz
```

ИЛИ 
## Вариант2: 
скачиваем его в браузере с яндекс диска например в папку Downloads:
```
https://disk.yandex.ru/d/6KjoYF-d-GQwGg
// потом в wsl
cd /mnt/c/Users/User/Downloads/
```

## Создаём папку для установки
```
в wsl
sudo mkdir -p /usr/local/gcc-arm-none-eabi-14.3
```

## Распаковываем архив в эту папку
```
в wsl
sudo tar -xvf arm-gnu-toolchain-14.3.rel1-x86_64-arm-none-eabi.tar.xz -C /usr/local/gcc-arm-none-eabi-14.3 --strip-components=1
```

## Добавляем тулчейн в PATH
echo 'export PATH=/usr/local/gcc-arm-none-eabi-14.3/bin:$PATH' >> ~/.bashrc

## Обновляем окружение
source ~/.bashrc

## Проверяем
arm-none-eabi-gcc --version


(переходим в папку с проектом)
```
cd /mnt/c/Users/User/c/f103_disp_st7789v3/  
code .     (запускаем vscode - он запускается из под wsl)
```
В терминале VSCode:
```
make clean
make
make flashwin   // проверить, где установлен st-flash.exe и поправить путь в makefile
```


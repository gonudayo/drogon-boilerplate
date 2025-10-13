[Ubuntu]

1. 시스템 세팅

```bash
apt-get update
sudo apt install git gcc g++ cmake libjsoncpp-dev uuid-dev zlib1g-dev openssl libssl-dev
```

2. drogon 설치

```bash
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
make && sudo make install
```

3. 프로젝트 설치

```bash
git clone https://github.com/gonudayo/drogon-boilerplate.git
cd drogon-boilerplate/build
cmake ..
make
```

4. 실행

```bash
./drogon-boilerplate
```

[Ubuntu]

1. System Preparation

```bash
apt-get update
sudo apt install git gcc g++ cmake libjsoncpp-dev uuid-dev zlib1g-dev openssl libssl-dev
```

2. Drogon Installation

```bash
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
make && sudo make install
```

3. Build

```bash
git clone https://github.com/gonudayo/drogon-boilerplate.git
cd drogon-boilerplate
mkdir build
cd build
cmake ..
make
```

4. Execute

```bash
./drogon-boilerplate
```

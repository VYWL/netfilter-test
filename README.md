## Netfilter-test

### 구현 정도

-   [x] iptables 옵션을 통한 패킷 흐름 이해
-   [x] IP - TCP - HTTP 로 이루어진 패킷 중, Payload만 넘기는 함수 구현
-   [x] Payload에서, Host가 입력된 차단 대상 사이트의 도메인인지 비교
-   [x] 문자열 비교를 위해, KMP 알고리즘 구현
-   [x] 동작 테스트

### 사용 방법

```sh
$ git clone https://github.com/VYWL/netfilter-test
$ cd netfilter-test
$ make
$ sudo ./netfilter-test <domain>
```
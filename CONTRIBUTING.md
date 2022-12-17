## Contributing to AsyncHTTPSRequest_ESP32_Ethernet

### Reporting Bugs

Please report bugs in [AsyncHTTPSRequest_ESP32_Ethernet](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/issues/new) if you find them.

However, before reporting a bug please check through the following:

* [Existing Open Issues](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/issues) - someone might have already encountered this.

If you don't find anything, please [open a new issue](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/issues/new).

### How to submit a bug report

Please ensure to specify the following:

* Arduino IDE version (e.g. 1.8.19) or Platform.io version
* Board Type (e.g. ESP32S3_DEV, ESP32S2_DEV, ESP32C3_DEV)
* Board Core Version (e.g. ESP32 core v2.0.5)
* Contextual information (e.g. what you were trying to achieve)
* Simplest possible steps to reproduce
* Anything that might be relevant in your opinion, such as:
  * Operating system (Windows, Ubuntu, etc.) and the output of `uname -a`
  * Network configuration


Please be educated, civilized and constructive. Disrespective posts against [GitHub Code of Conduct](https://docs.github.com/en/site-policy/github-terms/github-event-code-of-conduct) will be ignored and deleted.


### Example

```
Arduino IDE version: 1.8.19
ESP32S3_DEV board
ESP32 core v2.0.5
OS: Ubuntu 20.04 LTS
Linux xy-Inspiron-3593 5.15.0-56-generic #62~20.04.1-Ubuntu SMP Tue Nov 22 21:24:20 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux

Context:
I encountered a crash while using this library
Steps to reproduce:
1. ...
2. ...
3. ...
4. ...
```

### Additional context

Add any other context about the problem here.

---

### Sending Feature Requests

Feel free to post feature requests. It's helpful if you can explain exactly why the feature would be useful.

There are usually some outstanding feature requests in the [existing issues list](https://github.com/khoih-prog/AsyncHTTPSRequest_ESP32_Ethernet/issues?q=is%3Aopen+is%3Aissue+label%3Aenhancement), feel free to add comments to them.

---

### Sending Pull Requests

Pull Requests with changes and fixes are also welcome!

Please use the `astyle` to reformat the updated library code as follows (demo for Ubuntu Linux)

1. Change directory to the library GitHub

```
xy@xy-Inspiron-3593:~$ cd Arduino/xy/AsyncHTTPSRequest_ESP32_Ethernet_GitHub/
xy@xy-Inspiron-3593:~/Arduino/xy/AsyncHTTPSRequest_ESP32_Ethernet_GitHub$
```

2. Issue astyle command

```
xy@xy-Inspiron-3593:~/Arduino/xy/AsyncHTTPSRequest_ESP32_Ethernet_GitHub$ bash utils/restyle.sh
```




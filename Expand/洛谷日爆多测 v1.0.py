#  请先 pip install requests

from requests import *
from time import *

times = 10 # 请求次数
errortimes = 0

hd = { "user-agent" : "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36" }
cnt = {
    100 : 0, 101 : 0, 102 : 0,
    200 : 0, 201 : 0, 202 : 0, 203 : 0, 204 : 0, 205 : 0, 206 : 0, 207 : 0,
    300 : 0, 301 : 0, 302 : 0, 303 : 0, 304 : 0, 305 : 0, 306 : 0, 307 : 0, 
    400 : 0, 401 : 0, 402 : 0, 403 : 0, 404 : 0, 405 : 0, 406 : 0, 407 : 0, 408 : 0, 409 : 0, 410 : 0, 411 : 0, 412 : 0, 413 : 0, 414 : 0, 415 : 0, 416 : 0, 417 : 0, 418 : 0, 421 : 0, 422 : 0, 423 : 0, 424 : 0, 425 : 0, 426 : 0, 449 : 0, 451 : 0,
    500 : 0, 502 : 0, 503 : 0, 504 : 0, 505 : 0, 506 : 0, 507 : 0, 509 : 0, 510 : 0, 600 : 0
}
table = {
    100 : "Continue",
    101 : "Switching Protocols",
    102 : "Processing",
    200	: "OK", 
    201	: "Created",
    202	: "Accepted",
    203	: "Non-Authoritative Information",
    204	: "No Content",
    205 : "Reset Content",
    206	: "Partial Content",
    300	: "Multiple Choices",
    301	: "Moved Permanently",
    302	: "Found",
    303 : "See Other",
    304	: "Not Modified",
    305	: "Use Proxy",
    306	: "Unused",
    307	: "Temporary Redirect",
    400	: "Bad Request",
    401	: "Unauthorized",
    402	: "Payment Required",
    403	: "Forbidden",
    404	: "Not Found",
    408	: "Request Time-out",
    416	: "Requested range not satisfiable",
    500	: "Internal Server Error",
    502	: "Bad Gateway",
    503	: "Service Unavailable"
}

for i in range(times):
    try:
        now = get("https://www.luogu.com.cn", headers = hd)
        cnt[now.status_code] += 1
        print(now.status_code)
    except:
        print("NetWork Error\n")
        errortimes += 1
    
    # print(cnt)
    sleep(0.2)

print("访问失败无返回次数", errortimes)

for k, v in cnt.items():
    if (v != 0):
        print(k, table[k], ":", v, "次")
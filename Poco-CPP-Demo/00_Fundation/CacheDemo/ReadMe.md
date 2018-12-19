## Poco C++ ﻿公共组件：Cache机制

参考文档：http://blog.csdn.net/arau_sh/article/details/8698434

### 1. Cache概述

Poco C++ 的 Cache 机制存在以下几种具体的实现：
- LRUCache：最近使用的Cache。其在内部维护一个指定大小N的Cache，当第N+1个元素插入Cache的时候，最先放入Cache的元素将失效；
- ExpireCache：时间过期Cache。在内部统一管理一个失效时间T，当元素插入Cache后，超过时间T没有被更新，则元素失效
- AccessExpireCache：
- UniqueExpireCache：
- UniqueAccessExpireCache：
- ExpireLRUCache：
- AccessExpireLRUCache：
- UniqueExpireLRUCache：
- UniqueAccessExpireLRUCache：

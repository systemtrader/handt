[![Build Status](https://travis-ci.org/deanturpin/handt.svg?branch=master)](https://travis-ci.org/deanturpin/handt)

**History is no indicator of future performance. Don't invest what you can't
afford to lose.**

*Have A Nice Day Trader* is an algorithmic trading platform that uses patterns
in historic prices to influence future trades. 80 days of prices are requested
for hundreds of currency pairs, then a library of strategies is backtested and
a summary is generated.

Run in Docker:
```bash
docker run deanturpin/handt
```

Prices are fetched using the [CryptoCompare
API](https://min-api.cryptocompare.com/). See the entry point in
[main.cpp](https://github.com/deanturpin/handt/blob/master/main.cpp) and [all
exchanges](https://min-api.cryptocompare.com/data/all/exchanges). The
strategies are defined in the
[low_frequency_trader.cpp](low_frequency_trader.cpp), the permutations and
thresholds are generated in [strategy.cpp](strategy.cpp).

Exchanges in use: Coinbase Binance
```
dff2fa3 Use native tuning
```
Generated Mon May  6 17:28:49 2019

* 2 threads
* 556 currency pairs
* 2,250 strategies
* 2,283,861,193 backtests

# Current prospects

Strategy|Pair|Exchange|Perf|Spot|Jitter %
---|---|---|---|---
Darting-Griffon-8|[APPC-BNB](https://www.cryptocompare.com/coins/APPC)|Binance|9/0|0.00315|1.28542
Darting-Griffon-9|[APPC-BNB](https://www.cryptocompare.com/coins/APPC)|Binance|9/0|0.00315|1.28542
Supine-Xoloitzcuintli-6|[ENJ-ETH](https://www.cryptocompare.com/coins/ENJ)|Binance|10/1|0.0008235|1.25384
Darting-Pomeranian-6|[LOOM-USDC](https://www.cryptocompare.com/coins/LOOM)|Coinbase|10/1|0.06436|0.763706
Indifferent-Griffon-15|[EVX-BTC](https://www.cryptocompare.com/coins/EVX)|Binance|9/0|0.0001248|1.60194
Indifferent-Griffon-16|[EVX-BTC](https://www.cryptocompare.com/coins/EVX)|Binance|9/0|0.0001248|1.60194
Leaping-Pomeranian-5|[LOOM-USDC](https://www.cryptocompare.com/coins/LOOM)|Coinbase|8/0|0.06436|0.763706
Indifferent-Griffon-17|[EVX-BTC](https://www.cryptocompare.com/coins/EVX)|Binance|8/0|0.0001248|1.60194
Supine-Axolotl-5|[APPC-BTC](https://www.cryptocompare.com/coins/APPC)|Binance|8/0|1.205e-05|1.03534
Indifferent-Pomeranian-9|[DLT-ETH](https://www.cryptocompare.com/coins/DLT)|Binance|8/1|0.000587|0.968959
Slouching-Axolotl-7|[DENT-BTC](https://www.cryptocompare.com/coins/DENT)|Binance|8/1|1.3e-07|2.13179

# 80-day backtest

Strategy|Pair|Exchange|Perf|Spot|Jitter %
---|---|---|---|---
Indifferent-Cricket-10|[ONT-USDT](https://www.cryptocompare.com/coins/ONT)|Binance|13/0|1.07|0.914467
Darting-Pomeranian-6|[ONT-USDT](https://www.cryptocompare.com/coins/ONT)|Binance|12/0|1.07|0.914467
Darting-Axolotl-13|[RVN-BNB](https://www.cryptocompare.com/coins/RVN)|Binance|13/1|0.002196|1.4763
Darting-Cricket-10|[ONT-USDT](https://www.cryptocompare.com/coins/ONT)|Binance|12/1|1.07|0.914467
Darting-Griffon-8|[APPC-BNB](https://www.cryptocompare.com/coins/APPC)|Binance|9/0|0.00315|1.28542
Darting-Griffon-9|[APPC-BNB](https://www.cryptocompare.com/coins/APPC)|Binance|9/0|0.00315|1.28542
Supine-Shiba Inu-12|[ENJ-ETH](https://www.cryptocompare.com/coins/ENJ)|Binance|10/1|0.0008235|1.25384
Supine-Xoloitzcuintli-6|[ENJ-ETH](https://www.cryptocompare.com/coins/ENJ)|Binance|10/1|0.0008235|1.25384
Indifferent-Pekingese-12|[RVN-BNB](https://www.cryptocompare.com/coins/RVN)|Binance|9/0|0.002196|1.4763
Darting-Griffon-8|[RVN-BTC](https://www.cryptocompare.com/coins/RVN)|Binance|10/1|8.47e-06|1.30951
Slouching-Cricket-7|[RVN-BTC](https://www.cryptocompare.com/coins/RVN)|Binance|10/1|8.47e-06|1.30951
Slouching-Cricket-8|[RVN-BTC](https://www.cryptocompare.com/coins/RVN)|Binance|9/0|8.47e-06|1.30951
Darting-Pomeranian-6|[LOOM-USDC](https://www.cryptocompare.com/coins/LOOM)|Coinbase|10/1|0.06436|0.763706
Indifferent-Griffon-15|[EVX-BTC](https://www.cryptocompare.com/coins/EVX)|Binance|9/0|0.0001248|1.60194
Indifferent-Griffon-16|[EVX-BTC](https://www.cryptocompare.com/coins/EVX)|Binance|9/0|0.0001248|1.60194
Darting-Havanese-12|[ONT-USDT](https://www.cryptocompare.com/coins/ONT)|Binance|9/0|1.07|0.914467
Darting-Pomeranian-7|[ONT-USDT](https://www.cryptocompare.com/coins/ONT)|Binance|9/0|1.07|0.914467
Indifferent-Pomeranian-13|[ENJ-ETH](https://www.cryptocompare.com/coins/ENJ)|Binance|9/1|0.0008235|1.25384
Supine-Norrbottenspets-11|[ENJ-ETH](https://www.cryptocompare.com/coins/ENJ)|Binance|9/1|0.0008235|1.25384
Supine-Cricket-11|[RVN-BNB](https://www.cryptocompare.com/coins/RVN)|Binance|9/1|0.002196|1.4763
Leaping-Pekingese-4|[WTC-ETH](https://www.cryptocompare.com/coins/WTC)|Binance|9/1|0.01168|0.856239

# Overall strategy performance
150 strategies

Slouching-Bandicoot|10/1
Darting-Bichon Frise|0/0
Darting-Lowchen|0/0
Darting-Mink|0/0
Darting-Narwahl|0/0
Darting-Ocelot|0/0
Darting-Papillon|0/0
Darting-Shih Tzu|0/0
Indifferent-Bichon Frise|0/0
Indifferent-Lowchen|0/0
Indifferent-Mink|0/0
Indifferent-Narwahl|0/0
Indifferent-Ocelot|0/0
Indifferent-Papillon|0/0
Indifferent-Shih Tzu|0/0
Leaping-Bichon Frise|0/0
Leaping-Lowchen|0/0
Leaping-Mink|0/0
Leaping-Narwahl|0/0
Leaping-Ocelot|0/0
Leaping-Papillon|0/0
Leaping-Shih Tzu|0/0
Slouching-Bichon Frise|0/0
Slouching-Lowchen|0/0
Slouching-Mink|0/0
Slouching-Narwahl|0/0
Slouching-Ocelot|0/0
Slouching-Papillon|0/0
Slouching-Shih Tzu|0/0
Straddling-Bichon Frise|0/0
Straddling-Lowchen|0/0
Straddling-Mink|0/0
Straddling-Narwahl|0/0
Straddling-Ocelot|0/0
Straddling-Papillon|0/0
Straddling-Shih Tzu|0/0
Supine-Bichon Frise|0/0
Supine-Lowchen|0/0
Supine-Mink|0/0
Supine-Narwahl|0/0
Supine-Ocelot|0/0
Supine-Papillon|0/0
Supine-Shih Tzu|0/0
Darting-Sphynx|1162/1728
Slouching-Affenpinscher|557/830
Slouching-Munchkin|137/209
Darting-Norrbottenspets|1968/3484
Slouching-Basenji|969/2123
Supine-Affenpinscher|1656/3694
Leaping-Bandicoot|2271/5392
Darting-Xoloitzcuintli|1426/3471
Slouching-Jagdterrier|770/1887
Darting-Capybara|502/1430
Supine-Bandicoot|558/1636
Leaping-Affenpinscher|9486/28507
Supine-Munchkin|2100/7200
Straddling-Basenji|936/3218
Leaping-Sphynx|726/2555
Darting-Shiba Inu|10595/40322
Leaping-Munchkin|7403/28406
Leaping-Xoloitzcuintli|696/2682
Supine-Jagdterrier|3161/12488
Leaping-Basenji|7698/30625
Leaping-Griffon|7207/29062
Straddling-Sphynx|895/3681
Supine-Axolotl|7372/30367
Darting-Affenpinscher|16236/67835
Indifferent-Affenpinscher|16299/68125
Leaping-Capybara|714/3056
Supine-Basenji|2391/10296
Leaping-Norrbottenspets|1310/5890
Leaping-Pomeranian|12003/55754
Straddling-Munchkin|1036/4829
Leaping-Shiba Inu|4452/21190
Darting-Griffon|16312/79879
Leaping-Pekingese|8973/44390
Slouching-Axolotl|8972/45792
Indifferent-Basenji|13108/67455
Straddling-Affenpinscher|1149/5932
Darting-Basenji|12944/66884
Supine-Sphynx|12241/63752
Leaping-Jagdterrier|16405/85514
Slouching-Cricket|12650/67857
Straddling-Pomeranian|2071/11198
Supine-Cricket|10882/58847
Darting-Bandicoot|4170/22602
Indifferent-Bandicoot|4170/22602
Darting-Munchkin|12975/70562
Indifferent-Munchkin|12979/70646
Supine-Xoloitzcuintli|11757/64676
Supine-Badger|1985/11294
Leaping-Axolotl|18605/108344
Leaping-Badger|86/503
Straddling-Pekingese|1601/9441
Straddling-Jagdterrier|1475/8782
Indifferent-Sphynx|18566/111896
Slouching-Sphynx|18267/111139
Slouching-Xoloitzcuintli|17753/111314
Indifferent-Xoloitzcuintli|18107/113573
Leaping-Cricket|19916/125962
Slouching-Badger|2913/18465
Indifferent-Badger|2937/18732
Straddling-Axolotl|1612/10535
Darting-Jagdterrier|25766/172168
Indifferent-Jagdterrier|25817/172575
Darting-Pekingese|14656/99025
Straddling-Xoloitzcuintli|748/5075
Straddling-Norrbottenspets|1716/11747
Straddling-Cricket|1704/11711
Straddling-Griffon|2115/14650
Supine-Pomeranian|15994/111112
Straddling-Bandicoot|502/3520
Supine-Pekingese|14337/101305
Darting-Pomeranian|20638/148963
Supine-Capybara|9001/66108
Supine-Norrbottenspets|26999/201270
Straddling-Badger|154/1176
Leaping-Havanese|22594/173218
Straddling-Capybara|622/4862
Darting-Axolotl|30990/245650
Straddling-Shiba Inu|1794/14438
Darting-Badger|48/389
Indifferent-Axolotl|32804/267103
Straddling-Havanese|3085/25676
Supine-Shiba Inu|30419/254821
Indifferent-Pomeranian|32539/277704
Indifferent-Pekingese|27425/235062
Indifferent-Capybara|13647/117034
Slouching-Capybara|13536/116350
Supine-Griffon|31879/275543
Indifferent-Cricket|36723/332480
Darting-Cricket|33894/307056
Indifferent-Norrbottenspets|38707/352316
Slouching-Norrbottenspets|38315/350075
Slouching-Pomeranian|20196/188395
Slouching-Pekingese|18994/179299
Supine-Havanese|35410/353742
Indifferent-Griffon|48924/541625
Indifferent-Shiba Inu|45381/509440
Slouching-Shiba Inu|43579/493848
Slouching-Griffon|44471/505757
Darting-Havanese|37297/438293
Slouching-Havanese|46549/688750
Indifferent-Havanese|62125/932693
Leaping-Lundehund|49515/801780
Straddling-Lundehund|4980/85620
Supine-Lundehund|76560/1429965
Slouching-Lundehund|112545/3530775
Darting-Lundehund|88995/5142615
Indifferent-Lundehund|123105/7966575

# sloccount
```
Have a non-directory at the top, so creating directory top_dir
Adding /home/travis/build/deanturpin/handt/backtest.h to top_dir
Adding /home/travis/build/deanturpin/handt/detailed_report.h to top_dir
Adding /home/travis/build/deanturpin/handt/low_frequency_trader.h to top_dir
Adding /home/travis/build/deanturpin/handt/parallel.h to top_dir
Adding /home/travis/build/deanturpin/handt/report.h to top_dir
Adding /home/travis/build/deanturpin/handt/strategy.h to top_dir
Adding /home/travis/build/deanturpin/handt/strategy_report.h to top_dir
Adding /home/travis/build/deanturpin/handt/trade.h to top_dir
Adding /home/travis/build/deanturpin/handt/backtest.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/detailed_report.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/low_frequency_trader.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/main.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/report.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/strategy.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/strategy_report.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/trade.cpp to top_dir
Adding /home/travis/build/deanturpin/handt/get_all_coins.py to top_dir
Adding /home/travis/build/deanturpin/handt/get_coins.py to top_dir
Adding /home/travis/build/deanturpin/handt/get_prices.py to top_dir
Categorizing files.
Finding a working MD5 command....
Found a working MD5 command.
Computing results.


SLOC	Directory	SLOC-by-Language (Sorted)
627     top_dir         cpp=558,python=69


Totals grouped by language (dominant language first):
cpp:            558 (89.00%)
python:          69 (11.00%)




Total Physical Source Lines of Code (SLOC)                = 627
Development Effort Estimate, Person-Years (Person-Months) = 0.12 (1.47)
 (Basic COCOMO model, Person-Months = 2.4 * (KSLOC**1.05))
Schedule Estimate, Years (Months)                         = 0.24 (2.89)
 (Basic COCOMO model, Months = 2.5 * (person-months**0.38))
Estimated Average Number of Developers (Effort/Schedule)  = 0.51
Total Estimated Cost to Develop                           = $ 16,549
 (average salary = $56,286/year, overhead = 2.40).
SLOCCount, Copyright (C) 2001-2004 David A. Wheeler
SLOCCount is Open Source Software/Free Software, licensed under the GNU GPL.
SLOCCount comes with ABSOLUTELY NO WARRANTY, and you are welcome to
redistribute it under certain conditions as specified by the GNU GPL license;
see the documentation for details.
Please credit this data as "generated using David A. Wheeler's 'SLOCCount'."
```



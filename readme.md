[![Build Status](https://travis-ci.org/deanturpin/handt.svg?branch=master)](https://travis-ci.org/deanturpin/handt)
[![Coverage Status](https://coveralls.io/repos/github/deanturpin/handt/badge.svg)](https://coveralls.io/github/deanturpin/handt)
  
**Have A Nice Day Trader** is an algorithmic trading platform. Prices are
requested for a list of currency symbols, a library of strategies is run over
the prices and a web page summary of strategy performance is generated every
minute. The positions are (notionally) closed if they exceed a sell threshold or
expire after 24 hours.

![](doc/handt.svg)

# Clone and build
```bash
git clone https://github.com/deanturpin/handt
cd handt
make
```

Build "update" to fetch fresh prices.
```bash
make update
```

# Continuous integration
The code is intended to run periodically on a web server. Travis builds are
invoked on commit and Coveralls reports are generated on demand.

To upload coverage:
```bash
export COVERALLS_ID=XXXX
cd test
make coverage
```

# C++
The C++ is built with a C++14 compliant compiler (gcc, clang). The code confirms
to LLVM's coding standard by virtue of periodic runs of ```clang-format```
over the source.

# Web server
```cron``` is used to schedule builds on a Linux web server. The project is
periodically pulled from GitHub, compiled, run and if successful the results are
copied into the web root. Modules are unit tested with each compilation and a
code coverage tool can be run on demand. Compilation errors discovered on the
server are reported immediately by email.

```bash
*/1 * * * * cd ~/handt && nice make CXX=g++ --silent gitpull update && cp -u index.html ~/public_html/
```

The web page is created from an [HTML template](include/index.html). The
template contains keywords which are substituted for current data.

```html
<h1>Have A Nice Day Trader <small>DATE</small></h1>
```

# Exchanges
Intuitively it feels that requesting prices more often will make the softwrae
more responsive to market changes. But Coinbase and CryptoCompare actually don't
publish updates more often than once per minute. CryptoCompare also has API
request rate limiting but in practice only 60 coins can be processed per minute
to ensure we don't clash with the next cron job.

# Heading towards a strategy definition language
The current strategy definition makes use of a library of techniques.
```cpp
result stepping_up(series s, param p) { 
  const auto name = NAME("stepping_up", p);
  const bool exec = RECENT_AVERAGE(s) / DISTANT_AVERAGE(s) > THRESHOLD(p);
  return result(name, exec);
}
```

Which doesn't seem too far removed from a strategy definition language.
```
name = "stepping_up"
exec = RECENT_AVERAGE / DISTANT_AVERAGE > THRESHOLD
```

all: tmp tmp/haveanicedaytrader

CXX = g++-8
cflags = --std=c++17 --all-warnings --extra-warnings --pedantic-errors \
	 -Werror -Wshadow -Wfloat-equal -Weffc++ -Wdelete-non-virtual-dtor \
	 -lstdc++fs -O3

tmp/%.o: %.cpp
	$(CXX) -o $@ $< $(cflags) -c

tmp:
	 mkdir $@
	./get_prices.py

# Generate documentation
readme = readme.md
tmp/haveanicedaytrader: tmp/prices.o tmp/handt.o tmp/report.o tmp/main.o
	$(CXX) -o $@ $^ -lstdc++fs
	./$@ > tmp/strategy.txt
	cat template.md > $(readme)
	echo Generated $(shell TZ=GMT-1 date) >> $(readme)
	`head -200 tmp/strategy.txt >> $(readme)`

# All intermediate files are stored in tmp, so just remove it
clean:
	rm -rf tmp

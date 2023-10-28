CC = clang
CXX = clang++
DB = lldb

# ifdef
getmac: main.o getmac.o
	$(CXX) main.o getmac.o -o getmac

debug: getmac
	$(DB) ./getmac

main.o: main.cpp 
	$(CXX) -c main.cpp 

getmac.o: getmac.cpp getmac_macos.cpp getmac_win32.cpp getmac_linux.cpp
	$(CXX) -c getmac.cpp 

clean:
	rm -rf *.o
	rm -rf getmac
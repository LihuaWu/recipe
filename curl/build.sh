JUMBO="/home/work/.jumbo"
JUMBO_LIB=-L$JUMBO"/lib"
JUMBO_INC=-I$JUMBO"/include"

JUMBO_OPT="/home/work/.jumbo/opt"
JUMBO_OPT_INC=-I$JUMBO_OPT"/include"
JUMBO_OPT_LIB=-L$JUMBO_OPT"/lib"

LIBCURL_LIBS="-lidn -lssh2 -lssl -lcrypto -lldap -lz -lrt -lcurl"

g++ $JUMBO_INC $JUMBO_OPT_INC $JUMBO_LIB $JUMBO_OPT_LIB $LIBCURL_LIBS getinmemory.cc  -o getinmemory
g++ -I. $JUMBO_INC $JUMBO_OPT_INC $JUMBO_LIB $JUMBO_OPT_LIB $LIBCURL_LIBS Curl.cc curlTest.cc -o curlTest

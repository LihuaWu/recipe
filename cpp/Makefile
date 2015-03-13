#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=~/.jumbo/opt/gcc49/bin/g++
CXXFLAGS=-g \
  -std=c++11 \
  -pipe \
  -W \
  -Wall \
  -fPIC
CFLAGS=-g \
  -std=c++11 \
  -pipe \
  -W \
  -Wall \
  -fPIC
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION=\"1.9.8.7\"
INCPATH=
DEP_INCPATH=-I../../third-64/gtest \
  -I../../third-64/gtest/include \
  -I../../third-64/gtest/output \
  -I../../third-64/gtest/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=37fde5c06019823f805f34b9044cd275  COMAKE


.PHONY:all
all:comake2_makefile_check tail graph 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf tail
	rm -rf ./output/bin/tail
	rm -rf graph
	rm -rf ./output/bin/graph
	rm -rf tail_tail.o
	rm -rf graph_graph.o
	rm -rf test/graph_testGraph.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

tail:tail_tail.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtail[0m']"
	$(CXX) tail_tail.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o tail
	mkdir -p ./output/bin
	cp -f --link tail ./output/bin

graph:graph_graph.o \
  test/graph_testGraph.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgraph[0m']"
	$(CXX) graph_graph.o \
  test/graph_testGraph.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o graph
	mkdir -p ./output/bin
	cp -f --link graph ./output/bin

tail_tail.o:tail.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtail_tail.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tail_tail.o tail.cc

graph_graph.o:graph.cc \
  graph.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgraph_graph.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o graph_graph.o graph.cc

test/graph_testGraph.o:test/testGraph.cc \
  graph.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest/graph_testGraph.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test/graph_testGraph.o test/testGraph.cc

endif #ifeq ($(shell uname -m),x86_64)



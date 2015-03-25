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
COMAKE_MD5=b291467e7b279778bac1718db3ead974  COMAKE


.PHONY:all
all:comake2_makefile_check tail graph top dijkstra tree1 ac 
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
	rm -rf top
	rm -rf ./output/bin/top
	rm -rf dijkstra
	rm -rf ./output/bin/dijkstra
	rm -rf tree1
	rm -rf ./output/bin/tree1
	rm -rf ac
	rm -rf ./output/bin/ac
	rm -rf tail_tail.o
	rm -rf graph_graph.o
	rm -rf graph_bfs.o
	rm -rf graph_dfs.o
	rm -rf test/graph_testGraph.o
	rm -rf top_topsort.o
	rm -rf test/top_testTopSort.o
	rm -rf dijkstra_dijkstra.o
	rm -rf test/dijkstra_testDijkstra.o
	rm -rf tree1_tree.o
	rm -rf ac_ac.o

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
  graph_bfs.o \
  graph_dfs.o \
  test/graph_testGraph.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgraph[0m']"
	$(CXX) graph_graph.o \
  graph_bfs.o \
  graph_dfs.o \
  test/graph_testGraph.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o graph
	mkdir -p ./output/bin
	cp -f --link graph ./output/bin

top:top_topsort.o \
  test/top_testTopSort.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtop[0m']"
	$(CXX) top_topsort.o \
  test/top_testTopSort.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o top
	mkdir -p ./output/bin
	cp -f --link top ./output/bin

dijkstra:dijkstra_dijkstra.o \
  test/dijkstra_testDijkstra.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdijkstra[0m']"
	$(CXX) dijkstra_dijkstra.o \
  test/dijkstra_testDijkstra.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o dijkstra
	mkdir -p ./output/bin
	cp -f --link dijkstra ./output/bin

tree1:tree1_tree.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtree1[0m']"
	$(CXX) tree1_tree.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o tree1
	mkdir -p ./output/bin
	cp -f --link tree1 ./output/bin

ac:ac_ac.o
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mac[0m']"
	$(CXX) ac_ac.o -Xlinker "-("  ../../third-64/gtest/lib/libgtest.a \
  ../../third-64/gtest/lib/libgtest_main.a -lpthread -Xlinker "-)" -o ac
	mkdir -p ./output/bin
	cp -f --link ac ./output/bin

tail_tail.o:tail.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtail_tail.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tail_tail.o tail.cc

graph_graph.o:graph.cc \
  graph.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgraph_graph.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o graph_graph.o graph.cc

graph_bfs.o:bfs.cc \
  graph.h \
  bfs.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgraph_bfs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o graph_bfs.o bfs.cc

graph_dfs.o:dfs.cc \
  graph.h \
  dfs.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mgraph_dfs.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o graph_dfs.o dfs.cc

test/graph_testGraph.o:test/testGraph.cc \
  graph.h \
  bfs.h \
  dfs.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest/graph_testGraph.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test/graph_testGraph.o test/testGraph.cc

top_topsort.o:topsort.cc \
  wgraph.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtop_topsort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o top_topsort.o topsort.cc

test/top_testTopSort.o:test/testTopSort.cc \
  wgraph.h \
  topsort.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest/top_testTopSort.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test/top_testTopSort.o test/testTopSort.cc

dijkstra_dijkstra.o:dijkstra.cc \
  dijkstra.h \
  wgraph.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdijkstra_dijkstra.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o dijkstra_dijkstra.o dijkstra.cc

test/dijkstra_testDijkstra.o:test/testDijkstra.cc \
  wgraph.h \
  dijkstra.h
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest/dijkstra_testDijkstra.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test/dijkstra_testDijkstra.o test/testDijkstra.cc

tree1_tree.o:tree.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtree1_tree.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o tree1_tree.o tree.cc

ac_ac.o:ac.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mac_ac.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ac_ac.o ac.cc

endif #ifeq ($(shell uname -m),x86_64)



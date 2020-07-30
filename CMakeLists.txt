cmake_minimum_required(VERSION 3.13)
project(proj2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(proj2 server_side.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h StringReverser.cpp StringReverser.h Searcher.h DFS.h BFS.h boot.h main.cpp Searchable.h SearcherSolver.h State.h Matrix.cpp Matrix.h MyClientHandler.cpp MyClientHandler.h FileCacheManager.h MyParallelServer.cpp MyParallelServer.h Result.h Point.h Result.cpp PriorityQueueA.h Astar.h BestFirstSearch.h Compare.h)
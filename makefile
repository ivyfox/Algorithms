UnionFindSet.o: Data_Structures/UnionFindSet.h Data_Structures/UnionFindSet.cpp
	g++ -c -O2 Data_Structures/UnionFindSet.cpp -o UnionFindSet.o

TrieTree.o: Data_Structures/TrieTree.h Data_Structures/TrieTree.cpp
	g++ -c -O2 Data_Structures/TrieTree.cpp -o TrieTree.o

Heap.o: Data_Structures/Heap.h Data_Structures/Heap.cpp
	g++ -c -O2 Data_Structures/Heap.cpp -o Heap.o

clean:
	rm *.o

main: TrieTree.o main.cpp
	g++ -O2 main.cpp TrieTree.o


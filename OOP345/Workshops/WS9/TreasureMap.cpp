#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <future>
#include "TreasureMap.h"

namespace seneca {

    size_t digForTreasure(const std::string& str, char mark) {
        size_t cnt = 0;
        for (auto& x : str) {
            if (x == mark) cnt++;
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename) {
        std::fstream fin(filename);
        if (fin) {
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while (fin) {
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else throw std::string(filename) + " cannot be opened";
    }

    TreasureMap::~TreasureMap() {
        delete[] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const {
        if (map) {
            for (size_t i = 0; i < rows; ++i) {
                os << map[i] << std::endl;
            }
        }
        else os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename) {
        // Binary write
        if (map) {
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.

            std::ofstream f(filename, std::ios::out | std::ios::binary | std::ios::trunc);
            if (f.is_open()) {
                if (f) {
                    f.write(reinterpret_cast<char*>(&rows), sizeof(rows));
                    f.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));
                    
                    for (size_t i = 0; i < rows; i++){
                        f.write(&map[i][0], map[i].size());
                    };
                    f.close();
                };
            }
            else throw "Cannot open the file.";

            // END TODO
        }
        else throw std::string("Treasure map is empty!");
    }

    void TreasureMap::recall(const char* filename) {
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.

        std::ifstream f(filename, std::ios::in | std::ios::binary);
        if (f.is_open()) {
            f.read(reinterpret_cast<char*>(&rows), sizeof(size_t));
            f.read(reinterpret_cast<char*>(&colSize), sizeof(size_t));
            map = new std::string[rows];
            for (size_t i = 0; i < rows; i++) {
                map[i].resize(colSize);
                f.read(&map[i][0], colSize);
            };
            f.close();
        }
        else throw "File cannot be opened.";

        // END TODO
    }

    void TreasureMap::clear() {
        delete[] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
           // for (size_t i = 0; i < rows; ++i){
          //     count += digForTreasure(map[i], mark);
         // }

        size_t count = 0;
        size_t numThreads = 4; 
        std::vector<std::thread> threads(numThreads);
        std::vector<size_t> partialCounts(numThreads, 0);

        size_t partitionSize = rows / numThreads;

        auto threadFunction = [&](size_t threadId){
                size_t start = threadId * partitionSize;
                size_t end = (threadId == numThreads - 1) ? rows : (threadId + 1) * partitionSize;
                for (size_t i = start; i < end; ++i){
                    partialCounts[threadId] += digForTreasure(map[i], mark);
                }
            };

        for (size_t i = 0; i < numThreads; ++i){
            threads[i] = std::thread(threadFunction, i);
        }

        for (size_t i = 0; i < numThreads; ++i){
            threads[i].join();
            count += partialCounts[i];
        }

        // END TODO

        return count;
    }
}
//
// Created by dayan on 4/23/2026.
//

#ifndef BANKING_SYSTEM_HISTORY_H
#define BANKING_SYSTEM_HISTORY_H

#include <iostream>
#include <vector>

template <typename T>
class History {
public:
    void addRecord(T record) {
        records.push_back(record);
    }

    void showRecords() const {
        if (records.empty()) {
            throw std::runtime_error("No record to show.");
        }
            for (T record : records) {
                std::cout << record << std::endl;
            }
    }
    int getCount() const {
        return records.size();
    }
private:
    std::vector<T> records;
};

#endif //BANKING_SYSTEM_HISTORY_H